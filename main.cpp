#include <string>
#include <iostream>
#include <vector>

#include "time.h"

using namespace std;

bool start(){
    return false;
}
void run(){
    cout << "Smart Home System";
    // init lights
    // init thermometer & barometer
    // init thermostat
    // init socket
    // init radiator valve
}
void end(){

}

char menu(){
    string menuBreak = "\n################################################################";
    cout    << menuBreak
            << "\nMenu"
            << "\n" /*Add Peripherals here*/
            << "\nQuit"
            << endl;

    return '0';
}
int main(){
    if (!start()){
        run();
    }
    end();
    return 0;
}
