#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Menu {
public:
    //Function pointers to create function array like a switch statement
    //for now lets create standard member functions
    void mainMenu(){}
    void deviceMenu(){}

private:
    string menuDivider = "\n##########################\n";
    string mainOptions[3] = {};
    string quit = "Quit";
};