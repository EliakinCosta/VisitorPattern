#ifndef VISITOR_H
#define VISITOR_H

class Professor;
class Aluno;

class Visitor
{
public:
    virtual ~Visitor(){}
    virtual void visitProfessor(Professor *professor);
    virtual void visitAluno(Aluno *professor);
protected:
    Visitor();
};

#endif // VISITOR_H
