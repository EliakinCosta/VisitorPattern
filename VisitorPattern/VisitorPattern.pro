QT += core
QT += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VisitorPattern
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    visitor.cpp \
    ielement.cpp \
    professor.cpp \
    aluno.cpp \
    salariomedioprofessorvisitor.cpp \
    idademediaalunovisitor.cpp

HEADERS += \
    visitor.h \
    ielement.h \
    professor.h \
    aluno.h \
    salariomedioprofessorvisitor.h \
    idademediaalunovisitor.h

DISTFILES += \
    teste.json

