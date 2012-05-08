#ifndef _Fructs_h_
#define _Fructs_h_

#include "Fruct.h"

#include <vector>

class Fructs { //Фрукты, состоящие из фруктов
private:
    int numberfructs; //число фруктов
	
public:
	std::vector<Fruct*>Fruits; //в public для сохранения свойств (нужно получать размер и т.п., а не только сам элемент)
    Fructs (int len);
	Fructs();
    bool set_numberfructs (int new_numberfructs);
    int get_numberfructs ();
    void add (int size1,int size2); //случайное добавление фруктов
    void addApple(Apple *new_apple);//вручную добавляем
    void addPear(Pear *new_pear);
	bool deleteFruct(int number);
};

#endif
