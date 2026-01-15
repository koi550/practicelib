#include "jsontablereader.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
namespace ding{
JsonTableReader::JsonTableReader(const QString & arrayKey)
    :m_key(arrayKey)
{
}


TableData JsonTableReader::read(const QString &path,
                                const QVector<ColumnDef> &columns)
{
    TableData table;
    table.columns = columns;

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "json 文件打开失败";
    }
    auto doc = QJsonDocument::fromJson(file.readAll());
    QJsonArray arr;
    if(doc.isArray()){
        arr = doc.array();
    }else if(doc.isObject()){
        QJsonObject root = doc.object();
        arr = root.value(m_key).toArray();
    }else{
        return table;
    }
    for (auto v : arr) {
        QJsonObject obj = v.toObject();
        RowData row;

        for (const auto &col : columns)
            row << obj.value(col.key).toVariant();

        table.rows << row;
    }

    return table;
}
}
