#pragma once
#include <stdexcept>
#include "Car.hpp"

struct InvalidGear : public std::range_error {
    InvalidGear(std::string msg)
        : std::range_error(msg) {}
};

class PetrolEngine {
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int);
    // int currentGear_;
    // bool invalidGear(int);

private:
    int power_;       // in HP
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;
    bool invalidGear(int);
};
