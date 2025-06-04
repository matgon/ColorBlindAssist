#include <iostream>
#include "cba/color.hpp"
#include "cba/simulator.hpp"

using namespace ColorBlindAssist;

int main() {
    Color c(100, 100, 100);
    auto sim = Simulator::simulate(c, DaltonismType::Protanopia);
    std::cout << "Color simulado (Deuteranopia): "
    << "R=" << sim.get_r() << ", G=" << sim.get_g() << ", B=" << sim.get_b() << std::endl;
    sim = Simulator::simulate(c, DaltonismType::Deuteranopia);
    std::cout << "Color simulado (Deuteranopia): "
              << "R=" << sim.get_r() << ", G=" << sim.get_g() << ", B=" << sim.get_b() << std::endl;
    sim = Simulator::simulate(c, DaltonismType::Tritanopia);
    std::cout << "Color simulado (Tritanopia): "
                << "R=" << sim.get_r() << ", G=" << sim.get_g() << ", B=" << sim.get_b() << std::endl;
    return (0);
}

