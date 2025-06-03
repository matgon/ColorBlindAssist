#include "cba/simulator.hpp"

namespace ColorBlindAssist {
    Color Simulator::simulate(Color color, DaltonismType type) {
        // Matrices de transformacion mas comunes:
        // Protanopia	[[0.5667, 0.4333, 0], [0.5583, 0.4417, 0], [0, 0.2417, 0.7583]]
        // Deuteranopia	[[0.625, 0.375, 0], [0.7, 0.3, 0], [0, 0.3, 0.7]]
        // Tritanopia	[[0.95, 0.05, 0], [0, 0.4333, 0.5667], [0, 0.475, 0.525]]
        Color ret(0,0,0);
        int r{0}, g{0}, b{0};
        switch (type)
        {
            case DaltonismType::Protanopia:
                r = static_cast<int>(color.get_r() * 0.5667 + color.get_g() * 0.4333);
                g = static_cast<int>(color.get_r() * 0.5583 + color.get_g() * 0.4417);
                b = color.get_b();
                break;
            case DaltonismType::Tritanopia:
                r = static_cast<int>(color.get_r() * 0.5667 + color.get_g() * 0.4333);
                g = static_cast<int>(color.get_r() * 0.5583 + color.get_g() * 0.4417);
                b = color.get_b();
                break;
            case DaltonismType::Deuteranopia:
                r = static_cast<int>(color.get_r() * 0.5667 + color.get_g() * 0.4333);
                g = static_cast<int>(color.get_r() * 0.5583 + color.get_g() * 0.4417);
                b = color.get_b();
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
