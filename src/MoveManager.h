#ifndef MOVEMANAGER_H
#define MOVEMANAGER_H
#include <vector>
#include <set>
#include <queue>
#include "Grid.h"
#include "Point.h"
#include "Tile.h"
#include "Unit.h"

class MoveManager {
    public:
        MoveManager(Grid& _grid) : grid(_grid) {};
        Grid& grid;
        std::map<Point, Point> parents;
        std::set<Point> calculateMovablePoints(Unit* unit) {
            std::set<Point> visited;
            std::queue<std::pair<Point, int>> toVisit;

            int remainingMov = unit->getMovement();

            visited.insert(unit->getPosition());
            toVisit.push(std::make_pair(unit->getPosition(), remainingMov));

            while(!toVisit.empty()) {
                std::pair<Point, int> currentPointPair = toVisit.front();
                Point currentPoint = currentPointPair.first;
                visited.insert(currentPoint);
                remainingMov = currentPointPair.second;
                toVisit.pop();

                Point topPoint = Point(currentPoint.x, currentPoint.y + 1);
                Point bottomPoint = Point(currentPoint.x, currentPoint.y - 1);
                Point leftPoint = Point(currentPoint.x - 1, currentPoint.y);
                Point rightPoint = Point(currentPoint.x + 1, currentPoint.y);

                std::vector<Point> directions = { topPoint, bottomPoint, leftPoint, rightPoint };

                for(int i = 0; i < directions.size(); i++) {
                    Point targetPoint = directions[i];

                    auto visitedItr = visited.find(targetPoint);
                    auto unitLocs = grid.getUnitLocations();
                    auto unitItr = unitLocs.find(targetPoint);
                    

                    if(grid.validatePoint(targetPoint) && visitedItr == visited.end() && unitItr == unitLocs.end()) {
                        
                        Tile targetTile = grid.getTileAtPoint(targetPoint);

                        if(remainingMov >= targetTile.getMovementCost()) {
                            
                            auto targetPair = std::make_pair(targetPoint, remainingMov - targetTile.getMovementCost());
                            toVisit.push(targetPair);

                            parents[targetPoint] = currentPoint;
                        }
                    }
                }
            }

            return visited;
        }
        std::set<Point> getAttackTargets(Unit* unit) {

            std::set<Point> targets;

            Point currentPoint = unit->getPosition();
            Point topPoint = Point(currentPoint.x, currentPoint.y + 1);
            Point bottomPoint = Point(currentPoint.x, currentPoint.y - 1);
            Point leftPoint = Point(currentPoint.x - 1, currentPoint.y);
            Point rightPoint = Point(currentPoint.x + 1, currentPoint.y);

            std::vector<Point> directions = { topPoint, bottomPoint, leftPoint, rightPoint };

            for(int i = 0; i < directions.size(); i++) {
                Point targetPoint = directions[i];

                auto unitLocs = grid.getUnitLocations();
                auto unitItr = unitLocs.find(targetPoint);

                if(unitItr != unitLocs.end()) {
                    
                    targets.insert(targetPoint);
                }
            }

            return targets;
        }
};

#endif