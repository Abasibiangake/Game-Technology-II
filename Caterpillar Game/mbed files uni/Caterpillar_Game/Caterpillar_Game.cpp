#include "Caterpillar_Game.h"

Caterpillar_Game::Caterpillar_Game()
{
    
}
Caterpillar_Game::~Caterpillar_Game()
{
    
}

void Caterpillar_Game::init(int caterpillar_width,int caterpillar_height,int food_height, int food_width, int enemy_radius1)
{
 
     // initialise caterpillar characteristics
    _caterpillar_width = caterpillar_width;
    _caterpillar_height = caterpillar_height;
     
     // initialise food characteristics
    _food_height = food_height;
    _food_width = food_width;
    
    // initialise enemy characteristic
    _enemy_radius1 = enemy_radius1;
    
    // puts caterpillar in the middle
    _p1.init(_caterpillar_height,_caterpillar_width);
    _food.init(_food_height,_food_width);
    _enemy.init(_enemy_radius1);
    
}
void Caterpillar_Game::read_input(Gamepad &pad)
{
    _d = pad.get_direction();
    _mag = pad.get_mag();
}

void Caterpillar_Game::draw(N5110 &lcd)
{
    //draw board of game on screen
    lcd.drawRect(0,0,WIDTH,HEIGHT,FILL_TRANSPARENT);
    // add grass on board of the screen
    lcd.printString("|***************",0, 5);
    
    // display score
    display_scores(lcd);
    
    // caterpillar
    _p1.drawonlcd(lcd);
    
    // draw caterpillar food
    _food.drawonlcd(lcd);
    
    // draw caterpillar enemy
    _enemy.draw(lcd);
}


void Caterpillar_Game::update_gameonlcd(Gamepad &pad)
{
    // update direction and position of the caterpillar on screen.
    _p1.updateonlcd(_d,_mag);
    
    // update food on screen
    _food.update(newfood_x, newfood_y);
    
    // update the enemy on screen
    _enemy.update();
    
    // caterpillar test 
    check_if_caterpillar_eaten_food(pad);    // test to see if food is eaten, then update the caterpillar attribute.
    check_if_enemy_has_killed_caterpillar(pad);    // test to see if enemy collides with the caterpillar's body.
}

void Caterpillar_Game::check_if_caterpillar_eaten_food(Gamepad &pad)
{
    // get current caterpillar food location
    newfood_x = _food.get_pos_x();
    newfood_y = _food.get_pos_y();
    
    // check p1 (caterpillar) x and y position.
    Vector2D p1_pos = _p1.get_pos();

    // check if the caterpillar has eaten the food.
    if (p1_pos.x >= newfood_x && p1_pos.x < newfood_x+5 || p1_pos.x+5 >= newfood_x && p1_pos.x+5 < newfood_x+5) {
        if (p1_pos.y >= newfood_y && p1_pos.y < newfood_y+6 || p1_pos.y+6 >= newfood_y && p1_pos.y+6 < newfood_y+6) {
            
            //new food parameter.
            newfood_x = rand() % (WIDTH - 7);
 
            newfood_y = rand() % (HEIGHT - 7);
            
            // audio feedback
            pad.tone(1000.0,0.1);
            _p1.add_score();
            
        }
    }
    
    
    _food.update(newfood_x, newfood_y);
    _p1.updateonlcd(_d,_mag);
    
}

void Caterpillar_Game::check_if_enemy_has_killed_caterpillar(Gamepad &pad) {
    // check p1 (caterpillar) x and y position.
    Vector2D p1_pos = _p1.get_pos();
    
    // check caterpillar enemy x and y position.
    Vector2D enemy_pos = _enemy.get_position();
    if (
        (enemy_pos.y >= p1_pos.y) &&   //top
        (enemy_pos.y <= p1_pos.y + 12)  && //bottom
        (enemy_pos.x >= p1_pos.x) && 
        (enemy_pos.x <= p1_pos.x + 3)  
    ) {
         _p1.subtract_score();
         pad.tone(1000.0,0.1);
        }
    
    _p1.updateonlcd(_d,_mag);
    _enemy.update();
    
}

void Caterpillar_Game::display_scores(N5110 &lcd)
{   // sprite to display butterfly when game is won
    int butterfly[7][9] = {
        { 1,1,0,0,0,0,0,1,1 },
        { 1,0,1,0,0,0,1,0,1 },
        { 1,0,0,1,1,1,0,0,1 },
        { 1,1,1,1,0,1,1,1,1 },
        { 1,0,0,1,1,1,0,0,1 },
        { 1,0,1,0,0,0,1,0,1 },
        { 1,1,0,0,0,0,0,1,1 },
    
    };
    // sprite to show arrow from caterpillar to butterfly
    int arrow[5][5] = {
        { 0,0,1,0,0, },
        { 1,1,1,1,0, },
        { 1,1,1,0,1, },
        { 0,0,1,1,0, },
        { 0,0,1,0,0, },
    
        };
     // get scores from caterpillar
    int p1_score = _p1.get_score();
    char buff[14];
    sprintf(buff,"Score:%d",p1_score);
    lcd.printString(buff,0,4);  // font is 8 wide, so leave 4 pixel gape from middle assuming two digits
    while (p1_score >= 10){
        lcd.clear();
        lcd.printString("WINNER", 4,0);  // level 1 over
        lcd.printString(" BUTTERFLY!!!! ",4,2);
        lcd.printString(" BUTTERFLY!!!! ",4,2); 
        lcd.drawSprite(50,25,7,9,(int *)butterfly); // sprite to draw a butterfly
        lcd.drawRect(20, 25, 7, 3, FILL_BLACK);
        lcd.drawSprite(35,25,5,5,(int * )arrow);
        lcd.refresh();
    }
    
    //leds 1- 6 represent the 6 life of the caterpillar
    if (p1_score == -2){
        led6 = 1;
    } else if(p1_score == -4) {
        led6 = 1;
        led5 = 1;
    } else if(p1_score == -6) {
        led6 = 1;
        led5 = 1;
        led4 = 1;
     } else if(p1_score == -8) {
        led6 = 1;
        led5 = 1;
        led4 = 1;
        led3 = 1;
     } else if(p1_score == -10) {
        led6 = 1;
        led5 = 1;
        led4 = 1;
        led3 =1;
        led2 = 1;
     } else if(p1_score == -12) {
        led6 = 1;
        led5 = 1;
        led4 = 1;
        led3 =1;
        led2 =1;
        led1 = 1;
        lcd.clear();
        lcd.printString("Lost", 4,0);  
        lcd.printString("Game Over", 4,0); // End Game
        lcd.refresh();
     }

}
