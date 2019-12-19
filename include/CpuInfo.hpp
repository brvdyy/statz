#pragma once

#include <string>

#include "Command.hpp"

class CpuInfo
{
    private:
        std::string m_lscpu_info{""};
        float m_CurrentMhz{ 0.0 };
        float m_MinMhz{ 0.0 };
        float m_MaxMhz{ 0.0 };
        float m_Utilization{ 0.0 };

    public:
        void setCurrentMhz();
        void setMinMhz();
        void setMaxMhz();
        void setUtilization();

        float getCurrentMhz();
        float getMinMhz();
        float getMaxMhz();
        float getUtilization();
};
