#include "create_cities.hpp"
#include "point.hpp"
#include <gtest/gtest.h>

TEST(CreateCities, CreatesCorrectAmount)
{
    auto const points = create_cities(5);
    ASSERT_EQ(5, points.size());
}

TEST(CreateCities, CitiesHaveSamePositionsWhenCalledTwiceWithSameSeed)
{
    auto const points1 = create_cities(5, 1);
    auto const points2 = create_cities(5, 1);
    for (auto i = 0U; i != points1.size(); ++i) {
        auto const p1 = points1.at(i);
        auto const p2 = points2.at(i);
        ASSERT_EQ(p1.x, p2.x);
        ASSERT_EQ(p1.y, p2.y);
    }
}

TEST(CreateCities, CitiesHaveDifferentPositionsWhenCalledTwiceWithDifferentSeed)
{
    auto const points1 = create_cities(5, 1);
    auto const points2 = create_cities(5, 21121);
    for (auto i = 0U; i != points1.size(); ++i) {
        auto const p1 = points1.at(i);
        auto const p2 = points2.at(i);
        ASSERT_NE(p1.x, p2.x);
        ASSERT_NE(p1.y, p2.y);
    }
}

TEST(CreateCities, PointsAreInsideRange)
{
    auto points = create_cities(100);
    for (auto i = 0U; i != points.size(); ++i) {
        auto const p1 = points.at(i);
        ASSERT_GE(p1.x, 0.0);
        ASSERT_LE(p1.x, 1.0);

        ASSERT_GE(p1.y, 0.0);
        ASSERT_LE(p1.y, 1.0);
    }
}
