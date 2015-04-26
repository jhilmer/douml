#ifndef _UMLACCESSVARIABLEVALUEACTION_H
#define _UMLACCESSVARIABLEVALUEACTION_H



#include "UmlBaseAccessVariableValueAction.h"

class UmlAccessVariableValueAction : public UmlBaseAccessVariableValueAction
{
public:
    //entry to produce the html code receiving chapter number
    //path, rank in the mother and level in the browser tree
    virtual void html(QByteArray pfix, unsigned int rank, unsigned int level);


protected:
    //  the constructor, do not call it yourself !!!!!!!!!!
    UmlAccessVariableValueAction(void * id, const QByteArray & s) : UmlBaseAccessVariableValueAction(id, s) {
    }

};

#endif
