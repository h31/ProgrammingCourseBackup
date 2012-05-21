#include "Tgbutton.h"

TGbutton::TGbutton():QPushButton()
 {
 }
 void TGbutton::GetAB(int & c,int & d)
 {
 c=a;
 d=b;
 }

void TGbutton::setAB(int c,int d)
 {
 a=c;
 b=d;
 }
