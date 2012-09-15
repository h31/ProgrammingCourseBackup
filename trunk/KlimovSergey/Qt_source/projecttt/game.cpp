#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    player.name = QInputDialog::getText(0,"Введите ваше имя",
                                        "Имя:",
                                        QLineEdit::Normal,
                                        "Игрок");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), QBrush(QImage("1000225629.jpg")));
    this->setPalette(pal);

}

Game::~Game()
{
    delete ui;
}

QString temp = "";

void Game::on_actionStart_activated()
{
    fileName = QFileDialog::getOpenFileName(this,tr("Choose file"),"",tr("(*.txt);;All Files (*)"));
    complFile = fileName+"_c";
    field.loadField(fileName);
    field.createEmpty();
    this->setFixedSize(field.sizex,field.sizey+21);
    temp = fileName;
}

void Game::paintEvent(QPaintEvent *)
{
    QPainter qp;
    qp.begin(this);
    if (field.ready)
    {
        pf.paintF(field,qp);
    }
    qp.end();
}

void Game::closeEvent(QCloseEvent *event)
{
    if (QMessageBox::question(this, "Подтвердить",
                              "Действительно выйти?",
                              QMessageBox::Yes,
                              QMessageBox::No)==QMessageBox::Yes)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void Game::mousePressEvent(QMouseEvent * ev)
{
    if (ev->button() == Qt::LeftButton)
        leftButtonPressEvent(ev);
    else if (ev->button() == Qt::RightButton)
        rightButtonPressEvent(ev);
}

void Game::leftButtonPressEvent(QMouseEvent* ev)
{
    int d = sqSize + 1;
    int ds;
    ds =d;
    int kx = 0;
    int ky = 0;
    int tx = ev->x()- ds*field.vcol;
    int ty = ev->y()-21-ds*field.hcol;
    if(tx > 0 && ty > 0)
    {
        while(tx/d!=0)
        {
            d+=ds;
            kx++;
        }
        d = sqSize+1;

        while(ty/d!=0)
        {
            d+=ds;
            ky++;
        }
    if(field.getSqStat(kx,ky)!=1)
        field.setSqStat(1,kx,ky);
    else
        field.setSqStat(2,kx,ky);
    }
    repaint();
}

void Game::rightButtonPressEvent(QMouseEvent * ev)
{
    int d = sqSize + 1;
    int ds;
    ds = d;
    int kx = 0;
    int ky = 0;
    int tx = ev->x()-ds*field.vcol;
    int ty = ev->y()-21-ds*field.hcol;
    if(tx > 0 && ty > 0)
    {
        while(tx/d!=0)
        {
            d+=ds;
            kx++;
        }
        d = sqSize+1;

        while(ty/d!=0)
        {
            d+=ds;
            ky++;
        }
    if(field.getSqStat(kx,ky)!=0)
        field.setSqStat(0,kx,ky);
    else
        field.setSqStat(2,kx,ky);
    }
    repaint();
}

void Game::on_actionCheck_activated()
{
    QString str;
    if(field.Check(complFile))
    {
        str = "Success!";
    }
    else
        str = "Fail!";
    QMessageBox::information(0,"Game status",str);
}

void Game::on_actionExit_activated()
{
    this->close();
}

void Game::on_actionSave_activated()
{
    QString fileName = QFileDialog::getSaveFileName(this,
             tr("Save crossword"), "",
             tr("(*.save);;All Files (*)"));
    QFile file(fileName);
    file.open(QIODevice::Append | QIODevice::Text);
    QTextStream out(&file);
    out<<field.width<<" "<<field.height<<endl;
    for(int j=0;j<field.height;j++)
        {
            for(int i=0;i<field.width;i++)
            {
                out<<field.getSqStat(i,j)<<" ";
            }
            out<<endl;
        }
    out<<temp<<endl;
    file.close();
}

void Game::on_actionLoad_activated()
{
    QString fileName1 = QFileDialog::getOpenFileName(this,tr("Choose file to load"), "", tr("(*.save);;All Files (*)"));
    QFile file(fileName1);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(&file);
    int a,b;
    in>>a>>b;
    for(int i=0;i<=b;i++)
        in.readLine();
    QString sour = in.readLine();
    complFile = sour+"_c";
    field.loadField(sour);
    field.createEmpty();
    this->setFixedSize(field.sizex,field.sizey+21);
    file.close();
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    in>>field.width>>field.height;
    int tmp;
    for(int j=0;j<field.height;j++)
        {
            for(int i=0;i<field.width;i++)
            {
                in >> tmp;
                field.setSqStat(tmp,i,j);
            }
        }
    repaint();
}

void Game::on_actionShow_Answer_activated()
{
    if(temp != "")
    {
        field.loadField(temp);
        field.loadComplete(temp+"_c");
        repaint();
    }
    else
    {
        QMessageBox::information(0,"Information","Start game!");
    }
}
