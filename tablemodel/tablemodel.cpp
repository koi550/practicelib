#include "tablemodel.h"
#include <qvariant.h>

namespace ding
{

TableModel::TableModel(QObject * parent)
    :QAbstractTableModel(parent)
{
    
}

void TableModel::setTableData(TableData data){
    m_data = data;
}

int TableModel::rowCount(const QModelIndex &) const
{
    return m_data.rows.size();
}

int TableModel::columnCount(const QModelIndex &)const
{
    return m_data.columns.size();
}

QVariant TableModel::data(const QModelIndex & index, int role) const{
    if(!index.isValid())
        return {};
    const int row = index.row();
    const int col = index.column();

    if(row < 0 || row >= m_data.rows.size())
        return {};
    if(row < 0 || col >= m_data.columns.size())
        return {};
    switch (role){
        case Qt::DisplayRole:
            return m_data.rows[row][col];
        case Qt::TextAlignmentRole:
            return Qt::AlignCenter;
        default:return {};
    }
}

QVariant TableModel::headerData(int section,Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return {};
    if(orientation == Qt::Horizontal){
        if(section < 0 || section >= m_data.columns.size())
            return {};
        return m_data.columns[section].title;
    }
    return section + 1;
}
}
