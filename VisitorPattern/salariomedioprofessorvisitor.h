#ifndef SALARIOMEDIOPROFESSORVISITOR_H
#define SALARIOMEDIOPROFESSORVISITOR_H

#include "visitor.h"

class SalarioMedioProfessorVisitor : public Visitor
{
public:
    SalarioMedioProfessorVisitor();
    virtual ~SalarioMedioProfessorVisitor(){}
    virtual void visitProfessor(Professor *professor);
    double salarioMedio();
private:
    double m_salarioTotal;
    int m_quantidadePessoas;
};

#endif // SALARIOMEDIOPROFESSORVISITOR_H
