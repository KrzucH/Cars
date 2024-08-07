#include "PetrolEngine.hpp"
#include <iostream>

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power), capacity_(capacity), gears_(gears), currentGear_(0) {
    // std::cout << __FUNCTION__ << std::endl;
}

bool PetrolEngine::invalidGear(int gear) {
    if (gear <= gears_ && gear >= -1) {
        return currentGear_ + 1 == gear || currentGear_ - 1 == gear || currentGear_ == gear;
    } else {
        return false;
    }
}

void PetrolEngine::changeGear(int gear) {
    if (invalidGear(gear)) {
        currentGear_ = gear;
    } else {
        throw InvalidGear("Wrong Gear!!!");
    }
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL
    // std::cout << __FUNCTION__ << std::endl;
}
