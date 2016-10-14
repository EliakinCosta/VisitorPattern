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

#include "visitor.h"
#include "ielement.h"
#include "aluno.h"
#include "professor.h"
#include "idademediaalunovisitor.h"
#include "salariomedioprofessorvisitor.h"

QVariantMap readFromJson()
{
    QDir projectDir = QDir(qApp->applicationDirPath());
    projectDir.cdUp();

    QFile file;
    QString filePath = projectDir.absolutePath().append("/VisitorPattern/").append("teste.json");
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

