#pragma once

#include <string>

#include "Command.hpp"

class CpuInfo
{
    private:
        std::string m_lscpu_info{""};
        float m_MHz{ 0.0 };
        float m_Utilization{ 0.0 };

    public:
        void setMHz();
        void setUtilization();

        float getMHz();
        float getUtilization();
};
