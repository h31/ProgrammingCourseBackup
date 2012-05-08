#ifndef _Field_h_
#define _Field_h_

#include <stdlib.h>
#include "Fructs.h"

class Field {
private:
    int** field;
    int width, height;
public:
    Field (int W, int H);
    Field ();
    ~Field ();
    bool set_field (int x, int y, int new_value); //дл€ изменени€ €чейки пол€
    int get_field (int x, int y); //получить €чейку
    int get_width ();
    bool set_width (int new_width);
    int get_height();
    bool set_height (int new_height);
    bool createField ();
    void init ();
    bool resize(int size1, int size2);
};

#endif
