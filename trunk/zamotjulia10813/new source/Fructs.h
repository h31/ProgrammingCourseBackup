#ifndef _Fructs_h_
#define _Fructs_h_

#include "Fruct.h"

#include <vector>

class Fructs { //������, ��������� �� �������
private:
    int numberfructs; //����� �������
public:
    Fruct** fruct;
    std::vector<Fruct*>Apples;
    std::vector<Fruct*>Grushes;
    Fructs (int len);
    bool set_numberfructs (int new_numberfructs);
    int get_numberfructs ();
    void add (int size1,int size2); //
    void addApple(Apple *new_apple);//�������
    void addPear(Pear *new_pear);

};

#endif
