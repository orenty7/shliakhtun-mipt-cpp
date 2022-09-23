#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;

class GeomFig {
public:
    virtual double area() const = 0;
};

class Circle : public GeomFig {
    double r;
public:
    Circle(double r): r(r) {}
    
    double area() const override {
        return r * r * M_PI / 2;
    }
};


class Square : public GeomFig {
    double a;
public:
    Square(double a): a(a) {}
    
    double area() const override {
        return a * a;
    }
};

double sumArea(vector<GeomFig *> &figures){
    double area = 0;
    for(const GeomFig *figure : figures) {
        area += figure->area();
    }
    return area;
}

int main() {
    Square a = Square(10);
    Circle b = Circle(10);
    vector<GeomFig *> figures;
    
    figures.push_back(&a);
    cout << sumArea(figures) << endl;
    
    figures.push_back(&b);
    cout << sumArea(figures) << endl;
    
    return 0;
}


    
