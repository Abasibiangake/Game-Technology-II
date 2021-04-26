 #include "Food.h"

Food::Food()
{

}

Food::~Food()
{

}

// initialise food characteristics
void Food::init(int width, int height)
{
    _xorigin = rand() % (WIDTH - 2) + 1; // randomise x initial direction.
    _yorigin = rand() % (HEIGHT - 2) + 1; // randomise y initial direction
    _x = width;
    _y = height;
}
 
void Food::drawonlcd(N5110 &lcd)
{
    // x origin, y origin, rows, cols, fill type
    lcd.drawRect(_xorigin,_yorigin,_x,_y,FILL_BLACK);

}

int Food::get_pos_x()
{
    return _xorigin;
}

int Food::get_pos_y()
{
    return _yorigin;
}

void Food::update(int newfood_x, int newfood_y)
{
    _xorigin = newfood_x;
    _yorigin = newfood_y;
}