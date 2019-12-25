#include <iostream>
#include "Tile.h"
#include "Grid.h"

Grid::Grid(int _width, int _length) : width(_width), length(_length) {
    for(int x = 0; x < width; x++) {
        for(int y = 0; y < length; y++) {
            Point tilePoint = Point(x,y);
            Tile standardTile = Tile(1);
            tiles.insert(std::pair <Point, Tile> (tilePoint, standardTile));
        }
    }
}

Tile Grid::getTileAtPoint(Point p){
    auto tileItr = tiles.find(p);
    return tileItr->second;
}

void Grid::updateUnitPosition(Point unitLocation, Unit& unit) {
    Grid::unitLocations.erase(unit.getPosition());
    unit.movePosition(unitLocation);
    Grid::unitLocations[unitLocation] = &unit;
}

bool Grid::validatePoint(Point p) {
    if(p.x >= width || p.x < 0 || p.y >= length || p.y < 0) {
        return false;
    }
    return true;
}