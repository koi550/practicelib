#pragma once    
#include "jsontablereader.h"
#include <QAbstractTableModel>
#include <qabstractitemmodel.h>
#include <qobject.h>
#include <qtmetamacros.h>

namespace ding{

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit TableModel(QObject * parent = nullptr);
    void setTableData(TableData data);
    
    int rowCount(const QModelIndex &) const override;
    int columnCount(const QModelIndex &) const override;
    QVariant data(const QModelIndex &,int role) const override;
    QVariant headerData(int section,Qt::Orientation,int role) const override;
private:
    TableData m_data;
};
}

