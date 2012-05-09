#include "Dialog.h"

void dialog::setName()
{
	cout<<"Введите ваше имя: ";
}
void dialog::setBet()
{
	cout<<"Введите ставку: ";
}
void dialog::playerShow()
{
	cout<<"Ваши карты:"<<endl;
}
void dialog::moreOrStop()
{
	cout<<"Если взять еще, нажмите 1, если хватит -любую клавишу"<<endl;
}
void dialog::dealerShow()
{
	cout<<"Карты дилера: "<<endl;
}
void dialog::dealerName()
{
	cout<<"Dealer"<<endl;
}
void dialog::dealerMakeBet()
{
	cout<<"Дилер сравнивает. Его ставка: ";
}
void dialog::playerScore()
{
	cout<<"Ваш счет: ";
}
void dialog::dealerScore()
{
	cout<<"Счет дилера: ";
}
void dialog::prize()
{
	cout<<"Банк: ";
}
void dialog::isplayerWon()
{
	cout<<"Вы выиграли.";
}
void dialog::isDealerWon()
{
	cout<<"Дилер выиграл. ";
}
void dialog::isDraw()
{
	cout<<"Ничья.";
}
void dialog::wrongBet()
{
	cout<<"Вы ввели запрещенную ставку, сделайте новую ставку "<<endl;
}