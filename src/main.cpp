#include "Clock.h"

int main()
{
	Clock clock;
	std::cout<<clock<<std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout<<clock<<std::endl;
}
