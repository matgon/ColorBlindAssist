#pragma once

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
    const double m_protanopia[3][3] = {{0.567, 0.433, 0.000},
                                        {0.558, 0.442, 0.000},
                                        {0.000, 0.242, 0.758}};
    const double m_protanomaly[3][3] = {{0.817, 0.183, 0.000},
                                        {0.333, 0.667, 0.000},
                                        {0.000, 0.125, 0.875}};
    const double m_deuteranopia[3][3] = {{0.625, 0.375, 0.000},
                                        {0.700, 0.300, 0.000},
                                        {0.000, 0.300, 0.700}};
    const double m_deuteranomaly[3][3] = {{0.800, 0.200, 0.000},
                                        {0.258, 0.742, 0.000},
                                        {0.000, 0.142, 0.858}};
    const double m_tritanopia[3][3] = {{0.950, 0.050, 0.000},
                                        {0.000, 0.433, 0.567},
                                        {0.000, 0.475, 0.525}};
    const double m_tritanomaly[3][3] = {{0.967, 0.033, 0.000},
                                        {0.000, 0.733, 0.267},
                                        {0.000, 0.183, 0.817}};
    const double m_achromatopsia[3][3] = {{0.299, 0.587, 0.114},
                                        {0.299, 0.587, 0.114},
                                        {0.299, 0.587, 0.114}};
    const double m_achromatomaly[3][3] = {{0.618, 0.320, 0.062},
                                        {0.163, 0.775, 0.062},
                                        {0.163, 0.320, 0.516}};
}
