#ifndef ELEMENT_H
#define ELEMENT_H

class Visitor;

class IElement
{
public:
    IElement();
    virtual ~IElement(){}
    virtual void accept(Visitor *visitor) = 0;
};

#endif // ELEMENT_H
