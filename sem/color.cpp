#ifndef COLOR_CPP
#define COLOR_CPP

#include<iostream>

using namespace std;


struct Color {
    double r, g, b;
    
    Color(double r, double g, double b): r(r), g(g), b(b) {}
    Color(double gr): Color(gr, gr, gr) {}
    Color(): Color(0, 0, 0) {}

    friend ostream& operator<<(ostream &out, Color color) {
        out << (char) (color.r * 255)
            << (char) (color.g * 255)
            << (char) (color.b * 255);

        return out;
    }
};
#endif
