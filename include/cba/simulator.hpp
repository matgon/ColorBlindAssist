#pragma once
#include "color.hpp"
#include "string"

namespace ColorBlindAssist {

    class Simulator {
        public:
            static Color simulate(Color color, DaltonismType type, std::map<DaltonismType, const std::array<std::array<double, 3>, 3>> conversion_map);
            static void simularDaltonismo(const std::string& ruta, DaltonismType tipo);
    };
}