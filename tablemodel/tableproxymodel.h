#pragma once    
#include <QSortFilterProxyModel>


namespace ding{

class TableProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit TableProxyModel(QObject *parent = nullptr);

    // 过滤条件接口（对外）
    void setFilterText(const QString &text);
    void setFilterColumn(int column);

protected:
    bool filterAcceptsRow(int sourceRow,
        const QModelIndex &sourceParent) const override;

private:
    QString m_filterText;
    int m_filterColumn = -1; // -1 = 全列
};
}
