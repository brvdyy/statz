#include <iostream>
#include <unistd.h>

#include "../include/Command.hpp"
#include "../include/CpuInfo.hpp"

int main()
{
    CpuInfo ci;
    while(true)
    {
        ci.setMHz();
        ci.setUtilization();
        std::cout << ci.getMHz() << std::endl;
        std::cout << ci.getUtilization() << std::endl;
        sleep(1);
    }

    return 0; 
}

