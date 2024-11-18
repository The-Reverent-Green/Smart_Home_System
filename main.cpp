#include <string>
#include <iostream>

#include "time.h"

using namespace std;

bool start(){
    return false;
}
void run(){
    cout << "Smart Home System";
}
void end(){

}
int main(){
    if (!start()){
        run();
    }
    end();
    return 0;
}