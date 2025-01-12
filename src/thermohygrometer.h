#pragma once

#include "peripheral.h"

class Thermohygrometer : public Peripheral
{
private:
    string name;
    bool active;
    float temperature;
    float humidity;

public:
    Thermohygrometer();
    Thermohygrometer(const string &name);
    ~Thermohygrometer() = default;

    // Getters
    string getName() override;
    float getTemperature() const;
    float getHumidity() const;
    bool isOn() const override;

    // Setters
    void renameDevice(const string &newName);
    void measureTemperature();
    void measureHumidity();

    // Custom functions
    void quickAction() override;
    // Time getSchedule() const override;
};