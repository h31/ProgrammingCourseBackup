#include "russianwidget.h"
#include "ui_russianwidget.h"
#include "QTextCodec"
#include "QMessageBox"

RussianWidget::RussianWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RussianWidget)
{
    ui->setupUi(this);
    game = new Game;
    iflose = new RusLoseWidget;
    ifwin = new RusWinWidget;
    stats = new Statistics;
    stats->readStatistics();
    st = new RusStat;
    stats->setGames(stats->getGames().toDouble());
    stats->setWins(stats->getWins().toDouble());
    stats->setLoses(stats->getLoses().toDouble());
    stats->setWinPer(stats->getWinPer().toDouble());
    stats->setLosePer(stats->getLosePer().toDouble());
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Window,
    QBrush(QPixmap("C://Hangman/screen1.png")));
    this->setPalette(pal);
    QPalette qpal = ui->pushButton->palette();
    qpal.setBrush(QPalette::Button,QBrush(Qt::white));
    ui->pushButton->setPalette(qpal);
    QTextCodec::setCodecForCStrings(
    QTextCodec::codecForName(
    "Windows-1251"));
}

void RussianWidget::connectButtons()
{
    QObject::connect(iflose->returnYes(),SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(iflose->returnNo(),SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(ifwin->returnYes(),SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(ifwin->returnNo(),SIGNAL(clicked()),this,SLOT(close()));
}


void RussianWidget::play()
{
    game->dword = game->lib->takeRus();
    connectButtons();
    makeLabel();
    show();
}

void RussianWidget::makeLabel()
{
    game->uword->makeUserWord(*game->dword);
    ui->word->setText(game->uword->word);
    ui->misses->setNum(game->man->curMisses);
    iflose->getLabel()->setText(game->dword->word);
}

void RussianWidget::checkLetter()
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

RussianWidget::~RussianWidget()
{
    delete ui;
}

void RussianWidget::on_pushButton_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_2_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_3_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_4_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_5_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_6_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_7_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_8_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_9_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_10_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_11_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_12_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_13_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_14_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_15_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_16_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_24_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_23_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_22_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_21_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_20_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_19_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_18_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_17_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_32_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_31_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_30_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_29_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_28_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_27_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_26_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::on_pushButton_25_clicked()
{
    game->uword->letter='�';
    checkLetter();
}

void RussianWidget::paintEvent(QPaintEvent *event)
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

void RussianWidget::on_statButton_clicked()
{
    st->returnGames()->setNum(stats->getDGames());
    st->returnWins()->setNum(stats->getDWins());
    st->returnLoses()->setNum(stats->getDLoses());
    st->returnWinPercent()->setNum(stats->getDWinPer());
    st->returnLosePercent()->setNum(stats->getDLosePer());
    st->show();
}
