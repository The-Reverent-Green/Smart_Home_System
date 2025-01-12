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
    return false;
}

void MainMenu::viewDevicesUnordered()
{
    
}
void MainMenu::viewDevicesAlphabetically(){}
void MainMenu::viewDevicesByType(){}

void MainMenu::promptAndExecute()
{
    while (true)
    {
        promptUser();
        bool isExit = selectOption();
        if (isExit) break;
    }
}