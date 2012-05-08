#ifndef _Snakelem_h_
#define _Snakelem_h_
class ZmElement {
private:
int x, y;
int napx, napy;
int dir;
public:
    ZmElement ();
    ZmElement (int X, int Y);
    ~ZmElement();
    int getx();
    int gety();
    bool setx (int new_x);
    bool sety (int new_y);
    int getnapx();
    int getnapy();
    bool set_napx(int new_napx );
    bool set_napy(int new_napy);
};

#endif
