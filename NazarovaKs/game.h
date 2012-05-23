#ifndef _game_h_
#define _game_h_

#include "field.h"
#include <stdlib.h>

class Game{
public:
	Game();
    bool checkEnd(Field& f);
};

#endif
