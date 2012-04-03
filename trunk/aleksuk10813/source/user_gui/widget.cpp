#include "widget.h"
#include <QHBoxLayout>
#include <QToolButton>
#include <iostream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("GUI");

    // TODO: Объединить в блок
    QHBoxLayout* lists = new QHBoxLayout;
    QVBoxLayout* sourceListBlock = new QVBoxLayout;
    QVBoxLayout* destinationListBlock = new QVBoxLayout;
    QHBoxLayout* sourceButtons = new QHBoxLayout;
    QHBoxLayout* destinationButtons = new QHBoxLayout;
    QHBoxLayout* globalLayout = new QHBoxLayout;


    sources = new QTableWidget;
    destinations = new QTableWidget;

    QStringList headers;
    headers << "Protocol" << "Address";

    // TODO: много дублирования кода

    sources->setColumnCount(2);
    destinations->setColumnCount(2);

    sources->setHorizontalHeaderLabels(headers);
    destinations->setHorizontalHeaderLabels(headers);

    l = new QLabel;

    QToolButton* addSource = new QToolButton;
    QToolButton* removeSource = new QToolButton;
    addSource->setIcon(QIcon::fromTheme("list-add"));
    removeSource->setIcon(QIcon::fromTheme("list-remove"));

    QToolButton* addDestination = new QToolButton;
    QToolButton* removeDestination = new QToolButton;
    addDestination->setIcon(QIcon::fromTheme("list-add"));
    removeDestination->setIcon(QIcon::fromTheme("list-remove"));

    sourceButtons->addWidget(addSource);
    sourceButtons->addWidget(removeSource);
    sourceButtons->addStretch(0);
    sourceListBlock->addWidget(sources);
    sourceListBlock->addLayout(sourceButtons);

    destinationButtons->addWidget(addDestination);
    destinationButtons->addWidget(removeDestination);
    destinationButtons->addStretch(0);
    destinationButtons->setAlignment(Qt::AlignRight); // TODO: не работает
    destinationListBlock->addWidget(destinations);
    destinationListBlock->addLayout(destinationButtons);

    lists->addLayout(sourceListBlock);
    lists->addLayout(destinationListBlock);
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
