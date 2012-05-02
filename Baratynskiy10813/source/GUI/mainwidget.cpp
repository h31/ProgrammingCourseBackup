#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    game = new Game;
    iflose = new IfLoseWidget;
    ifwin = new IfWinWidget;
}

void MainWidget::connectButtons()
{
    QObject::connect(ui->a,SIGNAL(clicked()),this,SLOT(on_a_clicked()));
    QObject::connect(ui->b,SIGNAL(clicked()),this,SLOT(on_b_clicked()));
    QObject::connect(ui->c,SIGNAL(clicked()),this,SLOT(on_c_clicked()));
    QObject::connect(ui->d,SIGNAL(clicked()),this,SLOT(on_d_clicked()));
    QObject::connect(ui->e,SIGNAL(clicked()),this,SLOT(on_e_clicked()));
    QObject::connect(ui->f,SIGNAL(clicked()),this,SLOT(on_f_clicked()));
    QObject::connect(ui->g,SIGNAL(clicked()),this,SLOT(on_g_clicked()));
    QObject::connect(ui->h,SIGNAL(clicked()),this,SLOT(on_h_clicked()));
    QObject::connect(ui->i,SIGNAL(clicked()),this,SLOT(on_i_clicked()));
    QObject::connect(ui->j,SIGNAL(clicked()),this,SLOT(on_j_clicked()));
    QObject::connect(ui->k,SIGNAL(clicked()),this,SLOT(on_k_clicked()));
    QObject::connect(ui->l,SIGNAL(clicked()),this,SLOT(on_l_clicked()));
    QObject::connect(ui->m,SIGNAL(clicked()),this,SLOT(on_m_clicked()));
    QObject::connect(ui->n,SIGNAL(clicked()),this,SLOT(on_n_clicked()));
    QObject::connect(ui->o,SIGNAL(clicked()),this,SLOT(on_o_clicked()));
    QObject::connect(ui->p,SIGNAL(clicked()),this,SLOT(on_p_clicked()));
    QObject::connect(ui->q,SIGNAL(clicked()),this,SLOT(on_q_clicked()));
    QObject::connect(ui->r,SIGNAL(clicked()),this,SLOT(on_r_clicked()));
    QObject::connect(ui->s,SIGNAL(clicked()),this,SLOT(on_s_clicked()));
    QObject::connect(ui->t,SIGNAL(clicked()),this,SLOT(on_t_clicked()));
    QObject::connect(ui->u,SIGNAL(clicked()),this,SLOT(on_u_clicked()));
    QObject::connect(ui->v,SIGNAL(clicked()),this,SLOT(on_v_clicked()));
    QObject::connect(ui->w,SIGNAL(clicked()),this,SLOT(on_w_clicked()));
    QObject::connect(ui->x,SIGNAL(clicked()),this,SLOT(on_x_clicked()));
    QObject::connect(ui->y,SIGNAL(clicked()),this,SLOT(on_y_clicked()));
    QObject::connect(ui->z,SIGNAL(clicked()),this,SLOT(on_z_clicked()));
    QObject::connect(iflose->returnYes(),SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(iflose->returnNo(),SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(ifwin->returnYes(),SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(ifwin->returnNo(),SIGNAL(clicked()),this,SLOT(close()));
}
void MainWidget::play()
{
    game->dword = game->lib->takeWordOfLang();
    connectButtons();
    makeLabel();
    show();
}

void MainWidget::makeLabel()
{
    game->uword->makeUserWord(*game->dword);
    ui->word->setText(game->uword->word);
    ui->misses->setNum(game->man->curMisses);
}
void MainWidget::checkLetter()
{
    if (game->uword->checkLetter(*game->dword)==true)
    {
        game->uword->putLetter(*game->dword);
        ui->word->setText(game->uword->word);
        if (game->uword->word == game->dword->word)
        {
            ifwin->show();
            return;
        }
    }
    else
    {
       game->man->curMisses++;
       paintEvent(0);
       this->update();
       ui->misses->setNum(game->man->curMisses);
       game->uword->putMistake(game->man->curMisses);
       if (game->man->curMisses == game->man->maxMisses)
       {
           iflose->show();
           return;
       }
    }
}
MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_a_clicked()
{
    game->uword->letter='a';
    checkLetter();
}

void MainWidget::on_b_clicked()
{
    game->uword->letter='b';
    checkLetter();
}

void MainWidget::on_c_clicked()
{
    game->uword->letter='c';
    checkLetter();
}

void MainWidget::on_d_clicked()
{
    game->uword->letter='d';
    checkLetter();
}

void MainWidget::on_e_clicked()
{
    game->uword->letter='e';
    checkLetter();
}

void MainWidget::on_f_clicked()
{
    game->uword->letter='f';
    checkLetter();
}

void MainWidget::on_g_clicked()
{
    game->uword->letter='g';
    checkLetter();
}

void MainWidget::on_h_clicked()
{
    game->uword->letter='h';
    checkLetter();
}

void MainWidget::on_i_clicked()
{
    game->uword->letter='i';
    checkLetter();
}

void MainWidget::on_j_clicked()
{
    game->uword->letter='j';
    checkLetter();
}

void MainWidget::on_k_clicked()
{
    game->uword->letter='k';
    checkLetter();
}

void MainWidget::on_l_clicked()
{
    game->uword->letter='l';
    checkLetter();
}

void MainWidget::on_m_clicked()
{
    game->uword->letter='m';
    checkLetter();
}

void MainWidget::on_n_clicked()
{
    game->uword->letter='n';
    checkLetter();
}

void MainWidget::on_o_clicked()
{
    game->uword->letter='o';
    checkLetter();
}

void MainWidget::on_p_clicked()
{
    game->uword->letter='p';
    checkLetter();
}

void MainWidget::on_q_clicked()
{
    game->uword->letter='q';
    checkLetter();
}

void MainWidget::on_r_clicked()
{
    game->uword->letter='r';
    checkLetter();
}

void MainWidget::on_s_clicked()
{
    game->uword->letter='s';
    checkLetter();
}

void MainWidget::on_t_clicked()
{
    game->uword->letter='t';
    checkLetter();
}

void MainWidget::on_u_clicked()
{
    game->uword->letter='u';
    checkLetter();
}

void MainWidget::on_v_clicked()
{
    game->uword->letter='v';
    checkLetter();
}

void MainWidget::on_w_clicked()
{
    game->uword->letter='w';
    checkLetter();
}

void MainWidget::on_x_clicked()
{
    game->uword->letter='x';
    checkLetter();
}

void MainWidget::on_y_clicked()
{
    game->uword->letter='y';
    checkLetter();
}

void MainWidget::on_z_clicked()
{
    game->uword->letter='z';
    checkLetter();
}

void MainWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPicture(0,0,game->man->createMan());
    painter.end();
}
