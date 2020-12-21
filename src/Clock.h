#ifndef CLOCK_H
#define CLOCK_H

#include <ctime>
#include <iostream>
#include <cstring>
#include <chrono>
#include <thread>

class Clock
{
    std::time_t now;
    std::thread th;

    void update();
    void updatePeriodically();

  public: 
    Clock();

    friend std::ostream& operator<<(std::ostream& os, const Clock& clock);

};
#endif