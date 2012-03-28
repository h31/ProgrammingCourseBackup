#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QTableWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QUrl>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QLabel>
#include <QtXml/QDomElement>
#include <QtXml/QDomDocument>

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QTableWidget* sources;
    QTableWidget* destinations;
    QLabel* l;
public slots:
    void dataReceived(QNetworkReply* reply);
};

#endif // WIDGET_H
