
#include "field.h"


int main()
{
	Field f(7, 5); //Не работает конструктор по умолчанию и конструктор присваивания со значениями (7, любое число)
	f.createField();

	cout<<f;
	
	return 0;
}