#include <string>

#include "../include/CpuInfo.hpp"

void CpuInfo::setMHz()
{
    std::string lscpu = Command::execute("lscpu | grep 'CPU MHz'");
    lscpu.erase(0, 33);
    m_MHz = std::stof(lscpu, NULL);
}

float CpuInfo::getMHz()
{
    return m_MHz;
}
