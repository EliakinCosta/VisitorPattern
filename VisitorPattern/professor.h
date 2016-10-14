#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "ielement.h"

class Visitor;

class Professor : public IElement
{
public:
    Professor(double salario=0.0);
    virtual ~Professor(){}
    virtual void accept(Visitor *visitor);
    double salario();
private:
    double m_salario;
};

#endif // PROFESSOR_H
