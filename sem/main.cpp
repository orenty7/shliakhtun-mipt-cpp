#include <iostream>
#include <fstream>
#include <vector>

#include "color.cpp"
#include "image.h"

using namespace std;

struct Point {
    double x, y;
    double charge;
    Point(double x, double y, double charge = 1): x(x), y(y), charge(charge) {}
};

void save(vector<Color> &image) {
    ofstream fout;
    fout.open("image.ppm");
    fout << "P6" << endl;
    fout << width << " " << height << endl;
    fout << 255 << endl;

    for(int y = 0; y < height; y ++) {
        for(int x = 0; x < width; x ++) {
            fout << image[y * width + x];
        }
    }
    fout.close();
    
}


    
int main() {
    vector<Point> scene = { {0, 0, 1} };
    vector<Color> image;
    image.reserve(1920 * 1080);
    for(int y = 0; y < height; y ++)
        for(int x = 0; x < width; x ++)
            image.push_back(background);

    
    
    save(image);
    return 0;
}
