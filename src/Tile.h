#ifndef TILE_H
#define TILE_H

class Tile {
    public:
        Tile(int _movementCost) : movementCost(_movementCost) {};
        int getMovementCost(){
            return movementCost;
        }
    private:
        int terrain;
        int movementCost;
};

#endif