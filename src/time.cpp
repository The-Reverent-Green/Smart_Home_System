#include <chrono>
#include <iostream>
#include <thread>
#include <queue> //includes vector

using namespace std;


class Timer
{
public:
    
    static void timer1hour()
    {
        // https://www.youtube.com/watch?v=t11q4qgwngQ
        auto startTime = std::chrono::steady_clock::now();

        bool timerRunning = true;
        while (true)
        {
            if (timerRunning)
            {
                auto now = std::chrono::steady_clock::now();
                if (std::chrono::duration_cast<chrono::minutes>(now - startTime) >= 60min)
                {
                    // timer complete !
                    std::cout << "Timer finished! \n" << endl;
                    timerRunning = false;
                    std::this_thread::sleep_for(1s);
                }
            }
        }
    }
    

};
