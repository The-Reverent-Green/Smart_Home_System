#include <iostream>
#include "peripheral.h"
#include "speaker.h"
using namespace std;

Speaker::Speaker() {}
Speaker::Speaker(const string &name) 
    : percentage(0.0f), name(name), active(false){}
// Getters
string Speaker::getName(){return name;}
bool Speaker::isOn() const { return active; }

// Setters

// Custom functions
void Speaker::quickAction(){}
// Time getSchedule() const override;