#ifndef POINT_H
#define POINT_H
#include <string>

class Point {
    public:
        Point() {
            x = 0;
            y = 0;
        }
        Point(int _x, int _y) : x(_x), y(_y) {};
        int x;
        int y;
        std::string toString() const {
            return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
        }
        bool operator== (const Point &p1) const {
            if(p1.x == x && p1.y == y) {
                return true;
            }
            return false;
        }
        bool operator< (const Point &p1) const {
            if(x < p1.x) {
                return true;
            }
            if(x == p1.x) {
                if(y < p1.y) {
                    return true;
                }
            }
            return false;
        }

        bool operator!= (const Point &p1) const {
            return x != p1.x || y != p1.y;
        }
};

#endif