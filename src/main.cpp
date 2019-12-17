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
        std::cout << ci.getMHz() << std::endl;
        sleep(1);
    }

    return 0; 
}

