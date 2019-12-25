#ifndef GRID_H
#define GRID_H
#include <map>
#include "Tile.h"
#include "Unit.h"
#include "Point.h"

class Grid {
    public:
        Grid(int _width, int _length);
        int getWidth() {
            return width;
        }
        int getLength() {
            return length;
        }
        Tile getTileAtPoint(Point p);
        std::map<Point, Unit*> getUnitLocations() {
            return unitLocations;
        }
        void updateUnitPosition(Point unitLocation, Unit& unit);
        bool validatePoint(Point p);
    private:
        int width;
        int length;
        std::map<Point, Tile> tiles;
        std::map<Point, Unit*> unitLocations;
};

#endif