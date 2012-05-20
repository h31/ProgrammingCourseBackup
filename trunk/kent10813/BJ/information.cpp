#include "information.h"
#include "ui_information.h"

information::information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::information)
{
    ui->setupUi(this);

  //  new_game= new want_to_play;
    dlr_cards= new dealer_cards;

  //  QMessageBox::information(this,"",p.qw());


//   window->game->playerScore();
    who_won();
  //  ui->label->setNum(new_game->dialog->wn->game->playerScore());
    //ui->label_4->setNum(p.qw());
    connect(dlr_cards,SIGNAL(mySignal(int)),ui->label_4,SLOT(setNum(int)));
}

information::~information()
{
    delete ui;
}

void information::on_pushButton_clicked()
{
  /*  play_again  *play= new play_again;
    play->show();
    this->close();*/
}
void information::who_won()
{

}

int information::dlrScore()
{
   return 0;
}
