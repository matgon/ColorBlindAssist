#pragma once
#include "color.hpp"

namespace ColorBlindAssist {
    enum class DaltonismType {
        Protanopia,
        Protanomaly,
        Deuteranopia,
        Deuteranomaly,
        Tritanopia,
        Tritanomaly,
        Achromatopsia,
        Achromatomaly
    };
    class Simulator {
        public:
            static Color simulate(Color color, DaltonismType type);
    };
}