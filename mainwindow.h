#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tablemodel/jsontablereader.h"
#include "tablemodel/tableproxymodel.h"
#include "tablemodel/tablemodel.h"

#include <QWidget>
#include <QTableView>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
using namespace ding;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    TableModel * tm;
    JsonTableReader *jtr;
    TableProxyModel *tpm;
    QTableView *view;
    QLineEdit *edit_search;
    QPushButton *btn_search;
};
#endif // MAINWINDOW_H
