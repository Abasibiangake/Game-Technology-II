#ifndef CATERPILLAR_H
#define CATERPILLAR_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"

/** Caterpillar Class
 * @brief Class sets the attribute of the Caterpillar.
 * @author James, Abasibiangake
 * @author Dr Craig A. Evans
 * @date May, 2019
 */
class Caterpillar
{
public:
    /** Constructor */
    Caterpillar();
    
    /** Destructor */
    ~Caterpillar();
    
    /** Initialize caterpillar's width and height
     * @param the value of caterpillar_width(int) and caterpillar_height(int)
     */
    void init(int height,int width);
    
    /** Draw the caterpillar with the chosen height and width */
    void drawonlcd(N5110 &lcd);
    
    /** Update the direction and magnitude of the speed of the caterpillar.
     * @param the new value of the speed as the direction changes.
     */
    void updateonlcd(Direction d,float mag);
    
    /** Add the scrore
     * @param new incremented score
     */
    void add_score();
    
    /** Subtract the scrore
     * @param new incremented score
     */
    void subtract_score();
    
    /** Get the score
     * @return the current score
     */
    int get_score();
    
    /**Get the x and y position of the caterpillar
     * @return the current x and y position
     */
    Vector2D get_pos();
    
private:
    int _x;
    int _height1;
    int _width1;
    int _height;
    int _width;
    int _y;
    int _speed;
    int _score;

    
};
#endif