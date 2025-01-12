#include <iostream>
#include "peripheral.h"
#include "light.h"
using namespace std;

Light::Light(){}
Light::Light(const string &name) : percentage(0.0f), name(name) {}

// getters
string Light::getName() { return name; }
bool Light::isOn() const { return percentage > 0.0f; }

// setters

/*
    Time Light::getSchedule() const
    {
        //return schedule; // Return the schedule (assumes this is handled in the base class)
    }
    */
// custom functions
void Light::quickAction()
    {
        cout << "What intensity would you like to set the light to? (0-100)" << endl;
        string userInput;
        cin >> userInput;
        this->percentage = stof(userInput);

        if (percentage < 0.0f)
        {
            percentage = 0.0f;
            return;
        }
        if (percentage > 100.0f) percentage = 100.0f;
        else {
            cout << "Light is now set to " << percentage << "% brightness." << endl;
        }

    }