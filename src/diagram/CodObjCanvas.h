// *************************************************************************
//
// Copyright 2004-2010 Bruno PAGES  .
// Copyright 2012-2013 Nikolai Marchenko.
// Copyright 2012-2013 Leonardo Guilherme.
//
// This file is part of the DOUML Uml Toolkit.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License Version 3.0 as published by
// the Free Software Foundation and appearing in the file LICENSE.GPL included in the
//  packaging of this file.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License Version 3.0 for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//
// e-mail : doumleditor@gmail.com
// home   : http://sourceforge.net/projects/douml
//
// *************************************************************************

#ifndef CODOBJCANVAS_H
#define CODOBJCANVAS_H

#include "DiagramCanvas.h"

class QStringList;
class CodSelfLinkCanvas;
class BrowserClass;
class ColMsgList;

class CodObjCanvas : public DiagramCanvas
{
protected:
    CodSelfLinkCanvas * self_link;

public:
    CodObjCanvas(BrowserNode * bn, UmlCanvas * canvas,
                 int x, int y, int w, int h, int id);
    virtual ~CodObjCanvas();

    virtual void delete_it() override;

    virtual void delete_available(BooL & in_model, BooL & out_model) const override;

    virtual void moveBy(double dx, double dy) override;
    virtual void set_z(double z) override;

    virtual BrowserClass * get_class() const;
    virtual QString may_start(UmlCode &) const override;
    virtual QString may_connect(UmlCode & l, const DiagramItem * dest) const override;
    virtual void connexion(UmlCode, DiagramItem *, const QPoint &, const QPoint &) override;
    virtual void change_scale() override;

    virtual QString get_full_name() const = 0;
    void get_all_in_all_out(ColMsgList & all_in, ColMsgList & all_out) const;

    void set_self_link(CodSelfLinkCanvas * l) {
        self_link = l;
    };

    static CodObjCanvas * read(char *& st, UmlCanvas * canvas);
};

#endif

