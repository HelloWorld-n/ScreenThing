#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <random>
#include <string>
#include <vector>
#include "TerminalUtil.cpp"

int enlimit(int num, int limit){
	if (num % (limit * 2) < limit){
		return num % limit;
	} else {
		return limit - (num % limit);
	}
}

int main(int argc, char **argv){
	int terminalSize[2] = {
		WEXITSTATUS(std::system("exit `tput lines`")), 
		WEXITSTATUS(std::system("exit `tput cols`"))
	};

	std::system("clear");
	std::cout << std::flush;
	
	const int gradientStart = 0.2 * terminalSize[0];
	const int gradientEnd = 0.7 * terminalSize[0];
	const int brightest = 200;
	int backgroundColor[3] = {};
	for (int i = 0; i < terminalSize[0] - 2; i++){
		for (int j = 0; j < terminalSize[1]; j++){
			if (i < gradientStart){
				for(int bg = 0; bg < 3; bg++){
					backgroundColor[bg] = 0;
				}
			} else if (i < gradientEnd){
				for (int bg = 0; bg < 3; bg++){
					backgroundColor[bg] = (
						i - gradientStart
					) * (
						brightest / (gradientEnd - gradientStart)
					);
				}
			} else {
				backgroundColor[0] = 85 + (3 * enlimit(j, 15));
				backgroundColor[1] = 0;
				backgroundColor[2] = 255;
			}

			TerminalUtil::setBackgroundColor(backgroundColor);
			std::cout << " ";
		}
		std::cout << "\n";
	}
	// reset colors
	std::cout << "\e[0m\n";
}
