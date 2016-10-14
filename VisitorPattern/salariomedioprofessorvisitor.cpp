#include "salariomedioprofessorvisitor.h"
#include "professor.h"

#include <QDebug>

SalarioMedioProfessorVisitor::SalarioMedioProfessorVisitor():
    m_salarioTotal(0.0),
    m_quantidadePessoas(0)
{

}

void SalarioMedioProfessorVisitor::visitProfessor(Professor *professor)
{
    m_quantidadePessoas++;
    m_salarioTotal += professor->salario();
}

double SalarioMedioProfessorVisitor::salarioMedio()
{
    if (m_quantidadePessoas==0)
        return 0.0;
    return m_salarioTotal / m_quantidadePessoas;
}
