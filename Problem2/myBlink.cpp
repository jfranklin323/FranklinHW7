#include "derek_LED.h"


int main(int argc, char* argv[]){
   if(argc!=2){
        cout << "Usage is makeLEDs <command>" << endl;
        cout << "   command is one of: on, off, flash or status" << endl;
        cout << " e.g. makeLEDs flash" << endl;
   }

        cout << "Start blinking LED" << endl;
        string cmd(argv[1]);

        //initilization 
        int LEDblinky = 0;
        int Blinks = 0;

        //convert string to to integer
        if(argc == 4) {
          LEDblinky = atoi(argv[2]);
          Blinks = atoi(argv[3]);
       }


  LED leds[4] = { LED(0), LED(1), LED(2), LED(3) };
     for(int i=0; i<=3; i++){
                   if(cmd=="on")leds[i].turnOn();
                         else if(cmd=="off")leds[i].turnOff();
                               else if(cmd=="flash")leds[i].flash("100"); //default is "50"
                                     else if(cmd=="status")leds[i].outputState();
                                           else if(cmd=="blink" && i == LEDblinky)leds[i].blink(Blinks);  // if blink is commanded, LED will blink the set amount of times
                                                                   else { cout << "Invalid command!" << endl; }
                                              }
        cout << "Finished the blinking  program" << endl;
           return 0;
}
