#pragma once
#include <QString>
#include <QVector>

namespace ding
{
//定义行
using RowData = QVector<QVariant>;
//定义列描述
struct ColumnDef{
    QString key;
    QString title;
};

struct TableData{
    QVector<ColumnDef> columns;
    QVector<RowData> rows;
};

class ITableReader{
public:
    virtual ~ITableReader() = default;
    virtual TableData read(
        const QString &filepath,
        const QVector<ColumnDef> &columns
    ) = 0;
};
}
