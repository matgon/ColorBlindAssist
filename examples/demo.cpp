#include <iostream>
#include "cba/color.hpp"
#include "cba/simulator.hpp"

int main() {
    ColorBlindAssist::Color c(255, 0, 0);
    auto sim = ColorBlindAssist::Simulator::simulate(c, ColorBlindAssist::DaltonismType::Deuteranopia);
    std::cout << "Color simulado (Deuteranopia): "
              << "R=" << sim.get_r() << ", G=" << sim.get_g() << ", B=" << sim.get_b() << std::endl;
    return (0);
}

