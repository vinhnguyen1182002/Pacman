
#ifndef pacman_tile_h
#define pacman_tile_h

//libraries
#include <SDL.h>
//headers
#include "globals.h"
#include "collider.h"

/******* TILE CLASS DECLARES *******/
//obstacle or non-obstacle tile clip
class Tile : public Collider
{
public:
    //constructor
    Tile(int obstacle_state, int x_tile, int y_tile);
    
    //accessors
    SDL_Rect& get_clip();
    bool get_state();
    
private:
    //clip to render tile
    SDL_Rect clip;
    //obstacle state
    bool obstacle_state;
};

#endif
