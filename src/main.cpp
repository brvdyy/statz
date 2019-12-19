#include <cstdlib>
#include <iostream>
#include <unistd.h>

#include "../include/Command.hpp"
#include "../include/CpuInfo.hpp"

int main()
{
    CpuInfo ci;
    ci.setMinMhz();
    ci.setMaxMhz();
    while(true)
    {
        ci.setCurrentMhz();
        ci.setUtilization();
        //std::system("clear");
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Current Mhz: " << ci.getCurrentMhz() << "\n";
        std::cout << "Minimum Mhz: " << ci.getMinMhz() << "\n";
        std::cout << "Maximum Mhz: " << ci.getMaxMhz() << "\n";
        std::cout << "Current CPU Utilization: " << ci.getUtilization() << "%\n";
        sleep(1);
    }

    return 0; 
}

