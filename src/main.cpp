#include <iostream>
#include "Grid.h"
#include "MoveManager.h"
#include "TurnManager.h"

int main() {
    Grid env = Grid(5,5);

    Unit unit = Unit();
    Unit unit2 = Unit("Ramza");

    env.updateUnitPosition(unit.getPosition(), unit);
    env.updateUnitPosition(unit2.getPosition(), unit2);

    std::vector<Unit*> units;
    units.push_back(&unit);
    units.push_back(&unit2);
    
    MoveManager movemanager = MoveManager(env);
    TurnManager turnManager = TurnManager(units);

    

    for(int i=0; i<5; i++) {
        auto activeUnit = turnManager.getActiveUnit();
        auto points = movemanager.calculateMovablePoints(activeUnit);

        std::cout << "Movable points: " << std::endl;
        for(auto it = points.begin(); it != points.end(); it++) {
            std::cout << it->toString() << std::endl;
        
        }
        std::cout << activeUnit->getName() << " " << activeUnit->getPosition().toString() << std::endl;
        std::cout << "HP: " << activeUnit->getHp() << std::endl;
        std::cout << "x coord: " << std::endl;
        int x;
        std::cin >> x;
        std::cout << "y coord: " << std::endl;
        int y;
        std::cin >> y;
        auto pointItr = points.find(Point(x,y));
        if(pointItr != points.end()) {
            env.updateUnitPosition(Point(x,y), *activeUnit);
        } else {
            std::cout << "Invalid point to move, skipping your turn" << std::endl;
            continue;
        }

        auto targets = movemanager.getAttackTargets(activeUnit);

        if(targets.size() > 0) {
            std::cout << "Input point to attack" << std::endl;
            for(auto it = targets.begin(); it != targets.end(); it++) {
            std::cout << it->toString() << std::endl;
        
        }
        std::cout << "x coord: " << std::endl;
        int x;
        std::cin >> x;
        std::cout << "y coord: " << std::endl;
        int y;
        std::cin >> y;
        auto targItr = targets.find(Point(x,y));
        if(targItr != targets.end()) {
            auto unitAtPoint = env.getUnitLocations()[*targItr];
            activeUnit->attack(*unitAtPoint);
        } else {
            std::cout << "Invalid point to attack, skipping your turn" << std::endl;
            continue;
        }
        }
    }
}