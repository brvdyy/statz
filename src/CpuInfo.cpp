#include <string>

#include "../include/CpuInfo.hpp"

void CpuInfo::setMHz()
{
    std::string data = Command::execute("lscpu | grep 'CPU MHz'");
    data.erase(0, 33);
    m_MHz = std::stof(data, NULL);
}

void CpuInfo::setUtilization()
{
    std::string data = Command::execute("top -b -n1 | grep \"Cpu(s)\" | awk '{print $2+$4}' | tail -n1");
    m_Utilization = std::stof(data, NULL);
}

float CpuInfo::getMHz()
{
    return m_MHz;
}

float CpuInfo::getUtilization()
{
    return m_Utilization;
}
