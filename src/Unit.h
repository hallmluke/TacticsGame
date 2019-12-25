#ifndef UNIT_H
#define UNIT_H
#include <string>
#include "Point.h"

enum allegiance { Ally, Enemy, Neutral };
enum state { Alive, Dead };

class Unit {
    public:
        Unit() {
            level = 1;
            name = "Unit";
            army = Ally;
            hp = 10;
            atk = 5;
            def = 2;
            speed = 4;
            activeSpeed = 0;
            movement = 5;
            position = Point(0, 0);
        }
        Unit(std::string _name) {
            level = 1;
            name = _name;
            army = Enemy;
            hp = 10;
            atk = 5;
            def = 2;
            speed = 6;
            activeSpeed = 0;
            movement = 5;
            position = Point(1, 0);
        }
        Point getPosition() {
            return position;
        }
        void movePosition(Point newPosition) {
            position = newPosition;
        }
        std::string getName(){
            return name;
        }
        int getHp() {
            return hp;
        }
        void setHp(int _hp) {
            hp = _hp;
        }
        int getDef() {
            return def;
        }
        int getMovement() {
            return movement;
        }
        void incrementActiveSpeed() {
            activeSpeed += speed;
        }
        void resetActiveSpeed() {
            activeSpeed = 0;
        }
        int getActiveSpeed() {
            return activeSpeed;
        }
        void attack(Unit& target);
    private:
        Point position;
        int level;
        std::string name;
        allegiance army;
        int hp;
        int atk;
        int def;
        int speed;
        int activeSpeed;
        int movement;
};

#endif