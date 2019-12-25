#ifndef TURNMANAGER_H
#define TURNMANAGER_H

#include <vector>
#include "Unit.h"

bool compareSpeed(Unit *unit1, Unit *unit2) {
            return unit1->getActiveSpeed() > unit2->getActiveSpeed();
        }

class TurnManager {
    public:
        TurnManager(std::vector<Unit*> units) : turnOrder(units) {};
        std::vector<Unit*> turnOrder;
        int activeSpeedLimit = 100;
        Unit* getActiveUnit() {
            std::sort(turnOrder.begin(), turnOrder.end(), compareSpeed);
            while(turnOrder[0]->getActiveSpeed() < activeSpeedLimit) {
                for(int i=0; i<turnOrder.size(); i++) {
                    turnOrder[i]->incrementActiveSpeed();
                }
                std::sort(turnOrder.begin(), turnOrder.end(), compareSpeed);
            }
            turnOrder[0]->resetActiveSpeed();
            return turnOrder[0];
        }
};

#endif