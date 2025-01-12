#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Menu
{
protected:
    string input;
private:
    string prompt;
    // Map to store valid inputs for corresponding function pointers
    map<string, void (*)()> inputToFunctionMap;

    string confirmInput(string userInput){
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

public:
    Menu() = default;
    Menu(string prompt) : prompt(prompt) {}
    ~Menu() = default;


    static inline void clear()
    {
        // ANSI code clears console - taken from https://stackoverflow.com/questions/55672661/what-does-printf-033h-033j-do-in-c
        cout << "\033[2J\033[H" << endl;
    }

    static void returnAnyKeyToContinue(){
        cout << "Return any key to continue..." << endl;
        char wait;
        cin >> wait;
    }

    static inline void invalidOption()
    {
        cout << "Invalid option. Please try again.\n";
    }

    void promptUser(){
        while (true)
        {
            clear();
            cout << prompt;
            string tempInput;
            cin >> tempInput;
            input = confirmInput(tempInput);
        }
    }
    virtual bool selectOption() = 0;
    virtual void promptAndExecute() = 0;
};