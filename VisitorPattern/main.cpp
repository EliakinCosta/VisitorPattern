#include <QCoreApplication>
#include <QList>
#include <QDir>
#include <QApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QIODevice>
#include <QDebug>
#include <QScopedPointer>
#include <QDirIterator>

#include "visitor.h"
#include "ielement.h"
#include "aluno.h"
#include "professor.h"
#include "idademediaalunovisitor.h"
#include "salariomedioprofessorvisitor.h"

QString findFileWithExtension(QString extension)
{
    QDir projectDir = QDir(qApp->applicationDirPath());
    projectDir.cdUp();

    QDirIterator dirIt(projectDir.absolutePath(), QDirIterator::Subdirectories);
    while (dirIt.hasNext()) {
        dirIt.next();
        if (QFileInfo(dirIt.filePath()).isFile())
          if (QFileInfo(dirIt.filePath()).suffix() == extension)
            return dirIt.filePath();
    }
    return "";
}


QVariantMap readFromJson()
{
    QFile file;
    QString filePath = findFileWithExtension("json");
    QString json;

    file.setFileName(filePath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    json = file.readAll();

    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(json.toUtf8());
    return jsonDocument.object().toVariantMap();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<Visitor *> visitors;
    QList<IElement *> collection;

    QVariantMap list =readFromJson();

    foreach (QVariant map, list.value("lista").toList())
    {
        if (map.toMap().value("typeName").toString()==QStringLiteral("Professor"))
            collection << new Professor(map.toMap().value("salario").toDouble());
        else
            collection << new Aluno(map.toMap().value("idade").toInt());
    };

    visitors << new SalarioMedioProfessorVisitor << new IdadeMediaAlunoVisitor;

    foreach (IElement *element, collection)
    {
        foreach (Visitor *visitor, visitors)
        {
            element->accept(visitor);
        }
    }

    foreach (Visitor *element, visitors)
    {
        if (dynamic_cast<SalarioMedioProfessorVisitor *>(element))
        {
            QScopedPointer<SalarioMedioProfessorVisitor> p(dynamic_cast<SalarioMedioProfessorVisitor *>(element));
            qDebug() << "O salario medio dos professores eh: " << p.data()->salarioMedio();
        }
        else
        {
            QScopedPointer<IdadeMediaAlunoVisitor> p(dynamic_cast<IdadeMediaAlunoVisitor *>(element));
            qDebug() << "A idade media dos alunos eh: " << p.data()->idadeMedia();
        }
    }

    return 0;
}

