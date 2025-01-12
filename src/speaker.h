#pragma once
#include "peripheral.h"

class Speaker : public Peripheral
{
private:
    string name;
    bool active;
    float percentage;

public:
    Speaker();
    Speaker(const string &name);
    ~Speaker() = default;

    // Getters
    string getName() override;
    bool isOn() const override;

    // Setters
    void renameDevice(const string &newName);

    // Custom functions
    void quickAction() override;
    // Time getSchedule() const override;
};
