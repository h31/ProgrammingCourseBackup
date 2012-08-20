#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "QMessageBox"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    game = new Game;
    iflose = new IfLoseWidget;
    ifwin = new IfWinWidget;
    stats = new Statistics;
    stats->readStatistics();
    st = new Stats;
    stats->setGames(stats->getGames().toDouble());
    stats->setWins(stats->getWins().toDouble());
    stats->setLoses(stats->getLoses().toDouble());
    stats->setWinPer(stats->getWinPer().toDouble());
    stats->setLosePer(stats->getLosePer().toDouble());
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Window,
    QBrush(QPixmap("C://Hangman/screen1.png")));
    this->setPalette(pal);
}



void MainWidget::connectButtons()
{
    QObject::connect(iflose->returnYes(),SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(iflose->returnNo(),SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(ifwin->returnYes(),SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(ifwin->returnNo(),SIGNAL(clicked()),this,SLOT(close()));
}

void MainWidget::play()
{
    game->dword = game->lib->takeEng();
    connectButtons();
    makeLabel();
    show();
}

void MainWidget::makeLabel()
{
    game->uword->makeUserWord(*game->dword);
    ui->word->setText(game->uword->word);
    ui->misses->setNum(game->man->curMisses);
    iflose->getLabel()->setText(game->dword->word);
}
void MainWidget::checkLetter()
{
    if (game->uword->checkLetter(*game->dword)==true)
    {
        game->uword->putLetter(*game->dword);
        ui->word->setText(game->uword->word);
        if (game->uword->word == game->dword->word)
        {
            stats->setGames(stats->getDGames()+1);
            stats->setWins(stats->getDWins()+1);
            stats->setWinPer(100/stats->getDGames()*stats->getDWins());
            stats->setLosePer(100/stats->getDGames()*stats->getDLoses());
            stats->writeStatistics();
            ifwin->show();
            return;
        }
    }
    else
    {
       game->man->curMisses++;
       paintEvent(0);
       game->uword->putMistake(game->man->curMisses);
       if (game->man->curMisses == game->man->maxMisses)
       {
           stats->setGames(stats->getDGames()+1);
           stats->setLoses(stats->getDLoses()+1);
           stats->setWinPer(100/stats->getDGames()*stats->getDWins());
           stats->setLosePer(100/stats->getDGames()*stats->getDLoses());
           stats->writeStatistics();
           ui->word->setText(game->dword->word);
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
    QPainter qp;
    QPixmap pix;
    if (game->man->curMisses==0)
        pix.load("C://Hangman/#0.png");
    if (game->man->curMisses==1)
        pix.load("C://Hangman/#1.png");
    if (game->man->curMisses==2)
        pix.load("C://Hangman/#2.png");
    if (game->man->curMisses==3)
        pix.load("C://Hangman/#3.png");
    if (game->man->curMisses==4)
        pix.load("C://Hangman/#4.png");
    if (game->man->curMisses==5)
        pix.load("C://Hangman/#5.png");
    if (game->man->curMisses==6)
        pix.load("C://Hangman/#6.png");

    qp.drawPixmap(0,0,pix);
    ui->misses->setPixmap(pix);
}


void MainWidget::on_statButton_clicked()
{
    st->returnGames()->setNum(stats->getDGames());
    st->returnWins()->setNum(stats->getDWins());
    st->returnLoses()->setNum(stats->getDLoses());
    st->returnWinPercent()->setNum(stats->getDWinPer());
    st->returnLosePercent()->setNum(stats->getDLosePer());
    st->show();
}
