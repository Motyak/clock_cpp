#include "Clock.h"

Clock::Clock()
{
    this->update();
    
    this->th = std::thread(&Clock::updatePeriodically, this);
    this->th.detach(); 
}

void Clock::update()
{
    std::time(&this->now);
}

void Clock::updatePeriodically()
{
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        this->update();
    }
}

std::ostream& operator<<(std::ostream& os, const Clock& clock)
{
    char* time = std::ctime(&clock.now);
    time[strlen(time) - 1] = '\0';
    return os << time;
}
