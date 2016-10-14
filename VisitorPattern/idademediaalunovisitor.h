#ifndef IDADEMEDIAALUNOVISITOR_H
#define IDADEMEDIAALUNOVISITOR_H

#include "visitor.h"

class Aluno;

class IdadeMediaAlunoVisitor : public Visitor
{
public:
    IdadeMediaAlunoVisitor();
    virtual ~IdadeMediaAlunoVisitor(){}
    virtual void visitAluno(Aluno *aluno);
    double idadeMedia();
private:
    double m_idadeTotal;
    int m_quantidadeAlunos;
};

#endif // IDADEMEDIAALUNOVISITOR_H
