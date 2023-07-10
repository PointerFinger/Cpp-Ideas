#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <string>

int main() {
	using namespace std:: this_thread;
	using namespace std:: chrono_literals;
	int time=1;
	int d;
	
	std::cout << "You are in the Wild West and about to do a duel. \n";
	sleep_for(3s);
	std::cout << "After three seconds you need to press D to be faster than your opponent. \n";
	sleep_for(3s);
	std::cout << "It's High Noon. \n";
	
	while(time <= 3) {
		std::cout << time;
		std::cout << "\n";
		sleep_for(3s);
		time++;
	}
	sleep_for(1s);
	
	std::cout << "DRAW! \n";
		
	std::mt19937_64 draw{std::random_device{}()};
    std::uniform_int_distribution<> dist{1, 500};
    sleep_for(std::chrono::milliseconds{dist(draw)});
    
    if(std::cin >> d) {
    	std::cout << "You Win!";
    }
    else {
    	std::cout << "You Lost...";
    }
      
	return 0;
}
