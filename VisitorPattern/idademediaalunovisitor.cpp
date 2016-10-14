#include "idademediaalunovisitor.h"
#include "aluno.h"

#include <QDebug>

IdadeMediaAlunoVisitor::IdadeMediaAlunoVisitor():
    m_idadeTotal(0.0),
    m_quantidadeAlunos(0)
{

}

void IdadeMediaAlunoVisitor::visitAluno(Aluno *aluno)
{
    m_quantidadeAlunos++;
    m_idadeTotal += aluno->idade();
}

double IdadeMediaAlunoVisitor::idadeMedia()
{
    if (m_quantidadeAlunos==0)
        return 0;
    return m_idadeTotal / m_quantidadeAlunos;
}



