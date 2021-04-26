#ifndef FOOD_TEST_H
#define FOOD_TEST_H

/**
 * @brief Checks if the food goes to correct position when moved
 * 
 * \returns true if all the tests passed and false if failed.
 */
bool Food_test_movement()
{
    // Initialise food object
    Food food;
    /** Initializes food object */
    food.init();
    
    // read and update food position
    /** Read the position of food 
     * @return position of food
     */
    Vector2D read_pos_1 = food.get_pos();
    
    printf("%f, %f\n", read_pos_1.x, read_pos_1.y);
    food.update();
    
    bool success_flag = true;
    
    if (read_pos_1.x != WIDTH - _width1 - 1 || read_pos_1.y != HEIGHT - _height1 - 1) {
        success_flag = false;
    }
    
    return success_flag;
}
#endif