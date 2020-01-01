#include <cstdlib>
#include <iostream>
#include <unistd.h>

#include "../include/Command.hpp"
#include "../include/CpuInfo.hpp"

int main()
{
    CpuInfo ci;
    float cur_mhz{};
    float min_mhz{};
    float max_mhz{};
    float util{};
    float temp{};

    std::cout << "\033[2J\033[1;1H";
    while(true)
    {
        cur_mhz = ci.getCurrentMhz();
        min_mhz = ci.getMinMhz();
        max_mhz = ci.getMaxMhz();
        util = ci.getUtilization();
        temp = ci.getTemp();
        
        std::cout << "             _        _       \n" 
                     "         ___| |_ __ _| |_ ____\n"
                     "        / __| __/ _` | __|_  /\n"
                     "        \\__ \\ || (_| | |_ / / \n"
                     "        |___/\\__\\__,_|\\__/___|\n\n";

                      
        std::cout << "Current Mhz:                " << cur_mhz << "\n";
        std::cout << "Minimum Mhz:                " << min_mhz << "\n";
        std::cout << "Maximum Mhz:                " << max_mhz << "\n";
        std::cout << "Current CPU Utilization:    " << util << "%\n";
        std::cout << "Current CPU Temp:           " << temp << " c\n";

        for (int i = 0; i < 11; i++)
            std::cout << "\033[A";
        sleep(1);
    }

    return 0; 
}





