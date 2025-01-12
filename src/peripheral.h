#pragma once
#include <string>
//#include "time.h"
using namespace std;

class Peripheral {
protected:
    string name;
    bool active;
    float percentage;
    
    //Time schedule;

public:
    Peripheral(){};
    virtual ~Peripheral() = default;

    // Getters
    virtual string getName() { return name; };
    virtual bool isOn() const = 0; 

    // setters
    void renameDevice(const string &newName) {
        string lowerCase = newName;
        for (char &c : lowerCase)
            c = tolower(static_cast<unsigned char>(c));
        name = lowerCase;
    }
    // Methods
    //virtual Time getSchedule() const = 0;
    virtual void quickAction() = 0;  
};