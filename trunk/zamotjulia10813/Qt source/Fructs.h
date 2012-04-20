#ifndef _Fructs_h_
#define _Fructs_h_

#include "Fruct.h"

#include <vector>

class Fructs { //Фрукты, состоящие из фруктов
private:
    int numberfructs; //число фруктов
public:
    Fruct** fruct;
    std::vector<Fruct*>Apples;
    std::vector<Fruct*>Grushes;
    Fructs (int len);
    bool set_numberfructs (int new_numberfructs);
    int get_numberfructs ();
    void add (int size1,int size2); //
    void addApple(Apple *new_apple);//вручную
    void addPear(Pear *new_pear);

};

#endif
