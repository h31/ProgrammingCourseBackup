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
    QPixmap cardpicture;
    for (unsigned i=0; i<hand.size(); i++)
    {
    //	cout<<hand[i].get_score()<<" "<<hand[i].get_suit()<<endl;

        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="2")
        {
            cardpicture.load("C:/QtProjects/BJ/images/twodiamonds.png");
            painter.drawPixmap(i,0,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="3")
        {
            cardpicture.load("C:/QtProjects/BJ/images/threediamonds.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="4")
        {
            cardpicture.load("C:/QtProjects/BJ/images/fourdiamonds.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="5")
        {
            cardpicture.load("C:/QtProjects/BJ/images/fivediamonds.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="6")
        {
            cardpicture.load("C:/QtProjects/BJ/images/sixdiamonds.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="7")
        {
            cardpicture.load("C:/QtProjects/BJ/images/sevendiamonds.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="8")
        {
            cardpicture.load("C:/QtProjects/BJ/images/eightdiamonds.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="9")
        {
            cardpicture.load("C:/QtProjects/BJ/images/ninediamonds.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="10")
        {
            cardpicture.load("C:/QtProjects/BJ/images/tendiamonds.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="J")
        {
            cardpicture.load("C:/QtProjects/BJ/images/jackdiamonds.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="Q")
        {
            cardpicture.load("C:/QtProjects/BJ/images/queendiamonds.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="K")
        {
            cardpicture.load("C:/QtProjects/BJ/images/kingdiamonds.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Diamonds"&&hand[i].get_score()=="A")
        {
            cardpicture.load("C:/QtProjects/BJ/images/acediamonds.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="2")
        {
            cardpicture.load("C:/QtProjects/BJ/images/twohearts.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="3")
        {
            cardpicture.load("C:/QtProjects/BJ/images/threehearts.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="4")
        {
            cardpicture.load("C:/QtProjects/BJ/images/fourhearts.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="5")
        {
            cardpicture.load("C:/QtProjects/BJ/images/fivehearts.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="6")
        {
            cardpicture.load("C:/QtProjects/BJ/images/sixhearts.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="7")
        {
            cardpicture.load("C:/QtProjects/BJ/images/sevenhearts.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="8")
        {
            cardpicture.load("C:/QtProjects/BJ/images/eighthearts.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="9")
        {
            cardpicture.load("C:/QtProjects/BJ/images/ninehearts.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="10")
        {
            cardpicture.load("C:/QtProjects/BJ/images/tenhearts.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="J")
        {
            cardpicture.load("C:/QtProjects/BJ/images/jackhearts.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="Q")
        {
            cardpicture.load("C:/QtProjects/BJ/images/queenhearts.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="K")
        {
            cardpicture.load("C:/QtProjects/BJ/images/kinghearts.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Hearts"&&hand[i].get_score()=="A")
        {
            cardpicture.load("C:/QtProjects/BJ/images/acehearts.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="2")
        {
            cardpicture.load("C:/QtProjects/BJ/images/twoclubs.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="3")
        {
            cardpicture.load("C:/QtProjects/BJ/images/threeclubs.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="4")
        {
            cardpicture.load("C:/QtProjects/BJ/images/fourclubs.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="5")
        {
            cardpicture.load("C:/QtProjects/BJ/images/fiveclubs.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="6")
        {
            cardpicture.load("C:/QtProjects/BJ/images/sixclubs.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="7")
        {
            cardpicture.load("C:/QtProjects/BJ/images/sevenclubs.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="8")
        {
            cardpicture.load("C:/QtProjects/BJ/images/eightclubs.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="9")
        {
            cardpicture.load("C:/QtProjects/BJ/images/nineclubs.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="10")
        {
            cardpicture.load("C:/QtProjects/BJ/images/tenclubs.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="J")
        {
            cardpicture.load("C:/QtProjects/BJ/images/jackclubs.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="Q")
        {
            cardpicture.load("C:/QtProjects/BJ/images/queenclubs.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="K")
        {
            cardpicture.load("C:/QtProjects/BJ/images/kingclubs.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Clubs"&&hand[i].get_score()=="A")
        {
            cardpicture.load("C:/QtProjects/BJ/images/aceclubs.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="2")
        {
            cardpicture.load("C:/QtProjects/BJ/images/twospades.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="3")
        {
            cardpicture.load("C:/QtProjects/BJ/images/treespades.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="4")
        {
            cardpicture.load("C:/QtProjects/BJ/images/fourspades.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="5")
        {
            cardpicture.load("C:/QtProjects/BJ/images/fivespades.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="6")
        {
            cardpicture.load("C:/QtProjects/BJ/images/sixspades.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="7")
        {
            cardpicture.load("C:/QtProjects/BJ/images/sevenspades.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="8")
        {
            cardpicture.load("C:/QtProjects/BJ/images/eightspades.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="9")
        {
            cardpicture.load("C:/QtProjects/BJ/images/ninespades.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="10")
        {
            cardpicture.load("C:/QtProjects/BJ/images/tenspades.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="J")
        {
            cardpicture.load("C:/QtProjects/BJ/images/jackspades.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="Q")
        {
            cardpicture.load("C:/QtProjects/BJ/images/queenspades.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="K")
        {
            cardpicture.load("C:/QtProjects/BJ/images/kingspades.png");
            painter.drawPixmap(10,10,cardpicture);
        }
        if (hand[i].get_suit()=="Spades"&&hand[i].get_score()=="A")
        {
            cardpicture.load("C:/QtProjects/BJ/images/acespades.png");
            painter.drawPixmap(10,10,cardpicture);
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
