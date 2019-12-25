#include "Unit.h"

void Unit::attack(Unit& target) {
    target.setHp(target.getHp() - std::max(atk - target.def, 0));
}