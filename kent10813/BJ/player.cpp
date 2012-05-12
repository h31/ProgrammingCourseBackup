#include "player.h"

player::player()
{
	hand.clear();
}

void player::enterName(QString name)
{
   plname=name;
}
int player::makeBets(int bets)
{
    bet=bets;
	return bet;
}
void player::takeCards()
{
	mydeck.create_deck();
	hand.push_back(mydeck.pull_card());
}
void player::show(QPainter &painter)
{


    const int CARD_INITIAL_X =15;
    const int CARD_INITIAL_Y =15;

    QPixmap cardpicture;
    for (unsigned i=0; i<hand.size(); i++)
    {
    //	cout<<hand[i].get_score()<<" "<<hand[i].get_suit()<<endl;

        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="2")
        {
            cardpicture.load("../BJ/images/twodiamonds.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);

        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="3")
        {
            cardpicture.load("../BJ/images/threediamonds.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="4")
        {
            cardpicture.load("../BJ/images/fourdiamonds.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="5")
        {
            cardpicture.load("../BJ/images/fivediamonds.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="6")
        {
            cardpicture.load("../BJ/images/sixdiamonds.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="7")
        {
            cardpicture.load("../BJ/images/sevendiamonds.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="8")
        {
            cardpicture.load("../BJ/images/eightdiamonds.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="9")
        {
            cardpicture.load("../BJ/images/ninediamonds.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="10")
        {
            cardpicture.load("../BJ/images/tendiamonds.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="J")
        {
            cardpicture.load("../BJ/images/jackdiamonds.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="Q")
        {
            cardpicture.load("../BJ/images/queendiamonds.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="K")
        {
            cardpicture.load("../BJ/images/kingdiamonds.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="A")
        {
            cardpicture.load("../BJ/images/acediamonds.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="2")
        {
            cardpicture.load("../BJ/images/twohearts.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="3")
        {
            cardpicture.load("../BJ/images/threehearts.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="4")
        {
            cardpicture.load("../BJ/images/fourhearts.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="5")
        {
            cardpicture.load("../BJ/images/fivehearts.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="6")
        {
            cardpicture.load("../BJ/images/sixhearts.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="7")
        {
            cardpicture.load("../BJ/images/sevenhearts.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="8")
        {
            cardpicture.load("../BJ/images/eighthearts.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="9")
        {
            cardpicture.load("../BJ/images/ninehearts.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="10")
        {
            cardpicture.load("../BJ/images/tenhearts.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="J")
        {
            cardpicture.load("../BJ/images/jackhearts.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="Q")
        {
            cardpicture.load("../BJ/images/queenhearts.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="K")
        {
            cardpicture.load("../BJ/images/kinghearts.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="A")
        {
            cardpicture.load("../BJ/images/acehearts.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="2")
        {
            cardpicture.load("../BJ/images/twoclubs.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="3")
        {
            cardpicture.load("../BJ/images/threeclubs.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="4")
        {
            cardpicture.load("../BJ/images/fourclubs.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="5")
        {
            cardpicture.load("../BJ/images/fiveclubs.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="6")
        {
            cardpicture.load("../BJ/images/sixclubs.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="7")
        {
            cardpicture.load("../BJ/images/sevenclubs.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="8")
        {
            cardpicture.load("../BJ/images/eightclubs.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="9")
        {
            cardpicture.load("../BJ/images/nineclubs.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="10")
        {
            cardpicture.load("../BJ/images/tenclubs.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="J")
        {
            cardpicture.load("../BJ/images/jackclubs.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="Q")
        {
            cardpicture.load("../BJ/images/queenclubs.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="K")
        {
            cardpicture.load("../BJ/images/kingclubs.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="A")
        {
            cardpicture.load("../BJ/images/aceclubs.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="2")
        {
            cardpicture.load("../BJ/images/twospades.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="3")
        {
            cardpicture.load("../BJ/images/treespades.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="4")
        {
            cardpicture.load("../BJ/images/fourspades.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="5")
        {
            cardpicture.load("../BJ/images/fivespades.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="6")
        {
            cardpicture.load("../BJ/images/sixspades.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="7")
        {
            cardpicture.load("../BJ/images/sevenspades.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="8")
        {
            cardpicture.load("../BJ/images/eightspades.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="9")
        {
            cardpicture.load("../BJ/images/ninespades.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="10")
        {
            cardpicture.load("../BJ/images/tenspades.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="J")
        {
            cardpicture.load("../BJ/images/jackspades.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="Q")
        {
            cardpicture.load("../BJ/images/queenspades.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="K")
        {
            cardpicture.load("../BJ/images/kingspades.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="A")
        {
            cardpicture.load("../BJ/images/acespades.png");
            painter.drawPixmap(10+i*CARD_INITIAL_X,CARD_INITIAL_Y,cardpicture);
        }
    }
}
int player::countScore()
{
	score=0;
	for (int i=0; i<hand.size(); i++)
	{
		if (hand[i].get_score()=="2")
			score+=2;
		if (hand[i].get_score()=="3")
			score+=3;
		if (hand[i].get_score()=="4")
			score+=4;
		if (hand[i].get_score()=="5")
			score+=5;
		if (hand[i].get_score()=="6")
			score+=6;
		if (hand[i].get_score()=="7")
			score+=7;
		if (hand[i].get_score()=="8")
			score+=8;
		if (hand[i].get_score()=="9")
			score+=9;
		if (hand[i].get_score()=="10")
			score+=10;
		if (hand[i].get_score()=="J")
			score+=10;
		if (hand[i].get_score()=="Q")
			score+=10;
		if (hand[i].get_score()=="K")
			score+=10;
		if (hand[i].get_score()=="A")
			score+=11;
	
	}

	return score;
}
