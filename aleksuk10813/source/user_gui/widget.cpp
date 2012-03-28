#include "widget.h"
#include <QHBoxLayout>
#include <iostream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("GUI");

    QHBoxLayout* lists = new QHBoxLayout;
    QHBoxLayout* globalLayout = new QHBoxLayout;

    sources = new QTableWidget;
    destinations = new QTableWidget;
    l = new QLabel;
    QStringList headers;

    headers << "Protocol" << "Address";

    sources->setColumnCount(2);
    destinations->setColumnCount(2);

    sources->setHorizontalHeaderLabels(headers);
    destinations->setHorizontalHeaderLabels(headers);

    lists->addWidget(sources);
    lists->addWidget(destinations);
    lists->addWidget(l);
    globalLayout->addLayout(lists);
    setLayout(globalLayout);

    QNetworkAccessManager* getData = new QNetworkAccessManager;
    connect(getData, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(dataReceived(QNetworkReply*)));
    getData->get(QNetworkRequest(QUrl("http://localhost:9863/sources")));
}

Widget::~Widget()
{

}

void Widget::dataReceived(QNetworkReply* reply)
{
    QByteArray payload = reply->read(65535); // TODO
    QString data(payload);
    //l->setText(data);
    QDomDocument doc;
    doc.setContent(payload);
    //QDomNodeList elements = doc.elementsByTagName("source");
    QDomElement root = doc.firstChildElement("data");
    int i=0;
    for (QDomElement elem = root.firstChildElement("source");
         !elem.isNull();
         elem = elem.nextSiblingElement("source"))
    {
        //l->setText(elem.attribute("address"));
        QString t = elem.attribute("address");
        QTableWidgetItem* cell = new QTableWidgetItem;
        cell->setText(elem.attribute("address") );
        sources->setRowCount(sources->rowCount() + 1);
        sources->setItem(i, 1, cell);
        i++;
    }

}
