#ifndef CATERPILLAR_GAME_H
#define CATERPILLAR_GAME_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Caterpillar.h"
#include "Food.h"
#include "Enemy.h"


extern DigitalOut led1;
extern DigitalOut led2;
extern DigitalOut led3;
extern DigitalOut led4;
extern DigitalOut led5;
extern DigitalOut led6;

/** Caterpillar_Game Class
 * @brief Class that collates the caterpillar and food data together to play game.
 * @author James, Abasibiangake
 * @author Dr Craig A. Evans (reference code)
 * @date May, 2019
 */
class Caterpillar_Game
{
    
public:
    /** Constructor */
    Caterpillar_Game();
    
    /** Destructor */
    ~Caterpillar_Game();
    
    /** Initialize caterpillar's width and height
     * Initialize width and height
     * @param the value of caterpillar_width(int) and caterpillar_height(int)
     * @param the value of food_width(int) and food_height(int)
     */
    void init(int caterpillar_width,int caterpillar_height, int food_height, int food_width, int enemy_radius1);
    
    /** Read the input sent to the gamepad 
     * @return the input which is direction and magnitude
     */
    void read_input(Gamepad &pad);
    
    /** Update the gamepad with the new direction, position and magnitude.
     * @param the new direction, position and magnitude.
     */  
    void update_gameonlcd(Gamepad &pad);
    
    /** Draw the board, caterpillar and food 
     * @return the drawn caterpillar, food and board on lcd
     */
    void draw(N5110 &lcd);

    
private:
    void check_if_caterpillar_eaten_food(Gamepad &pad);
    void check_if_enemy_hits_wall (Gamepad &pad);
    void check_if_enemy_has_killed_caterpillar (Gamepad &pad);
    void check_if_food_and_enemy_collide (Gamepad &pad);
    void display_scores(N5110 &lcd);
   
    int _caterpillar_width;
    int _caterpillar_height;
    int _food_height;
    int _food_width;
    int _enemy_radius1;

    Caterpillar _p1;
    Food _food;
    Enemy _enemy;
    
    Direction _d;
    float _mag;
    int newfood_x;
    int newfood_y;

    
};
#endif