#ifndef _Fructs_h_
#define _Fructs_h_

#include "Fruct.h"

#include <vector>

class Fructs { //������, ��������� �� �������
private:
    //vector <Fruct> Fructs2;

    int Nfructs; //����� �������
public:
    Fruct** fruct;
    std::vector<Apple>Apples;
    std::vector<Grusha>Grushes;
    Fructs (int len);
    void add (int Size1,int Size2); //
    void addApple(Apple new_apple);//�������
    void addGrusha(Grusha new_grusha);
    bool setNfructs (int new_N);
    int getNfructs ();
};

#endif
