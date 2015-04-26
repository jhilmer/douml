
#include "UmlOperation.h"

#include <stdio.h>
#include "UmlClass.h"
#include "CppSettings.h"
#include "JavaSettings.h"
#include "IdlSettings.h"
#include "PhpSettings.h"
#include "PythonSettings.h"
//Added by qt3to4:
#include <QByteArray>
#include <QList>
void UmlOperation::uml2cpp(bool)
{
    QByteArray st = CppSettings::classStereotype(parent()->stereotype());

    if ((st == "enum") || (st == "typedef") || (st == "ignored")) {
        set_CppDecl("");
        set_CppDef("");
        return;
    }

    if (getOf() || setOf())
        return;

    QByteArray decl = CppSettings::operationDef();
    QByteArray def = CppSettings::operationDef();
    const QList<UmlParameter> p = params();
    QByteArray sparams;

    if (!p.isEmpty()) {
        QList<UmlParameter>::ConstIterator it;
        unsigned rank;
        const char * sep = "";

        for (it = p.begin(), rank = 0; it != p.end(); ++it, rank += 1, sep = ", ")
            sparams += sep + (*it).cpp(rank);
    }

    UmlTypeSpec t = returnType();
    QByteArray returntypeform;

    if ((name() != parent()->name()) &&
        (name() != "~" + parent()->name())) {
        if (t.type != 0)
            returntypeform = (CppSettings::classStereotype(t.type->stereotype()) == "enum")
                             ? CppSettings::enumReturn() : CppSettings::Return();
        else if (t.explicit_type.isEmpty()) {
            t.explicit_type = "void";
            set_ReturnType(t);
        }
        else if ((returntypeform = CppSettings::builtinReturn(t.explicit_type))
                 .isEmpty())
            returntypeform = CppSettings::Return();
    }

    QByteArray d;

    d = CppSettings::operationDecl();
    d.insert(d.indexOf("${)}"), (const char *)sparams); //[rageek] ambiguous
    d.replace(d.indexOf("${type}"), 7, returntypeform);
    set_CppDecl(d);

    if (isAbstract())
        set_CppDef("");
    else {
        int index1 = 0;
        int index2;

        while ((index2 = sparams.indexOf("${v", index1)) != -1) {
            sparams.remove(index2, sparams.indexOf('}', index2 + 3) - index2 + 1);
            index1 = index2;
        }

        d = CppSettings::operationDef();
        d.insert(d.indexOf("${)}"), (const char *)sparams); //[rageek] ambiguous
        d.replace(d.indexOf("${type}"), 7, returntypeform);
        set_CppDef(d);
    }
}

void UmlOperation::uml2java(bool)
{
    QByteArray st = JavaSettings::classStereotype(parent()->stereotype());

    if ((st == "enum") || (st == "ignored")) {
        set_JavaDef("");
        return;
    }

    if (getOf() || setOf())
        return;

    QByteArray def = JavaSettings::operationDef();
    unsigned nparams = params().count();

    if (nparams != 0) {
        const char * sep = "";
        QByteArray sparams;
        unsigned rank;

        for (rank = 0; rank != nparams; rank += 1) {
            char s[32];

            sprintf(s, "%s${t%u} ${p%u}", sep, rank, rank);
            sparams += s;
            sep = ", ";
        }

        def.insert(def.indexOf("${)}"), (const char *)sparams); //[rageek] ambiguous
    }

    if (name() == parent()->name())
        def.remove(def.indexOf("${type}"), 7);
    else {
        UmlTypeSpec t = returnType();

        if ((t.type == 0) && t.explicit_type.isEmpty()) {
            t.explicit_type = "void";

            set_ReturnType(t);
        }
    }

    set_JavaDef(def);

}

void UmlOperation::uml2idl(bool)
{
    QByteArray st = IdlSettings::classStereotype(parent()->stereotype());

    if ((st == "enum") || (st == "typedef") || (st == "ignored")) {
        set_IdlDecl("");
        return;
    }

    if (getOf() || setOf())
        return;

    QByteArray def = IdlSettings::operationDecl();
    unsigned nparams = params().count();

    if (nparams != 0) {
        const char * sep = "";
        QByteArray sparams;
        unsigned rank;

        for (rank = 0; rank != nparams; rank += 1) {
            char s[64];

            sprintf(s, "%s${d%d} ${t%u} ${p%u}", sep, rank, rank, rank);
            sparams += s;
            sep = ", ";
        }

        def.insert(def.indexOf("${)}"), (const char *)sparams); //[rageek] ambiguous
    }

    set_IdlDecl(def);

    UmlTypeSpec t = returnType();

    if ((t.type == 0) && t.explicit_type.isEmpty()) {
        t.explicit_type = "void";

        set_ReturnType(t);
    }
}

void UmlOperation::uml2php(bool)
{
    QByteArray st = PhpSettings::classStereotype(parent()->stereotype());

    if ((st == "enum") || (st == "ignored")) {
        set_PhpDef("");
        return;
    }

    if (getOf() || setOf())
        return;

    QByteArray def = PhpSettings::operationDef();

    if ((name() == parent()->name()) ||
        (name() == "__construct") ||
        (name() == "__destruct")) {
        int index = def.indexOf("${static}");

        if (index != -1)
            def.remove(index, 9);
    }

    if (isAbstract() ||
        (PhpSettings::classStereotype(parent()->stereotype()) == "interface")) {
        int index = def.indexOf("${)}");

        if (index != -1)
            def = def.left(index + 4) + ";";
    }

    unsigned nparams = params().count();

    if (nparams != 0) {
        const char * sep = "";
        QByteArray sparams;
        unsigned rank;

        for (rank = 0; rank != nparams; rank += 1) {
            char s[16];

            sprintf(s, "%s${p%u}${v%u}", sep, rank, rank);
            sparams += s;
            sep = ", ";
        }

        def.insert(def.indexOf("${)}"), (const char *)sparams); //[rageek] ambiguous
    }

    set_PhpDef(def);

    UmlTypeSpec t = returnType();

    if ((t.type == 0) && t.explicit_type.isEmpty()) {
        t.explicit_type = "void";

        set_ReturnType(t);
    }
}

void UmlOperation::uml2python(bool)
{
    QByteArray st = PythonSettings::classStereotype(parent()->stereotype());

    if ((st == "enum") || (st == "ignored")) {
        set_PythonDef("");
        return;
    }

    if (getOf() || setOf())
        return;

    QByteArray def = PythonSettings::operationDef();
    unsigned nparams = params().count();

    if (nparams != 0) {
        const char * sep = "";
        QByteArray sparams;
        unsigned rank;

        for (rank = 0; rank != nparams; rank += 1) {
            char s[16];

            sprintf(s, "%s${p%u}${v%u}", sep, rank, rank);
            sparams += s;
            sep = ", ";
        }

        def.insert(def.indexOf("${)}"), (const char *)sparams); //[rageek] ambiguous
    }

    set_PythonDef(def);
}

