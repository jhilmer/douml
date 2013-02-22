// *************************************************************************
//
// Copyright 2012-2013 Nikolai Marchenko.
//
// This file is part of the Douml Uml Toolkit.
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
//
// *************************************************************************
#ifndef _TABLEDATALISTHOLDER_H
#define _TABLEDATALISTHOLDER_H


#include "TableDataInterface.h"
#include <QVariant>
#include <QStringList>
#include <QList>
#include <QHash>
#include <QSharedPointer>
#include "ItemController.h"

//#include "l_tree_controller_global.h"



template<typename T>
class TableDataListHolder : public TableDataInterface
{
  public:
    virtual QVariant GetValue(int row, int column, int role) const;

    virtual void SetValue(int row, int column, int role, const QVariant & value);

    virtual QStringList GetColumns();

    void SetColumns(QStringList _columns);

    void SetData(QList<T*> data);

    QList<T> GetData() const;

    QList<T>& GetData();

    virtual int columnCount() const;

    virtual int rowCount() const;

    void AddGetter(const QPair<int,int> & index, std::function<QVariant(const T*)> function);

    void AddSetter(const QPair<int,int> & index, std::function<void(T*, QVariant)> function);

    virtual int PreviousRowCount();


  private:
     QList<T*> m_data;
     QHash<QPair<int,int>, std::function<void(T*, QVariant)> > setters;
     QHash<QPair<int, int>, std::function<QVariant(const T*)> > getters;
     QSharedPointer<ItemController<T> > controller;

     QStringList m_columns;
     int previousRowCount;
};
template<class T>
QVariant TableDataListHolder<T>::GetValue(int row, int column, int role) const 
{
    // Bouml preserved body begin 0021352A
    if(!getters.contains(QPair<int,int>(column, role)))
        return QVariant();
    QVariant ret = getters[QPair<int,int>(column, role)](m_data.at(row));
    return ret;
    // Bouml preserved body end 0021352A
}

template<class T>
void TableDataListHolder<T>::SetValue(int row, int column, int role, const QVariant & value) 
{
    // Bouml preserved body begin 002135AA
    if(setters.contains(QPair<int,int>(column, role)))
        return;
    setters[QPair<int,int>(column, role)](m_data[row], value);
    // Bouml preserved body end 002135AA
}

template<class T>
QStringList TableDataListHolder<T>::GetColumns() 
{
    // Bouml preserved body begin 0021362A
    return m_columns;
    // Bouml preserved body end 0021362A
}

template<class T>
void TableDataListHolder<T>::SetColumns(QStringList _columns) 
{
    // Bouml preserved body begin 00213C2A
    m_columns = _columns;
    // Bouml preserved body end 00213C2A
}

template<class T>
void TableDataListHolder<T>::SetData(QList<T*>  data)
{
    // Bouml preserved body begin 002136AA
    previousRowCount = m_data.size();
    m_data = data;
    emit reloadData();
    // Bouml preserved body end 002136AA
}

template<class T>
QList<T> TableDataListHolder<T>::GetData() const 
{
    // Bouml preserved body begin 00218C2A
    return m_data;
    // Bouml preserved body end 00218C2A
}

template<class T>
QList<T>& TableDataListHolder<T>::GetData() 
{
    // Bouml preserved body begin 0021E7AA
    return m_data;
    // Bouml preserved body end 0021E7AA
}

template<class T>
int TableDataListHolder<T>::columnCount() const 
{
    // Bouml preserved body begin 002138AA
    return m_columns.size();
    // Bouml preserved body end 002138AA
}

template<class T>
int TableDataListHolder<T>::rowCount() const 
{
    // Bouml preserved body begin 002137AA
    return m_data.size();
    // Bouml preserved body end 002137AA
}

template<class T>
void TableDataListHolder<T>::AddGetter(const QPair<int,int> & index, std::function<QVariant(const T*)> function) 
{
    // Bouml preserved body begin 00213A2A
    getters.insert(index, function);
    // Bouml preserved body end 00213A2A
}

template<class T>
void TableDataListHolder<T>::AddSetter(const QPair<int,int> & index, std::function<void(T*, QVariant)> function) 
{
    // Bouml preserved body begin 00213AAA
    setters.insert(index, function);
    // Bouml preserved body end 00213AAA
}

template<class T>
int TableDataListHolder<T>::PreviousRowCount() 
{
    // Bouml preserved body begin 0022372A
    return previousRowCount;
    // Bouml preserved body end 0022372A
}

#endif
