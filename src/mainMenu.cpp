#include "mainMenu.h"

using namespace std;

MainMenu::MainMenu(string prompt) : Menu(prompt) {}

void MainMenu::exitProgram()
{
    // write data to persistent memory
    // close program
    MainMenu::clear();
    cout << "The program has now ended, thank you for your time." << endl;
}

bool MainMenu::selectOption()
{
    if (input == "0")
    {
        exitProgram();
        return true;
    }
    return false;
}

void MainMenu::viewDevicesUnordered(){}
void MainMenu::viewDevicesAlphabetically(){}
void MainMenu::viewDevicesByType(){}

void MainMenu::promptAndExecute()
{
    int count = 3;
    while (count > 0)
    {
        promptUser();
        bool isExit = selectOption();
        if (isExit) break;
        count--;
    }
}