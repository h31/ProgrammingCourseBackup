#include "russianwidget.h"
#include "ui_russianwidget.h"
#include "QTextCodec"

RussianWidget::RussianWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RussianWidget)
{
    ui->setupUi(this);
    game = new Game;
    iflose = new RusLoseWidget;
    ifwin = new RusWinWidget;
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Window,
    QBrush(Qt::white));
    this->setPalette(pal);
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
}

void RussianWidget::checkLetter()
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
       game->uword->putMistake(game->man->curMisses);
       if (game->man->curMisses == game->man->maxMisses)
       {
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
    game->uword->letter='à';
    checkLetter();
}

void RussianWidget::on_pushButton_2_clicked()
{
    game->uword->letter='á';
    checkLetter();
}

void RussianWidget::on_pushButton_3_clicked()
{
    game->uword->letter='â';
    checkLetter();
}

void RussianWidget::on_pushButton_4_clicked()
{
    game->uword->letter='ã';
    checkLetter();
}

void RussianWidget::on_pushButton_5_clicked()
{
    game->uword->letter='ä';
    checkLetter();
}

void RussianWidget::on_pushButton_6_clicked()
{
    game->uword->letter='å';
    checkLetter();
}

void RussianWidget::on_pushButton_7_clicked()
{
    game->uword->letter='æ';
    checkLetter();
}

void RussianWidget::on_pushButton_8_clicked()
{
    game->uword->letter='ç';
    checkLetter();
}

void RussianWidget::on_pushButton_9_clicked()
{
    game->uword->letter='è';
    checkLetter();
}

void RussianWidget::on_pushButton_10_clicked()
{
    game->uword->letter='é';
    checkLetter();
}

void RussianWidget::on_pushButton_11_clicked()
{
    game->uword->letter='ê';
    checkLetter();
}

void RussianWidget::on_pushButton_12_clicked()
{
    game->uword->letter='ë';
    checkLetter();
}

void RussianWidget::on_pushButton_13_clicked()
{
    game->uword->letter='ì';
    checkLetter();
}

void RussianWidget::on_pushButton_14_clicked()
{
    game->uword->letter='í';
    checkLetter();
}

void RussianWidget::on_pushButton_15_clicked()
{
    game->uword->letter='î';
    checkLetter();
}

void RussianWidget::on_pushButton_16_clicked()
{
    game->uword->letter='ï';
    checkLetter();
}

void RussianWidget::on_pushButton_24_clicked()
{
    game->uword->letter='ð';
    checkLetter();
}

void RussianWidget::on_pushButton_23_clicked()
{
    game->uword->letter='ñ';
    checkLetter();
}

void RussianWidget::on_pushButton_22_clicked()
{
    game->uword->letter='ò';
    checkLetter();
}

void RussianWidget::on_pushButton_21_clicked()
{
    game->uword->letter='ó';
    checkLetter();
}

void RussianWidget::on_pushButton_20_clicked()
{
    game->uword->letter='ô';
    checkLetter();
}

void RussianWidget::on_pushButton_19_clicked()
{
    game->uword->letter='õ';
    checkLetter();
}

void RussianWidget::on_pushButton_18_clicked()
{
    game->uword->letter='ö';
    checkLetter();
}

void RussianWidget::on_pushButton_17_clicked()
{
    game->uword->letter='÷';
    checkLetter();
}

void RussianWidget::on_pushButton_32_clicked()
{
    game->uword->letter='ø';
    checkLetter();
}

void RussianWidget::on_pushButton_31_clicked()
{
    game->uword->letter='ù';
    checkLetter();
}

void RussianWidget::on_pushButton_30_clicked()
{
    game->uword->letter='ú';
    checkLetter();
}

void RussianWidget::on_pushButton_29_clicked()
{
    game->uword->letter='û';
    checkLetter();
}

void RussianWidget::on_pushButton_28_clicked()
{
    game->uword->letter='ü';
    checkLetter();
}

void RussianWidget::on_pushButton_27_clicked()
{
    game->uword->letter='ý';
    checkLetter();
}

void RussianWidget::on_pushButton_26_clicked()
{
    game->uword->letter='þ';
    checkLetter();
}

void RussianWidget::on_pushButton_25_clicked()
{
    game->uword->letter='ÿ';
    checkLetter();
}

void RussianWidget::paintEvent(QPaintEvent *event)
{
    QPainter qp;
    QPixmap pix;
    if (game->man->curMisses==0)
        pix.load("C://QtProjects/Hangman-0-3/#0.png");
    if (game->man->curMisses==1)
        pix.load("C://QtProjects/Hangman-0-3/#1.png");
    if (game->man->curMisses==2)
        pix.load("C://QtProjects/Hangman-0-3/#2.png");
    if (game->man->curMisses==3)
        pix.load("C://QtProjects/Hangman-0-3/#3.png");
    if (game->man->curMisses==4)
        pix.load("C://QtProjects/Hangman-0-3/#4.png");
    if (game->man->curMisses==5)
        pix.load("C://QtProjects/Hangman-0-3/#5.png");
    if (game->man->curMisses==6)
        pix.load("C://QtProjects/Hangman-0-3/#6.png");
    qp.drawPixmap(0,0,pix);
    ui->misses->setPixmap(pix);
}
