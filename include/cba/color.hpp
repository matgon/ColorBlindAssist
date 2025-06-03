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
}
