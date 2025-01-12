#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

#include "light.cpp"
#include "thermohygrometer.cpp"
#include "speaker.cpp"
//#include "mainMenu.cpp"
//vector<shared_ptr<Peripheral>> temp = listDevicesUnordered();


using namespace std;

vector<shared_ptr<Peripheral>> devices;

bool alreadyTaken(const string &input)
{
    // All devices should have a user-editable device name that is unique across your system(case insensitive).
    // currently case sensitive
    for (const auto &device : devices)
    {
        if (input == device->getName())
            return true;
    }
    return false;
}

vector<shared_ptr<Peripheral>> listDevicesUnordered()
{
    return devices;
}
vector<shared_ptr<Peripheral>> listDevicesAlphabetically()
{
    vector<shared_ptr<Peripheral>> sortedDevices = devices;
    // sorting logic currently unimplemented
    return sortedDevices;
}
vector<shared_ptr<Peripheral>> listDevicesByType()
{
    vector<shared_ptr<Peripheral>> sortedDevices = devices;
    // sorting logic currently unimplemented
    return sortedDevices;
}

class Console
{
public:
    static inline void clear()
    {
        // ANSI code clears console - taken from https://stackoverflow.com/questions/55672661/what-does-printf-033h-033j-do-in-c
        cout << "\033[2J\033[H" << endl;
    }
    static void returnAnyKeyToContinue()
    {
        cout << "Return any key to continue..." << endl;
        char wait;
        cin >> wait; // Waits for a key press
    }
};

template <typename T>
void createAndConnectDevice(const string &name, vector<shared_ptr<Peripheral>> &devices)
{
    T *device = new T(name);
    devices.push_back(shared_ptr<Peripheral>(device));
    string objType = typeid(T).name();
    cout << "New " << objType << " [" << device->getName() << "] has been connected!" << endl;
    Console::returnAnyKeyToContinue();
}

void viewDevice()
{
}
void deleteDevice(string name)
{
    auto it = find_if(
        devices.begin(),
        devices.end(),
        [&name](const shared_ptr<Peripheral> &device)
        {
            return device->getName() == name;
        });
    devices.erase(it);
    cout << "Device deleted." << endl;
    Console::returnAnyKeyToContinue();
}
void oneClick()
{
    Console::clear();
    string deviceName;
    cout << "Enter the device name: ";
    cin >> deviceName;

    for (const auto &device : devices)
    {
        if (device->getName() == deviceName)
        {
            cout << "Performing quick action for " << deviceName << endl;
            device->quickAction();
            Console::returnAnyKeyToContinue();
            return;
        }
    }
    cout << "Device not found! Double check you've spelt it correctly." << endl;
    Console::returnAnyKeyToContinue();
}

void viewDevicesUnordered()
{
    vector<shared_ptr<Peripheral>> temp = listDevicesUnordered();

    Console::clear();
    cout << "Listing devices unordered..." << endl;
    for (int i(0); i < temp.size(); i++)
        cout << i << ": " << temp[i]->getName() << endl;

    Console::returnAnyKeyToContinue();
}
void exitProgram()
{
    // write data to persistent memory
    // close program
    Console::clear();
    cout << "The program has now ended, thank you for your time." << endl;
}

// Action Functions
string askForName()
{
    string name;
    while (true)
    {
        cout << "\nEnter the name for the device: " << endl;
        cin >> name;
        if (name == "0")
        {
            cout << "Aborting device connection.\n";
            return "";
        }
        if (!isalpha(name[0]))
        {
            cout << "Name must start with a letter, try again." << endl;
            continue;
        }
        if (alreadyTaken(name))
        {
            cout << "Name is already take, try again." << endl;
            continue;
        }
        break;
    }
    return name;
}

// Menu Functions
void connectDeviceMenu()
{
    string name;
    char choice;
    while (true)
    {
        Console::clear();
        cout << "Please choose a device to connect (Enter the number):\n"
                "0 - Abort\n"
                "1 - Light\n"
                "2 - Temperature & Humidity Sensor\n"
                "3 - Speaker\n"
                "4 - Thermostat\n"
                "5 - Smart Plug Socket\n"
                "6 - Smart Valve\n"
                "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case '0':
            cout << "Aborting device connection.\n\n";
            Console::returnAnyKeyToContinue();
            return;
        case '1':
            cout << "You selected: Light." << endl;
            name = askForName();
            if (name == "0")
                return;
            createAndConnectDevice<Light>(name, devices);
            return;
        case '2':
            cout << "You selected: Temperature & Humidity Sensor.\n";
            name = askForName();
            if (name == "0")
                return;
            createAndConnectDevice<Thermohygrometer>(name, devices);
            return;
        case '3':
            cout << "You selected: Speaker.\n";
            name = askForName();
            if (name == "0")
                return;
            createAndConnectDevice<Speaker>(name, devices);
            return;
        case '4':
            cout << "You selected: Thermostat.\n";
            name = askForName();
            if (name == "0")
                return;
            // createAndConnectDevice<Thermostat>(name, devices);
            break;
        case '5':
            cout << "You selected: Smart Plug Socket.\n";
            name = askForName();
            if (name == "0")
                return;
            // createAndConnectDevice<SmartPlug>(name, devices);
            break;
        case '6':
            cout << "You selected: Smart Valve.\n";
            name = askForName();
            if (name == "0")
                return;
            // createAndConnectDevice<SmartValve>(name, devices);
            break;
        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    }
    cout << "Device connected!" << endl;
    return;
}
/*void mainMenu2(){
    MainMenu mainMenu("Select an option:\n"
        "0 - Exit program\n"
        "1 - List devices\n"
        "2 - List devices alphabetically\n"
        "3 - List devices by type\n"
        "4 - Select a device to interact with its full feature set\n"
        "5 - Add a device\n"
        "6 - Select a device to view its Quick-Action\n");
        mainMenu.promptAndExecute();
}*/
void mainMenu()
{
    char choice;
    while (true)
    {
        Console::clear();
        cout << "Select an option:\n"
             << "0 - Exit program\n"
             << "1 - List devices\n"
             << "2 - List devices alphabetically\n"
             << "3 - List devices by type\n"
             << "4 - Select a device to interact with its full feature set\n"
             << "5 - Add a device\n"
             << "6 - Select a device to view its Quick-Action\n";
        cin >> choice;
        switch (choice)
        {
        case '0':
            exitProgram();
            return;
        case '1':
        {
            vector<shared_ptr<Peripheral>> temp = listDevicesUnordered();

            Console::clear();
            cout << "Listing devices unordered..." << endl;
            for (int i(0); i < temp.size(); i++)
                cout << i << ": " << temp[i]->getName() << endl;

            Console::returnAnyKeyToContinue();
        }
            break;
        case '2':
        {
            vector<shared_ptr<Peripheral>> temp = listDevicesAlphabetically();

            Console::clear();
            cout << "Listing devices alphabetically..." << endl;
            for (int i(0); i < temp.size(); i++)
                cout << i << ": " << temp[i]->getName() << endl;

            Console::returnAnyKeyToContinue();
        }
            break;
        case '3':
        {
            vector<shared_ptr<Peripheral>> temp = listDevicesAlphabetically();

            Console::clear();
            cout << "Listing devices by type..." << endl;
            for (int i(0); i < temp.size(); i++)
                cout << i << ": " << temp[i]->getName() << endl;

            Console::returnAnyKeyToContinue();
        }
            break;
        case '4':
            Console::clear();
            cout << "Viewing device...\n"<< endl;
            viewDevice();
            Console::returnAnyKeyToContinue();
            break;
        case '5':
            connectDeviceMenu();
            break;
        case '6':
            oneClick();
            break;
        default:
            cout << "Invalid option selected. Please try again." << endl;
            break;
        }
    }
}

int start()
{
    string filepath = "data/persistent_memory.txt";
    fstream file(filepath, ios::in | ios::out | ios::app);
    if (!file.good())
    {
        cout << "File doesn't exist or can't be opened for reading and writing\nThe program is unable to access persistent memory.\nEnd of program." << endl;
        return 1;
    }
    file.seekg(0);
    bool thisIsTheFirstTimeRunningTheProgram = (file.peek() == ifstream::traits_type::eof());
    if (!thisIsTheFirstTimeRunningTheProgram)
    {
        //load persistent memory and push to vector<shared_ptr<Peripheral>> devices;
    }
    return 0;
}

int main(){
    if (start()) return 1;//early exit if start() fails
    mainMenu();
    return 0;
}
// g++ -std=c++17 -o scr src/main.cpp
// ./scr

class PersistentMemory
{
public:
    bool loadMemory()
    {
        fstream file(getFilepath(), ios::in | ios::out | ios::app);
        bool thisIsTheFirstTimeRunningTheProgram = (file.peek() == ifstream::traits_type::eof());
        if (!file.good())
        {
            cout << "File doesn't exist or can't be opened for reading and writing\nThe program is unable to access persistent memory.\nEnd of program." << endl;
            return 0;
        }

        file.seekg(0);
        if (thisIsTheFirstTimeRunningTheProgram)
        {
            cout << "No data found in persistent memory." << endl;
            return 1;
        }
        // load persistent memory and push to vector<shared_ptr<Peripheral>> devices;
        string rawMemory;
        return 1;
    }
    void pushToVector() {}
    void saveToMemory(vector<unique_ptr<Peripheral>> &devices) {}

private:
    inline string getFilepath()
    {
        return "data/persistent_memory.txt";
    }
};
