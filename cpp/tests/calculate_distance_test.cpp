#include "calculate_distance.hpp"
#include "point.hpp"
#include <cmath>
#include <gtest/gtest.h>

TEST(CalculateDistance, SamePointReturnsZero)
{
    Point p { 0.25, 0.74 };
    double const expected_distance = 0.0;
    ASSERT_DOUBLE_EQ(expected_distance, calculate_distance(p, p));
}

TEST(CalculateDistance, DistanceX)
{
    Point p1 { 0.0, 0.0 };
    Point p2 { 0.5, 0.0 };
    double const expected_distance = 0.5;
    ASSERT_DOUBLE_EQ(expected_distance, calculate_distance(p1, p2));
}

TEST(CalculateDistance, DistanceX2)
{
    Point p1 { 0.5, 0.0 };
    Point p2 { 0.0, 0.0 };
    double const expected_distance = 0.5;
    ASSERT_DOUBLE_EQ(expected_distance, calculate_distance(p1, p2));
}

TEST(CalculateDistance, DistanceY)
{
    Point p1 { 0.0, 0.0 };
    Point p2 { 0.0, 0.1 };
    double const expected_distance = 0.1;
    ASSERT_DOUBLE_EQ(expected_distance, calculate_distance(p1, p2));
}

TEST(CalculateDistance, DistanceXY)
{
    Point p1 { 0.0, 0.0 };
    Point p2 { 1.0, 1.0 };
    double const expected_distance = sqrt(2);
    ASSERT_DOUBLE_EQ(expected_distance, calculate_distance(p1, p2));
}
