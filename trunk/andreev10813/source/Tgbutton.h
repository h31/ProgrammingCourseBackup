#ifndef TGBUTTON_H
 #define TGBUTTON_H

#include <QPushButton>

class TGbutton : public QPushButton
 {
 int a,b;
 public:
 TGbutton();
 void setAB(int a,int b);
 void GetAB(int & a,int & b);

};

#endif // TGBUTTON_H
