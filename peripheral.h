#include <string>
#include "time.h"
using namespace std;

class Peripheral
{
private:
    string name;
    string type;

    bool active;

    float percentage;

    Time schedule;

public :
// constructors
    Peripheral();
    ~Peripheral();

//accessors
    string getName();
    string getType();

    bool isOn();
    
    float getIntensity();

    virtual Time getSchedule() const = 0;

//modifiers
    void setName(string name);
    void setType(string type);

//custom functions
    virtual void read() const = 0;
    virtual void write() const = 0;


};