#ifndef ALUNO_H
#define ALUNO_H

#include "ielement.h"

class Visitor;

class Aluno : public IElement
{
public:
    Aluno(int idade=0.0);
    virtual ~Aluno(){}
    virtual void accept(Visitor *visitor);
    int idade();
private:
    int m_idade;
};

#endif // ALUNO_H
