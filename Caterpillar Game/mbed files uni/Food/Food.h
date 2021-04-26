#ifndef FOOD_H
#define FOOD_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"

/** Food Class
 * @brief Class for getting the attribute of the Caterpillar's food.
 * @author James, Abasibiangake.
 * @date May 2019.
 */
class Food
{
public:
    /** Constructor */
    Food();
    
    /** Destructor */
    ~Food();
    
    /** Initialize width and height
     * @param the value of width(int) and height(int)
     */
    void init(int width, int height);
    
    /** Draw the food(lcd) */
    void drawonlcd(N5110 &lcd);
    
    /** Get the x position of the food
     * @return the current x position of food
     */
    int get_pos_x();
    
    /** Get the y position of the food
     * @return the current y position of food
     */
    int get_pos_y();
    
    /** Update the food's x and y position
     * @param the updated value the food's x and y position
     */
    void update(int newfood_x, int newfood_y);

private:
//    int _size;
    int _xorigin;
    int _yorigin;
    int _x;
    int _y;
};
#endif