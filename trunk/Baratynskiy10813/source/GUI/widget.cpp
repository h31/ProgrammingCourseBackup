#include "widget.h"
#include "QHBoxLayout"

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    game = new Game;
    win = new WinWidget;
    lose = new LoseWidget;
    a = new QPushButton("A");
    b = new QPushButton("B");
    c = new QPushButton("C");
    d = new QPushButton("D");
    e = new QPushButton("E");
    f = new QPushButton("F");
    g = new QPushButton("G");
    h = new QPushButton("H");
    i = new QPushButton("I");
    j = new QPushButton("J");
    k = new QPushButton("K");
    l = new QPushButton("L");
    m = new QPushButton("M");
    n = new QPushButton("N");
    o = new QPushButton("O");
    p = new QPushButton("P");
    q = new QPushButton("Q");
    r = new QPushButton("R");
    s = new QPushButton("S");
    t = new QPushButton("T");
    u = new QPushButton("U");
    v = new QPushButton("V");
    w = new QPushButton("W");
    x = new QPushButton("X");
    y = new QPushButton("Y");
    z = new QPushButton("Z");
    label = new QLabel;
    miss = new QLabel;
}

void Widget::connectButtons()
{
    QObject::connect(a,SIGNAL(clicked()),this,SLOT(on_A_clicked()));
    QObject::connect(a,SIGNAL(clicked()),a,SLOT(close()));
    QObject::connect(b,SIGNAL(clicked()),this,SLOT(on_B_clicked()));
    QObject::connect(b,SIGNAL(clicked()),b,SLOT(close()));
    QObject::connect(c,SIGNAL(clicked()),this,SLOT(on_C_clicked()));
    QObject::connect(c,SIGNAL(clicked()),c,SLOT(close()));
    QObject::connect(d,SIGNAL(clicked()),this,SLOT(on_D_clicked()));
    QObject::connect(d,SIGNAL(clicked()),d,SLOT(close()));
    QObject::connect(e,SIGNAL(clicked()),this,SLOT(on_E_clicked()));
    QObject::connect(e,SIGNAL(clicked()),e,SLOT(close()));
    QObject::connect(f,SIGNAL(clicked()),this,SLOT(on_F_clicked()));
    QObject::connect(f,SIGNAL(clicked()),f,SLOT(close()));
    QObject::connect(g,SIGNAL(clicked()),this,SLOT(on_G_clicked()));
    QObject::connect(g,SIGNAL(clicked()),g,SLOT(close()));
    QObject::connect(h,SIGNAL(clicked()),this,SLOT(on_H_clicked()));
    QObject::connect(h,SIGNAL(clicked()),h,SLOT(close()));
    QObject::connect(i,SIGNAL(clicked()),this,SLOT(on_I_clicked()));
    QObject::connect(i,SIGNAL(clicked()),i,SLOT(close()));
    QObject::connect(j,SIGNAL(clicked()),this,SLOT(on_J_clicked()));
    QObject::connect(j,SIGNAL(clicked()),j,SLOT(close()));
    QObject::connect(k,SIGNAL(clicked()),this,SLOT(on_K_clicked()));
    QObject::connect(k,SIGNAL(clicked()),k,SLOT(close()));
    QObject::connect(l,SIGNAL(clicked()),this,SLOT(on_L_clicked()));
    QObject::connect(l,SIGNAL(clicked()),l,SLOT(close()));
    QObject::connect(m,SIGNAL(clicked()),this,SLOT(on_M_clicked()));
    QObject::connect(m,SIGNAL(clicked()),m,SLOT(close()));
    QObject::connect(n,SIGNAL(clicked()),this,SLOT(on_N_clicked()));
    QObject::connect(n,SIGNAL(clicked()),n,SLOT(close()));
    QObject::connect(o,SIGNAL(clicked()),this,SLOT(on_O_clicked()));
    QObject::connect(o,SIGNAL(clicked()),o,SLOT(close()));
    QObject::connect(p,SIGNAL(clicked()),this,SLOT(on_P_clicked()));
    QObject::connect(p,SIGNAL(clicked()),p,SLOT(close()));
    QObject::connect(q,SIGNAL(clicked()),this,SLOT(on_Q_clicked()));
    QObject::connect(q,SIGNAL(clicked()),q,SLOT(close()));
    QObject::connect(r,SIGNAL(clicked()),this,SLOT(on_R_clicked()));
    QObject::connect(r,SIGNAL(clicked()),r,SLOT(close()));
    QObject::connect(s,SIGNAL(clicked()),this,SLOT(on_S_clicked()));
    QObject::connect(s,SIGNAL(clicked()),s,SLOT(close()));
    QObject::connect(t,SIGNAL(clicked()),this,SLOT(on_T_clicked()));
    QObject::connect(t,SIGNAL(clicked()),t,SLOT(close()));
    QObject::connect(u,SIGNAL(clicked()),this,SLOT(on_U_clicked()));
    QObject::connect(u,SIGNAL(clicked()),u,SLOT(close()));
    QObject::connect(v,SIGNAL(clicked()),this,SLOT(on_V_clicked()));
    QObject::connect(v,SIGNAL(clicked()),v,SLOT(close()));
    QObject::connect(w,SIGNAL(clicked()),this,SLOT(on_W_clicked()));
    QObject::connect(w,SIGNAL(clicked()),w,SLOT(close()));
    QObject::connect(x,SIGNAL(clicked()),this,SLOT(on_X_clicked()));
    QObject::connect(x,SIGNAL(clicked()),x,SLOT(close()));
    QObject::connect(y,SIGNAL(clicked()),this,SLOT(on_Y_clicked()));
    QObject::connect(y,SIGNAL(clicked()),y,SLOT(close()));
    QObject::connect(z,SIGNAL(clicked()),this,SLOT(on_Z_clicked()));
    QObject::connect(z,SIGNAL(clicked()),z,SLOT(close()));
    QObject::connect(win->no,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(win->yes,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(lose->no,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(lose->yes,SIGNAL(clicked()),this,SLOT(close()));
}

void Widget::play()
{
    game->dword = game->lib->takeWordOfLang();
    connectButtons();
    makeLabel();
    QGridLayout *layout = new QGridLayout(0);
    addWidgets(layout);
    setLayout(layout);
    this->setGeometry(180,180,360,360);
    show();
}

void Widget::addWidgets(QGridLayout *layout)
{
    layout->addWidget(a,10,0);
    layout->addWidget(b,10,1);
    layout->addWidget(c,10,2);
    layout->addWidget(d,10,3);
    layout->addWidget(e);
    layout->addWidget(f);
    layout->addWidget(g);
    layout->addWidget(h);
    layout->addWidget(i);
    layout->addWidget(j);
    layout->addWidget(k);
    layout->addWidget(l);
    layout->addWidget(m);
    layout->addWidget(n);
    layout->addWidget(o);
    layout->addWidget(p);
    layout->addWidget(q);
    layout->addWidget(r);
    layout->addWidget(s);
    layout->addWidget(t);
    layout->addWidget(u);
    layout->addWidget(v);
    layout->addWidget(w);
    layout->addWidget(x);
    layout->addWidget(y);
    layout->addWidget(z);
    layout->addWidget(label,0,1);
    layout->addWidget(miss,0,5);
}

void Widget::makeLabel()
{
    game->uword->makeUserWord(*game->dword);
    label->setText(game->uword->word);
    QFont font = label->font();
    font.setPointSize(20);
    label->setFont(font);
    miss->setNum(game->man->curMisses);
}

void Widget::checkLetter()
{
    if (game->uword->checkLetter(*game->dword)==true)
    {
        game->uword->putLetter(*game->dword);
        label->setText(game->uword->word);
        if (game->uword->word == game->dword->word)
        {
            win->show();
            return;
        }
    }
    else
    {
       game->man->curMisses++;
       paintEvent(0);
       this->update();
       miss->setNum(game->man->curMisses);
       game->uword->putMistake(game->man->curMisses);
       if (game->man->curMisses == game->man->maxMisses)
       {
           lose->show();
           return;
       }
    }
}

void Widget::on_A_clicked()
{
    game->uword->letter='a';
    checkLetter();
}


void Widget::on_B_clicked()
{
    game->uword->letter='b';
    checkLetter();
}

void Widget::on_C_clicked()
{
    game->uword->letter='c';
    checkLetter();
}

void Widget::on_D_clicked()
{
    game->uword->letter='d';
    checkLetter();
}

void Widget::on_E_clicked()
{
    game->uword->letter='e';
    checkLetter();
}

void Widget::on_F_clicked()
{
    game->uword->letter='f';
    checkLetter();
}

void Widget::on_G_clicked()
{
    game->uword->letter='g';
    checkLetter();
}

void Widget::on_H_clicked()
{
    game->uword->letter='h';
    checkLetter();
}

void Widget::on_I_clicked()
{
    game->uword->letter='i';
    checkLetter();
}

void Widget::on_J_clicked()
{
    game->uword->letter='j';
    checkLetter();
}

void Widget::on_K_clicked()
{
    game->uword->letter='k';
    checkLetter();
}

void Widget::on_L_clicked()
{
    game->uword->letter='l';
    checkLetter();
}

void Widget::on_M_clicked()
{
    game->uword->letter='m';
    checkLetter();
}

void Widget::on_N_clicked()
{
    game->uword->letter='n';
    checkLetter();
}

void Widget::on_O_clicked()
{
    game->uword->letter='o';
    checkLetter();
}

void Widget::on_P_clicked()
{
    game->uword->letter='p';
    checkLetter();
}

void Widget::on_Q_clicked()
{
    game->uword->letter='q';
    checkLetter();
}

void Widget::on_R_clicked()
{
    game->uword->letter='r';
    checkLetter();
}

void Widget::on_S_clicked()
{
    game->uword->letter='s';
    checkLetter();
}

void Widget::on_T_clicked()
{
    game->uword->letter='t';
    checkLetter();
}

void Widget::on_U_clicked()
{
    game->uword->letter='u';
    checkLetter();
}

void Widget::on_V_clicked()
{
    game->uword->letter='v';
    checkLetter();
}

void Widget::on_W_clicked()
{
    game->uword->letter='w';
    checkLetter();
}

void Widget::on_X_clicked()
{
    game->uword->letter='x';
    checkLetter();
}

void Widget::on_Y_clicked()
{
    game->uword->letter='y';
    checkLetter();
}

void Widget::on_Z_clicked()
{
    game->uword->letter='z';
    checkLetter();
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPicture(0,0,game->man->createMan());
    painter.end();
}
