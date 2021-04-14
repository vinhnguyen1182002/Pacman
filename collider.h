
#ifndef pong_collider_h
#define pong_collider_h

//libraries
#include <SDL.h>

/******* COLLIDER CLASS DECLARES *******/

//collision determiner
class Collider
{
public:
    //constructor
    Collider();
    
    //coordinate accessors
    int get_x();
    int get_y();
    //dimension accessors
    int get_width();
    int get_height();
    
    //checks for collisions
    bool collided(Collider object2);
    
protected:
    //used to check for collisions
    SDL_Rect hitbox;
};





#endif
