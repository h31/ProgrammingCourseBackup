#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add_dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QNetworkAccessManager* getData = new QNetworkAccessManager;
    connect(getData, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(dataReceived(QNetworkReply*)));
    getData->get(QNetworkRequest(QUrl("http://localhost:9862/directions")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addRow(QTableWidget *table, QString protocol, QString address)
{
    int currentRowNumber = table->rowCount();
    table->setRowCount(currentRowNumber + 1);

    QTableWidgetItem* protocolCell = new QTableWidgetItem;
    protocolCell->setText(protocol);
    table->setItem(currentRowNumber, 0, protocolCell);

    QTableWidgetItem* addressCell = new QTableWidgetItem;
    addressCell->setText(address);
    table->setItem(currentRowNumber, 1, addressCell);
}

void MainWindow::dataReceived(QNetworkReply* reply)
{
    QByteArray payload = reply->read(65535); // TODO
    ui->textEdit->insertPlainText(QString(payload));

    receivedXML = new QDomDocument;
    receivedXML->setContent(payload);
    QDomElement root = receivedXML->firstChildElement("data");

    for (QDomElement elem = root.firstChildElement("source");
         !elem.isNull();
         elem = elem.nextSiblingElement("source"))
    {
        addRow(ui->sourceTable, elem.attribute("protocol"), elem.attribute("address"));
    }
}

void MainWindow::dataSended(QNetworkReply *reply)
{

}

void MainWindow::on_addSource_clicked()
{
    AddDialog* addDialog = new AddDialog;
    addDialog->exec();
    addRow(ui->sourceTable, addDialog->protocol, addDialog->address);
}

void MainWindow::on_buttonBox_accepted()
{
    QDomDocument doc;
    QDomElement root = doc.createElement("data");
    doc.appendChild(root);

    for (int i=0; i < ui->sourceTable->rowCount(); i++)
    {
        QDomElement source = doc.createElement("source");
        source.setAttribute("protocol", ui->sourceTable->item(i, 0)->text() );
        source.setAttribute("address", ui->sourceTable->item(i, 1)->text() );
        root.appendChild(source);
    }
    ui->textEdit->setPlainText(doc.toString().toUtf8() );
//    ui->sourceTable->item(0, 0)->data()
    //elem.setAttribute("src", "myimage.png");

    QNetworkAccessManager* postData = new QNetworkAccessManager;
    connect(postData, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(dataSended(QNetworkReply*)));
    postData->post(QNetworkRequest(QUrl("http://localhost:9862/directions")), doc.toString().toUtf8() );
}

void MainWindow::on_sourceTable_itemActivated(QTableWidgetItem *item)
{
    ui->destinationsTable->clearContents();
    ui->destinationsTable->setRowCount(0);

    QDomElement root = receivedXML->firstChildElement("data");

    for (QDomElement sourceElem = root.firstChildElement("source");
         !sourceElem.isNull();
         sourceElem = sourceElem.nextSiblingElement("source"))
    {
        if (sourceElem.attribute("address") == item->text())
        {
            for (QDomElement destinationElem = sourceElem.firstChildElement("destination");
                 !destinationElem.isNull();
                 destinationElem = destinationElem.nextSiblingElement("destination"))
            {
                addRow(ui->destinationsTable, destinationElem.attribute("protocol"), destinationElem.attribute("address"));
            }
            break;
        }
    }
}
