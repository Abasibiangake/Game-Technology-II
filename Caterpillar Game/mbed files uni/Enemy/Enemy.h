#ifndef ENEMY_H
#define ENEMY_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"


/** Enemy Class
 * @brief Class for getting the attribute of the Caterpillar's Enemy.
 * @author James, Abasibiangake.
 * @date May 2019.
 */
class Enemy
{
public:
    /** Constructor */
    Enemy();
    
    /** Destructor */
    ~Enemy();
    
    /** Initialize Enemy radius
     * @param the value of enemy radius(int)
     */
    void init(int radius1);
    
    /** Draw the food(lcd) */
    void draw(N5110 &lcd);
    
    /** Update the y position and y velocity of the enemy 
     * @param new y attributes.
     */
    void update();
    
    
    //accessors and mutators
    /** set the velocity
     * @param the velocity.y of the enemy
     */
    void set_the_velocity(Vector2D v);
    
    /** Get velocity
     * @return velocity of y
     */
    Vector2D get_the_velocity();
    
    /** Get x and y position of enemy
     * @return x and y  position
     */
    Vector2D get_position();
    
    /** set the x and y position
     * @param the x and y of the enemy
     */
    void set_position(Vector2D p);
    
private:
    int x1;
    int y1;
    int _radius;
    int speed;
    Vector2D _v;
    
};
#endif