#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add_dialog.h"
#include <QMessageBox>

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
    root = new QDomElement(receivedXML->firstChildElement("data") );

    for (QDomElement elem = root->firstChildElement("source");
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
    if (!addDialog->accepted)
        return;
    addRow(ui->sourceTable, addDialog->protocol, addDialog->address);

    QDomElement source = receivedXML->createElement("source");
    source.setAttribute("protocol", addDialog->protocol);
    source.setAttribute("address", addDialog->address);
    root->appendChild(source);
}

void MainWindow::on_removeSource_clicked()
{
    if (ui->sourceTable->currentColumn() != 1)
    {
        QMessageBox::warning(this, "Warning", "Нужно выбрать адрес, а не протокол");
        return;
    }

    QList<QTableWidgetItem*> selectedItems(ui->sourceTable->selectedItems() );
    QTableWidgetItem* item = selectedItems.front();
    for (QDomElement elem = root->firstChildElement("source");
         !elem.isNull();
         elem = elem.nextSiblingElement("source"))
    {
        if (elem.attribute("address") == item->text() )
        {
            ui->sourceTable->removeRow(ui->sourceTable->currentRow() );
            root->removeChild(elem);
            break;
        }
    }
}

void MainWindow::on_addDestination_clicked()
{
    AddDialog* addDialog = new AddDialog;
    addDialog->exec();
    if (!addDialog->accepted)
        return;
    addRow(ui->destinationsTable, addDialog->protocol, addDialog->address);

    QList<QTableWidgetItem*> selectedItems(ui->sourceTable->selectedItems() );
    QTableWidgetItem* item = selectedItems.front();
    for (QDomElement elem = root->firstChildElement("source");
         !elem.isNull();
         elem = elem.nextSiblingElement("source"))
    {
        if (elem.attribute("address") == item->text() )
        {
            QDomElement destination = receivedXML->createElement("destination");
            destination.setAttribute("protocol", addDialog->protocol);
            destination.setAttribute("address", addDialog->address);
            elem.appendChild(destination);
            break;
        }
    }
}

void MainWindow::on_removeDestination_clicked()
{
    if (ui->destinationsTable->currentColumn() != 1)
    {
        QMessageBox::warning(this, "Warning", "Нужно выбрать адрес, а не протокол");
        return;
    }

    QList<QTableWidgetItem*> selectedSourceItems(ui->sourceTable->selectedItems() );
    QTableWidgetItem* sourceItem = selectedSourceItems.front();

    QList<QTableWidgetItem*> selectedDestinationItems(ui->destinationsTable->selectedItems() );
    QTableWidgetItem* destinationItem = selectedDestinationItems.front();

    for (QDomElement sourceElem = root->firstChildElement("source");
         !sourceElem.isNull();
         sourceElem = sourceElem.nextSiblingElement("source"))
    {
        if (sourceElem.attribute("address") == sourceItem->text() )
        {
            for (QDomElement destinationElem = sourceElem.firstChildElement("destination");
                 !destinationElem.isNull();
                 destinationElem = destinationElem.nextSiblingElement("destination"))
            {
                if (destinationElem.attribute("address") == destinationItem->text() )
                {
                    ui->destinationsTable->removeRow(ui->destinationsTable->currentRow() );
                    sourceElem.removeChild(destinationElem);
                    break;
                }
            }
            break;
        }
    }
}

void MainWindow::on_buttonBox_accepted()
{
    ui->textEdit->setPlainText(receivedXML->toString().toUtf8() );

    QNetworkAccessManager* postData = new QNetworkAccessManager;
//    connect(postData, SIGNAL(finished(QNetworkReply*)),
//            this, SLOT(dataSended(QNetworkReply*)));
    postData->post(QNetworkRequest(QUrl("http://localhost:9862/directions")), receivedXML->toString().toUtf8() );
}

void MainWindow::on_sourceTable_itemActivated(QTableWidgetItem *item)
{
    ui->destinationsTable->clearContents();
    ui->destinationsTable->setRowCount(0);

    for (QDomElement sourceElem = root->firstChildElement("source");
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

void MainWindow::on_buttonBox_rejected()
{
    exit(0);
}
