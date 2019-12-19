#include <string>

#include "../include/CpuInfo.hpp"

void CpuInfo::setCurrentMhz()
{
    std::string data = Command::execute("lscpu | grep 'CPU MHz'");
    data.erase(0, 33);
    m_CurrentMhz = std::stof(data, NULL);
}

void CpuInfo::setMinMhz()
{
    std::string data = Command::execute("lscpu | grep 'CPU min MHz'");
    data.erase(0, 29);
    m_MinMhz = std::stof(data, NULL);
}

void CpuInfo::setMaxMhz()
{
    std::string data = Command::execute("lscpu | grep 'CPU max MHz'");
    data.erase(0, 29);
    m_MaxMhz = std::stof(data, NULL);
}

void CpuInfo::setUtilization()
{
    std::string data = Command::execute("top -b -n1 | grep \"Cpu(s)\" | awk '{print $2+$4}' | tail -n1");
    m_Utilization = std::stof(data, NULL);
}

float CpuInfo::getCurrentMhz()
{
    return m_CurrentMhz;
}

float CpuInfo::getMinMhz()
{
    return m_MinMhz;
}

float CpuInfo::getMaxMhz()
{
    return m_MaxMhz;
}

float CpuInfo::getUtilization()
{
    return m_Utilization;
}
