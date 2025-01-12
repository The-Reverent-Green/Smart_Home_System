#pragma once

#include "menu.h"

using namespace std;

class MainMenu : public Menu
{
private:
    string input;

    void exitProgram();
    void viewDevicesUnordered();
    void viewDevicesAlphabetically();
    void viewDevicesByType();

    bool selectOption();
public:
    MainMenu() = default;
    MainMenu(string prompt);
    ~MainMenu() = default;


    void promptAndExecute();
};