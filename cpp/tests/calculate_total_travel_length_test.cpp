#include "calculate_total_travel_distance.hpp"
#include "point.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(CalculateTravelLengthTest, ZeroCitiesResultInZeroLength)
{
    std::vector<Point> const cities;
    ASSERT_EQ(0.0, calculate_total_travel_distance(cities));
}

TEST(CalculateTravelLengthTest, OneCitiesResultInZeroLength)
{
    std::vector<Point> const cities { Point { 0.0, 1.0 } };

    ASSERT_EQ(0.0, calculate_total_travel_distance(cities));
}

TEST(CalculateTravelLengthTest, TwoCitiesResultInCorrectLength)
{
    std::vector<Point> const cities { Point { 0.0, 0.0 }, Point { 1.0, 0.0 } };

    ASSERT_EQ(1.0, calculate_total_travel_distance(cities));
}

TEST(CalculateTravelLengthTest, ManyCitiesResultInCorrectLength)
{
    std::vector<Point> const cities { Point { 0.0, 0.0 }, Point { 1.0, 0.0 }, Point { 1.0, 1.0 },
        Point { 0.0, 1.0 }, Point { 0.0, 0.0 } };

    ASSERT_EQ(4.0, calculate_total_travel_distance(cities));
}
