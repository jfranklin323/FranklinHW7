//header file
//class declaration

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

#define LED_PATH "/sys/class/leds/beaglebone:green:usr"

class LED{
        private:    // classes that dont allow outside access
                string path;
                int number;
                virtual void writeLED(string filename, string value);
                virtual void removeTrigger();
        public:    // classes that can be accessed publicly
                LED(int number);
                virtual void turnOn();
                virtual void turnOff();
                virtual void flash(string delayms);
                virtual void outputState();
                virtual ~LED();
};
