#ifndef _UMLPSEUDOSTATE_H
#define _UMLPSEUDOSTATE_H



#include "UmlItem.h"
#include "UmlStateItem.h"

class UmlPseudoState : public UmlStateItem, public UmlItem
{
public:
    //  the constructor, do not call it yourself !!!!!!!!!!
    UmlPseudoState(void * id, const QByteArray & s) : UmlItem(id, s) {
    }

    //entry to produce the html code receiving chapter number
    //path, rank in the mother and level in the browser tree
    virtual void html(QByteArray pfix, unsigned int rank, unsigned int level);

};

#endif
