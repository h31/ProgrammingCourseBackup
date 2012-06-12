#include "test.h"

bool Test::proverkaFieldIgrok()//для танка
{

    t.koords.x=34;
    t.koords.y=56;
    if ((t.koords.y-t.r<t.field.y1)||(t.koords.y+t.r>t.field.y2)||
        (t.koords.x-t.r<t.field.x1)||(t.koords.x+t.r>t.field.x2))
    {
        cout << "#1.Proverka ne proidena!"<<endl;
        //QMessageBox::information(this, "#1.Proverka ne proidena!", "#1.Proverka ne proidena!");
        exit(0);
        return false;
    }
    else
        return true;
}
bool Test::proverkaFieldBot()
{
    bott.koordsb.x=0;
    bott.koordsb.y=0;
    if ((bott.koordsb.x-bott.r<t.field.x1)||(bott.koordsb.y-bott.r-bott.speedb<t.field.y1)||
        (bott.koordsb.x+bott.r+bott.speedb>t.field.x2)||(bott.koordsb.y+bott.r>t.field.y2))
    {
         //
        cout << "#2.Proverka ne proidena!"<<endl;
        //QMessageBox::information(this, "#2.Proverka ne proidena!", "#2.Proverka ne proidena!");
        exit(0);
        return false;
    }
    else
        return true;
}


