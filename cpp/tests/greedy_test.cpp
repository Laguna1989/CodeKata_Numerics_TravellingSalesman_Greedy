#include "calculate_distance.hpp"
#include "calculate_total_travel_distance.hpp"
#include "create_cities.hpp"
#include "greedy_algorithm.hpp"
#include <gtest/gtest.h>

TEST(TSPGreedyTest, TwoCitiesPathLengthDoesNotChange)
{
    std::vector<Point> const initial_cities = create_cities(2);
    double const initial_length = calculate_total_travel_distance(initial_cities);

    auto const optimized_path = greedy(initial_cities);
    double const optimized_length = calculate_total_travel_distance(optimized_path);
    ASSERT_EQ(initial_length, optimized_length);
}

TEST(TSPGreedyTest, ThreeCitiesAreReordered)
{
    std::vector<Point> const initial_cities { Point { 0.0, 0.0 }, Point { 1.0, 0.0 },
        Point { 0.5, 0.0 } };

    auto const optimized_path = greedy(initial_cities);

    ASSERT_EQ(optimized_path.at(1).x, 0.5);
}
