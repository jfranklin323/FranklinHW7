//header file
//class declaration


#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include <unistd.h>
using namespace std;

#define LED_PATH "/sys/class/leds/beaglebone:green:usr"

class LED{
        private:    // private classes that cant be accessed with outside code
                string path;
                int number;
                virtual void writeLED(string filename, string value);
                virtual void removeTrigger();
        public:     //public classes that can be accessed with outside code 
                LED(int number);
                virtual void blink(int num);
                virtual void turnOn();
                virtual void turnOff();
                virtual void flash(string delayms);
                virtual void outputState();
                virtual ~LED();

};
