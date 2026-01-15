#include "tableproxymodel.h"


namespace ding{

TableProxyModel::TableProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{
    setFilterCaseSensitivity(Qt::CaseInsensitive);
}
    
bool TableProxyModel::filterAcceptsRow(int sourceRow,
                                       const QModelIndex &sourceParent) const
{
   if(m_filterText.isEmpty())
        return true;
    const QAbstractItemModel *model = sourceModel();
    if(m_filterColumn >= 0){
        QModelIndex idx = model->index(sourceRow, m_filterColumn, sourceParent);
        return model->data(idx).toString().contains(m_filterText);
    }

    for(int col = 0; col < model->columnCount(); ++col){
        QModelIndex idx = model->index(sourceRow, col, sourceParent);
        if(model->data(idx).toString().contains(m_filterText))
            return true;
    }
    return false;
}

void TableProxyModel::setFilterText(const QString &text)
{
    beginFilterChange();
    m_filterText = text;
    endFilterChange();
}

void TableProxyModel::setFilterColumn(int column)
{
    beginFilterChange();
    m_filterColumn = column;
    endFilterChange();
}

}
