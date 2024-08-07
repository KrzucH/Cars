#include <gtest/gtest.h>
#include "Car.hpp"
#include "PetrolEngine.hpp"

struct EngineTest : ::testing::Test {
    PetrolEngine engine{225, 2500, 6};
};

TEST_F(EngineTest, ChangeGearUpTest) {
    for (int i = 1; i <= 6; i++) {
        engine.changeGear(i);
        if (i == 6) {
            EXPECT_NO_THROW(engine.changeGear(i));
        }
    }
}

TEST_F(EngineTest, ChangeGearDownTest) {
    for (int i = 1; i <= 6; i++) {
        if (i == 6) {
            for (int j = 6; j >= -1; --j) {
                engine.changeGear(j);
                if (j == -1) {
                    EXPECT_NO_THROW(engine.changeGear(j));
                }
            }
        } else {
            engine.changeGear(i);
        }
    }
}

TEST_F(EngineTest, ChangeGearUpTestThrow) {
    for (int i = 1; i <= 7; i++) {
        if (i == 7) {
            EXPECT_THROW(engine.changeGear(i), InvalidGear);
        } else {
            engine.changeGear(i);
        }
    }
}

TEST_F(EngineTest, ChangeGearDownTestThrow) {
    for (int i = 1; i <= 6; i++) {
        if (i == 6) {
            for (int j = 6; j >= -2; --j) {
                if (j == -2) {
                    EXPECT_THROW(engine.changeGear(i), InvalidGear);
                } else {
                    engine.changeGear(j);
                }
            }
        } else {
            engine.changeGear(i);
        }
    }
}

TEST_F(EngineTest, RandomGearTest) {
    EXPECT_THROW(engine.changeGear(3), InvalidGear);
    EXPECT_THROW(engine.changeGear(2), InvalidGear);
    EXPECT_THROW(engine.changeGear(-2), InvalidGear);
    EXPECT_THROW(engine.changeGear(5), InvalidGear);
    EXPECT_THROW(engine.changeGear(4), InvalidGear);
    EXPECT_NO_THROW(engine.changeGear(1));
    EXPECT_NO_THROW(engine.changeGear(0));
    EXPECT_NO_THROW(engine.changeGear(-1));
    EXPECT_THROW(engine.changeGear(1), InvalidGear);
    EXPECT_NO_THROW(engine.changeGear(0));
}
