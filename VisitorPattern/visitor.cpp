#include "visitor.h"

#include <QtGlobal>

Visitor::Visitor()
{

}

void Visitor::visitProfessor(Professor *professor)
{
    Q_UNUSED(professor)
}

void Visitor::visitAluno(Aluno *aluno)
{
    Q_UNUSED(aluno)
}
