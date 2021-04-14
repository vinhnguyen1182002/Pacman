//Arman Farhangi
//May 12, 2015
//BOX-MAN Game
//Standard C++ and SDL Libraries

//headers
#include "collider.h"

/******* COLLIDER CLASS DEFS *******/
//constructor
Collider::Collider()
{
    hitbox = { 0, 0, 0, 0 };
}

//get x coordinate
int Collider::get_x()
{
    return hitbox.x;
}

//get y coordinate
int Collider::get_y()
{
    return hitbox.y;
}

//get width
int Collider::get_width()
{
    return hitbox.w;
}

//get height
int Collider::get_height()
{
    return hitbox.h;
}

//check to see if objects collide (using the separate axes test)
bool Collider::collided(Collider object2)
{
    //if calling object is to the right of object 2, can't have collided
    if ( get_x() >= object2.get_x() + object2.get_width() )
        return false;
    
    //if calling object is to the left of object 2, can't have collided
    if ( get_x() <= object2.get_x() - get_width() )
        return false;
    
    //if calling object is below object 2, can't have collided
    if ( get_y() >= object2.get_y() + object2.get_height() )
        return false;
    
    //if calling object is above object 2, can't have collided
    if ( get_y() <= object2.get_y() - get_height() )
        return false;
    
    //otherwise, it must have collided
    return true;
}


