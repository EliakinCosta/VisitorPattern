#include "professor.h"
#include "visitor.h"

Professor::Professor(double salario):
    m_salario(salario)
{

}

void Professor::accept(Visitor *visitor)
{
    visitor->visitProfessor(this);
}

double Professor::salario()
{
    return m_salario;
}
