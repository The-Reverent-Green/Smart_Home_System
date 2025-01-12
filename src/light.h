#pragma once
#include "peripheral.h"

class Light : public Peripheral {
private:
    string name;
    bool active;
    float percentage;

public:
    Light();
    Light(const string &name);
    ~Light() = default;

    //Getters
    string getName() override;
    bool isOn() const override;
    
    //Setters


    //Custom functions
    void quickAction() override;
    //Time getSchedule() const override;
};
