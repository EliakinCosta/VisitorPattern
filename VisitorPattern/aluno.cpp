#include "aluno.h"
#include "visitor.h"

Aluno::Aluno(int idade):
    m_idade(idade)
{

}

void Aluno::accept(Visitor *visitor)
{
    visitor->visitAluno(this);
}

int Aluno::idade()
{
    return m_idade;
}
