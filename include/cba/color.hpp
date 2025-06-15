#pragma once
#include <map>
#include <array>

namespace ColorBlindAssist
{
    class Color
    {
        public:
        Color(int red, int green, int blue) : r(red), g(green), b(blue) {}
        int get_r() {return (r);}
        int get_g() {return (g);}
        int get_b() {return (b);}
        void set_r(int red) {r = red;}
        void set_g(int green) {g = green;}
        void set_b(int blue) {b = blue;}
        private:
        int r{0}, g{0}, b{0};
    };
    enum DaltonismType {
        Protanopia,
        Protanomaly,
        Deuteranopia,
        Deuteranomaly,
        Tritanopia,
        Tritanomaly,
        Achromatopsia,
        Achromatomaly
    };
    const std::array<std::array<double, 3>, 3> m_protanopia = {{{0.567, 0.433, 0.000},
                                        {0.558, 0.442, 0.000},
                                        {0.000, 0.242, 0.758}}};
    const std::array<std::array<double, 3>, 3> m_protanomaly = {{{0.817, 0.183, 0.000},
                                        {0.333, 0.667, 0.000},
                                        {0.000, 0.125, 0.875}}};
    const std::array<std::array<double, 3>, 3> m_deuteranopia = {{{0.625, 0.375, 0.000},
                                        {0.700, 0.300, 0.000},
                                        {0.000, 0.300, 0.700}}};
    const std::array<std::array<double, 3>, 3> m_deuteranomaly = {{{0.800, 0.200, 0.000},
                                        {0.258, 0.742, 0.000},
                                        {0.000, 0.142, 0.858}}};
    const std::array<std::array<double, 3>, 3> m_tritanopia = {{{0.950, 0.050, 0.000},
                                        {0.000, 0.433, 0.567},
                                        {0.000, 0.475, 0.525}}};
    const std::array<std::array<double, 3>, 3> m_tritanomaly = {{{0.967, 0.033, 0.000},
                                        {0.000, 0.733, 0.267},
                                        {0.000, 0.183, 0.817}}};
    const std::array<std::array<double, 3>, 3> m_achromatopsia = {{{0.299, 0.587, 0.114},
                                        {0.299, 0.587, 0.114},
                                        {0.299, 0.587, 0.114}}};
    const std::array<std::array<double, 3>, 3> m_achromatomaly = {{{0.618, 0.320, 0.062},
                                        {0.163, 0.775, 0.062},
                                        {0.163, 0.320, 0.516}}};
    void init_map(DaltonismType colorblind_type);
}
