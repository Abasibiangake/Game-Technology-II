#include "Enemy.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void Enemy::init(int radius1)
{
    _radius = radius1;
    srand(time(NULL));
    
    x1 = 3 ;
    y1 = 3;
    speed = 1;
    int movement = rand() % 7;
    
    // determine velocity of enemy at random movement
    if (movement == 0) {
        _v.y = speed;
    } else if (movement == 1) {
        _v.y = speed;
    } else if (movement == 2) {
        _v.y = speed;
    } else if (movement == 3) {
        _v.y = speed;
    }else if (movement == 4) {
        _v.y = speed;
    }else if (movement == 5) {
        _v.y = speed;
    }else if (movement == 6) {
        _v.y = speed;
    }
}

void Enemy::draw(N5110 &lcd)
{
    // x origin, y origin, rows, cols, sprite
    lcd.drawCircle(x1, y1, _radius, FILL_BLACK);
}

// update the increasing position of y to the velocity of enemy
void Enemy::update() {
   
    y1 += _v.y; 

    if ( y1 < 40 ) {
        y1++; //run down 
          
        }else {
            x1 += 5; //increment x value to cause the enemy to move around the screen.  
            y1 = 3; // change y value back to start
    }
    if (x1 > 80) {
        x1 = 3;
    }

}

void Enemy::set_the_velocity(Vector2D v){
    _v.y = v.y;
}
Vector2D Enemy::get_the_velocity()
{
    Vector2D v = {_v.y};
    return v;
}
Vector2D Enemy::get_position()
{
    Vector2D p = { y1, x1 };
    return p;
}

void Enemy::set_position(Vector2D p)
{
    y1 = p.y;
    x1 = p.x;
}
