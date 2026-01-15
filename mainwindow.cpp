#include "mainwindow.h"
#include <QAbstractTableModel>
#include <QVBoxLayout>
#include <QHBoxLayout>
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , tm(new TableModel(this))
    , jtr(new JsonTableReader("students"))
    , tpm(new TableProxyModel(this))
    , view(new QTableView(this))
    , edit_search(new QLineEdit(this))
    , btn_search(new QPushButton(this))
{
    resize(500,700); 
    auto *widget_1 = new QWidget(this);
    auto *layout_h1 = new QHBoxLayout();
    auto *layout_v1 = new QVBoxLayout();
    this->setLayout(layout_v1);
    widget_1->setLayout(layout_h1);
    layout_h1->addWidget(edit_search);
    layout_h1->addWidget(btn_search);
     
    layout_v1->addWidget(widget_1); 
    layout_v1->addWidget(view);

    QVector<ColumnDef> columns = {
        {"id" , "编号"},
        {"name" , "姓名"},
        {"age" , "年龄"},
        {"gender" , "性别"},
        {"grade" , "成绩"},
        {"major" , "主修"}
    };

    //tm
    TableData data = jtr->read("/home/ding/test/users.json",columns);
    tm->setTableData(data);
    //TableProxyModel
    tpm->setSourceModel(tm);
    tpm->setFilterColumn(-1);
    //view
    view->setModel(tpm);

    //btn_search
    connect(btn_search,&QPushButton::clicked,this,[=]{
        tpm->setFilterText(edit_search->text());
    });
}

MainWindow::~MainWindow() {
    if(jtr != nullptr)
        delete jtr;
}
