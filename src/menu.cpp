#include "menu.h"

using namespace std;

string Menu::confirmInput(string userInput)
{
    while (true)
    {
        cout << "Confirm [" << userInput << "] is correct. (y/n)" << endl;
        string confirmInput;
        cin >> confirmInput;
        if (confirmInput == "y")
        {
            return userInput;
        }
        if (confirmInput == "n")
        {
            cout << "Please re-enter your desired input" << endl;
            break;
        }
        else
        {
            invalidOption();
            continue;
        }
    }
    return "";
}

Menu::Menu(string prompt) : prompt(prompt) {}

void Menu::returnAnyKeyToContinue()
{
    cout << "Return any key to continue..." << endl;
    char wait;
    cin >> wait; 
}

void Menu::promptUser()
{
    while (true)
    {
        Menu::clear();
        cout << prompt;
        string tempInput;
        cin >> tempInput;
        input = confirmInput(tempInput);
    }
}