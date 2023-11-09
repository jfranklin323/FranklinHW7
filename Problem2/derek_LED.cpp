//implementation code

#include "derek_LED.h"


LED::LED(int number){
   this->number = number;
   // much easier with C++11 using to_string(number)...private number and what was passed to it
   ostringstream s;    // using a stream to contruct the path
   s << LED_PATH << number;   //append LED number to LED_PATH
   path = string(s.str());    //convert back from stream to string
}

void LED::blink(int num){  //function that takes int and returns a void
        cout << "Blinking LED " << num << " times." << endl;
        removeTrigger();
        for(int i = 0; i < num; i++) {
           writeLED("/brightness", "1"); // turns the LED on
           sleep(1);
           writeLED("/brightness", "0"); //turns the LED off
           sleep(1);
        }
}

void LED::writeLED(string filename, string value){
   ofstream fs;
   fs.open((path + filename).c_str());
   fs << value;
   fs.close();
}

void LED::removeTrigger(){
   writeLED("/trigger", "none");
}

void LED::turnOn(){
  cout << "Turning LED" << number << " on." << endl;
   removeTrigger();
   writeLED("/brightness", "1");
}

void LED::turnOff(){
   cout << "Turning LED" << number << " off." << endl;
   removeTrigger();
   writeLED("/brightness", "0");
}

void LED::flash(string delayms = "50"){
   cout << "Making LED" << number << " flash." << endl;
   writeLED("/trigger", "timer");
   writeLED("/delay_on", delayms);
   writeLED("/delay_off", delayms);
}

void LED::outputState(){
   ifstream fs;
   fs.open( (path + "/trigger").c_str());
   string line;
   while(getline(fs,line)) cout << line << endl
           ;
   fs.close();
}

LED::~LED(){
   cout << "destroying the LED with path: " << path << endl;
}
