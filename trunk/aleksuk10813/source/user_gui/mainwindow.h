#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtXml/QDomElement>
#include <QtXml/QDomDocument>
#include <QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    void addRow(QTableWidget *table, QString protocol, QString address);

    QDomDocument* receivedXML;
public slots:
    void dataReceived(QNetworkReply* reply);
    void dataSended(QNetworkReply* reply);
private slots:
    void on_addSource_clicked();
    void on_buttonBox_accepted();
    void on_sourceTable_itemActivated(QTableWidgetItem *item);
};

#endif // MAINWINDOW_H
