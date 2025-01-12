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

    string confirmInput(string userInput);

public:
    Menu() = default;
    Menu(string prompt);
    ~Menu() = default;


    static inline void clear()
    {
        // ANSI code clears console - taken from https://stackoverflow.com/questions/55672661/what-does-printf-033h-033j-do-in-c
        cout << "\033[2J\033[H" << endl;
    }

    static void returnAnyKeyToContinue();

    static inline void invalidOption()
    {
        cout << "Invalid option. Please try again.\n";
    }

    virtual void promptUser();
    virtual bool selectOption() = 0;
    virtual void promptAndExecute() = 0;
};