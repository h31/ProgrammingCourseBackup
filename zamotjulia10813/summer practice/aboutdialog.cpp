#include "aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent):
    QDialog(parent)
{
    label = new QLabel(this);
    label->setText("<b>Designed by ZamotJulia </b>");
    label->show();
}

AboutDialog::~AboutDialog()
{
}

void AboutDialog::paintEvent(QPaintEvent *)
{
    QPainter qp;
    qp.begin(this);
    qp.end();
}
