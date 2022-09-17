#ifndef POINT_H
#define POINT_H

#include<iostream>

using ull = unsigned long long;

struct Point {
    ull x, y;
    Point(ull, ull);
    Point minx(const Point &) const;
    Point miny(const Point &) const;
    Point maxx(const Point &) const;
    Point maxy(const Point &) const;
    
    friend std::ostream& operator<<(std::ostream &out, const Point &);
};

#endif
