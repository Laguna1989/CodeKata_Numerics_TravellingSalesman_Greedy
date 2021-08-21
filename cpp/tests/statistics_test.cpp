#include "calculate_total_travel_distance.hpp"
#include "create_cities.hpp"
#include "greedy_algorithm.hpp"
#include <gtest/gtest.h>

TEST(StatisticsTest, UnoptimizedAveragePath)
{
    std::vector<std::size_t> const city_sizes { 3, 5, 10, 20, 50, 100, 200, 500 };
    std::size_t average = 10000;
}

TEST(StatisticsTest, OptimizedAveragePath)
{
    std::vector<std::size_t> const city_sizes { 3, 5, 10, 20, 50, 100, 200, 500 };
    std::size_t average = 1000;
}
