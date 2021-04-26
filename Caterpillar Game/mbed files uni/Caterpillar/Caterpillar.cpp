#include "Caterpillar.h"

Caterpillar::Caterpillar()
{

}

Caterpillar::~Caterpillar()
{

}
void Caterpillar::init(int height,int width)
{
    _x = WIDTH/2 - width/2;  // x depends on the width of the screen and the weight of the caterpillar
    _y = HEIGHT/2 - height/2;  // y depends on height of screen and height of caterpillar
    _height1 = height;
    _width1 = width;
    _speed = 4;  // default speed
    _score = 0;  // start score from zero
    
}
void Caterpillar::drawonlcd(N5110 &lcd)
{
    // draw caterpillar in screen buffer. 
    lcd.drawRect(_x,_y,_width,_height,FILL_BLACK);

}

void Caterpillar::updateonlcd(Direction d,float mag)
{
    _speed = int(mag*10.0f);  // scale is arbitrary, could be changed in future
    // update y value depending on direction of movement
    // North is decrement as origin is at the top-left so decreasing moves up
    // If it moves vertically, keep its initial height and width.
    if (d == N) {
        _y-=_speed;
        _height = _height1;
        _width = _width1;
    } else if (d == S) {
        _y+=_speed;
        _height = _height1;
        _width = _width1;
    }
    
    //update the x value according to the direction of movement
    //If the direction is towards the west, its speed should decrement because its moving left
    // If its moving along the horizon, update the new height and width of caterpillar.
    if (d == W) {
        _x-=_speed;
        // switch height and weight of the caterpillar to cause the caterpillar to move when direction is in the west(horizontal).
        _height = _width1;
        _width = _height1;
    } else if (d == E) {  // if its going to towards the east
    // switch height and weight of the caterpillar to cause the caterpillar to move when direction is in the east(horizontal)
        _x+=_speed;
        _height = _width1;
        _width = _height1;
    }

    // check the y origin to ensure that the caterpillar doesn't go off screen
    if (_y < 1) {
        _y = 1;
    }
    if (_y > HEIGHT - _height - 1) {
        _y = HEIGHT - _height - 1;
    }
    // check the x origin to ensure the caterpillardoesnt go off the screen
    if (_x < 1) {
        _x = 1;
    }
    if (_x > WIDTH - _width - 1) {
        _x = WIDTH - _width - 1;
    }
   
}
void Caterpillar::add_score()
{
    _score++;
}
void Caterpillar::subtract_score()
{
    _score--;
}
int Caterpillar::get_score()
{
    return _score;
}


Vector2D Caterpillar::get_pos() {
    Vector2D c = {_x,_y};
    return c;    
}
