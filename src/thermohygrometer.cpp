#include <iostream>

#include "thermohygrometer.h"

using namespace std;


Thermohygrometer::Thermohygrometer(){}
Thermohygrometer::Thermohygrometer(const string &name) : name(name), active(false), temperature(0.0f), humidity(0.0f){}

string Thermohygrometer::getName(){ return name; }
float Thermohygrometer::getTemperature() const { return temperature; }
float Thermohygrometer::getHumidity() const { return humidity; }
bool Thermohygrometer::isOn() const { return active; }


void Thermohygrometer::measureTemperature()
{
    if(isOn()){
        temperature = 0;
        return;
    }
    cout << "Thermohygrometer [" << name << "] is inactive." << endl;
}
void Thermohygrometer::measureHumidity(){
    if(isOn()){
        humidity = 0;
        return;
    }
    cout << "Thermohygrometer is inactive." << endl;
}
void Thermohygrometer::quickAction()
{
    measureTemperature();
    measureHumidity();
    cout << "The current temperature is: " << temperature << "°C" << endl;
    cout << "The current humidity is: " << humidity << "%" << endl;
}