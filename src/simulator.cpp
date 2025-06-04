#include "cba/simulator.hpp"

namespace ColorBlindAssist {
    Color Simulator::simulate(Color color, DaltonismType type) {
        Color ret(0,0,0);
        int r{0}, g{0}, b{0};
        switch (type)
        {
            case DaltonismType::Protanopia:
            // Protanopia	[[0.5667, 0.4333, 0], [0.5583, 0.4417, 0], [0, 0.2417, 0.7583]]
                r = static_cast<int>(color.get_r() * 0.5667 + color.get_g() * 0.4333);
                g = static_cast<int>(color.get_r() * 0.5583 + color.get_g() * 0.4417);
                b = static_cast<int>(color.get_g() * 0.2417 + color.get_b() * 0.7583);
                break;
            case DaltonismType::Deuteranopia:
            // Deuteranopia	[[0.625, 0.375, 0], [0.7, 0.3, 0], [0, 0.3, 0.7]]
                r = static_cast<int>(color.get_r() * 0.625 + color.get_g() * 0.375);
                g = static_cast<int>(color.get_r() * 0.7 + color.get_g() * 0.3);
                b = static_cast<int>(color.get_g() * 0.3 + color.get_b() * 0.7);
                break;
            case DaltonismType::Tritanopia:
            // Tritanopia	[[0.95, 0.05, 0], [0, 0.4333, 0.5667], [0, 0.475, 0.525]]
                r = static_cast<int>(color.get_r() * 0.95 + color.get_g() * 0.05);
                g = static_cast<int>(color.get_g() * 0.4333 + color.get_b() * 0.5667);
                b = static_cast<int>(color.get_g() * 0.475 + color.get_b() * 0.525);
                break;
            default:
                break;
        }
        ret.set_r(r);
        ret.set_g(g);
        ret.set_b(b);
        return ret;
    }

}
