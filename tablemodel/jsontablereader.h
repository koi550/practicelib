#pragma once
#include "itablereader.h"

namespace ding
{
class JsonTableReader : public ITableReader
{
public:
    explicit JsonTableReader(const QString &arrayKey);
    TableData read(const QString &path,
                   const QVector<ColumnDef> &columns) override;
private:
    QString m_key;
};
}
