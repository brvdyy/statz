#include <fstream>
#include <sstream>
#include <string>

#include "../include/CpuInfo.hpp"

float CpuInfo::getCurrentMhz()
{
    std::string data = Command::execute("lscpu | grep 'CPU MHz'");
    data.erase(0, 33);
    m_CurrentMhz = std::stof(data, NULL);

    return m_CurrentMhz;
}

float CpuInfo::getMinMhz()
{
    std::string data = Command::execute("lscpu | grep 'CPU min MHz'");
    data.erase(0, 29);
    m_MinMhz = std::stof(data, NULL);

    return m_MinMhz;
}

float CpuInfo::getMaxMhz()
{
    std::string data = Command::execute("lscpu | grep 'CPU max MHz'");
    data.erase(0, 29);
    m_MaxMhz = std::stof(data, NULL);

    return m_MaxMhz;
}

float CpuInfo::getUtilization()
{
    std::string data = Command::execute("top -b -n1 | grep \"Cpu(s)\" | awk '{print $2+$4}' | tail -n1");
    m_Utilization = std::stof(data, NULL);

    return m_Utilization;
}

float CpuInfo::getTemp()
{
    std::ifstream f("/sys/class/thermal/thermal_zone0/temp");
    std::string data{""};

    if(f)
    {
        std::ostringstream ss{};
        ss << f.rdbuf();
        data = ss.str();
    }
    m_temp = std::stof(data, NULL) / 1000;

    return m_temp;
}
