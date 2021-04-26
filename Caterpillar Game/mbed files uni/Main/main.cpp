/*
ELEC2645 Embedded Systems Project
School of Electronic & Electrical Engineering
University of Leeds
Name: James, Abasibiangake
Username: el17aej
Student ID Number: 201191089
Date: 26th March, 2019.
*/

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Caterpillar.h"
#include "Caterpillar_Game.h"
#include "Food.h"
#include "Enemy.h"

int caterpillar_w = 3;
int caterpillar_h = 12;
#define CATERPILLAR_WIDTH caterpillar_w
#define CATERPILLAR_HEIGHT caterpillar_h
#define FOOD_HEIGHT 7
#define FOOD_WIDTH 6
#define ENEMY_RADIUS1 3


Caterpillar_Game cat;
Gamepad gp;

// group different variables in a struct
struct UserInput {
    Direction d;
    float mag;
};

// objects 
N5110 lcd(PTC9,PTC0,PTC7,PTD2,PTD1,PTC11);
BusOut output(PTC2,PTA2,PTA1,PTD3,PTC4,PTC3); // order of leds is gotten from the notes. Gamepad leds.
DigitalOut led1(PTA1);
DigitalOut led2(PTA2);
DigitalOut led3(PTC2);
DigitalOut led4(PTC3);
DigitalOut led5(PTC4);
DigitalOut led6(PTD3);


void init();
void update_gameonlcd(UserInput input);
void rendertolcd();
void tutorial();
void welcome();
void nextpage();
void starttutorial();

int main()
{
    int fps = 8;  // frames per second

     
   while (1) {
        init();   // initialise and then display welcome screen..  
        welcome();
        rendertolcd();
        wait(1.0f/fps); // waiting for the user to start
        
        while (1) {
            cat.read_input(gp);
            cat.update_gameonlcd(gp);    // first draw the initial frame for the catrepillar.
            rendertolcd();
            wait(1.0f/fps);             // and wait for one frame period
            
            if (( gp.check_event(Gamepad::BACK_PRESSED) == true)){
            
                break;
            }
        }
        
    }
}

// initialisation
void init()
{
    // need to initialise LCD and Gamepad 
    lcd.init();
    gp.init();

    // initialise the game with correct caterpillar sizes
    cat.init(CATERPILLAR_WIDTH,CATERPILLAR_HEIGHT,FOOD_HEIGHT,FOOD_WIDTH,ENEMY_RADIUS1); 
}

void rendertolcd()
{
    // clear screen, re-draw and refresh
    lcd.clear(); 
    cat.draw(lcd);
    lcd.refresh();

}
void welcome() {
    lcd.printString(" CATERPILLAR!    ",0,0); 
    lcd.printString("  Let's Play!!!    ", 0,2);
    lcd.printString("  A = Tutorial   ", 0,3); 
    lcd.refresh();
    while(1) {
        if( gp.check_event(Gamepad::A_PRESSED) == true) {
        nextpage();
        starttutorial();
        tutorial();
    }
    if( gp.check_event(Gamepad::START_PRESSED) == true) {
        break;
    }       
}
      
}
void nextpage() {
    while( gp.check_event(Gamepad::B_PRESSED) == false) {
        lcd.clear();
        lcd.printString("***Tutorial!***",0,0); 
        lcd.printString("  Eat food  ", 0,1);
        lcd.printString(" 6 Life=6 leds ", 0,2); 
        lcd.printString("Hit Wall=lose  ",0,3);
        lcd.printString("Key B for more",0,4);
        lcd.refresh();
    }
}   

void starttutorial() {
    while( gp.check_event(Gamepad::X_PRESSED) == false) {
        lcd.clear();
        lcd.printString("START is pres",0,0); 
        lcd.printString("sed move joysti ", 0,1);
        lcd.printString("ck to activate  ", 0,2); 
        lcd.printString("the caterpillar.",0,3);
        lcd.printString("Key X for more",0,4);
        lcd.refresh();
    }
}   
void tutorial() {
    while ( gp.check_event(Gamepad::START_PRESSED) == false) {
        lcd.clear();
         lcd.printString(" Movement! ",0,0); 
        lcd.printString("Joystick moves:**", 0,1);
        lcd.printString(" Up, Down ", 0,2); 
        lcd.printString(" Left, Right ",0,3);
        lcd.printString("Start to play ",0,4);
        lcd.refresh();
    }
}

    
