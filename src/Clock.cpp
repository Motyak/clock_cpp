#include "Clock.h"

Clock::Clock()
{
    this->now = std::make_unique<std::time_t>();

    this->update();
    
    this->th = std::thread(&Clock::updatePeriodically, this);
    this->th.detach(); 
}

void Clock::update()
{
    std::time(this->now.get());
}

void Clock::updatePeriodically()
{
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        this->update();
        std::cout<<*this<<std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Clock& clock)
{
    char* time = std::ctime(clock.now.get());
    time[strlen(time) - 1] = '\0';
    return os << time;
}