#pragma once
#include "color.hpp"

namespace ColorBlindAssist {
    enum class DaltonismType {
        Protanopia,
        Deuteranopia,
        Tritanopia
    };
    class Simulator {
        public:
            static Color simulate(Color color, DaltonismType type);
    };
}