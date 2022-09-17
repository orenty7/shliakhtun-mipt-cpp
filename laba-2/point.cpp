#include "point.h"

using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) < (y) ? (y) : (x))

Point::Point(ull x, ull y): x(x), y(y) {}

Point Point::minx(const Point &other) const {
    return Point(MIN(x, other.x), y);
}
Point Point::miny(const Point &other) const {
    return Point(x, MIN(y, other.y));
}
Point Point::maxx(const Point &other) const {
    return Point(MAX(x, other.x), y);
}
Point Point::maxy(const Point &other) const {
    return Point(x, MAX(y, other.y));
}

ostream& operator<<(ostream &out, const Point &point) {
    out << "(" << point.x << "," << point.y << ")";
    return out;
}
