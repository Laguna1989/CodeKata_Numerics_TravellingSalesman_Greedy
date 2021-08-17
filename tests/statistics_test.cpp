#include "calculate_total_travel_distance.hpp"
#include "create_cities.hpp"
#include "greedy_algorithm.hpp"
#include <gtest/gtest.h>

TEST(StatisticsTest, UnoptimizedAveragePath)
{
    std::vector<std::size_t> const city_sizes { 3, 5, 10, 20, 50, 100, 200, 500 };
    std::size_t average = 10000;

    for (auto const number_of_cities : city_sizes) {
        double path_length = 0;
        for (auto i = 0U; i != average; ++i) {
            auto const cities = create_cities(number_of_cities, number_of_cities + i);
            path_length += calculate_total_travel_distance(cities);
        }
        std::cout << number_of_cities << " " << path_length / average << std::endl;
    }
}

TEST(StatisticsTest, OptimizedAveragePath)
{
    std::vector<std::size_t> const city_sizes { 3, 5, 10, 20, 50, 100, 200, 500 };
    std::size_t average = 1000;

    for (auto const number_of_cities : city_sizes) {
        double path_length = 0;
        for (auto i = 0U; i != average; ++i) {
            auto const cities = create_cities(number_of_cities, number_of_cities + i);
            auto optimized_cities = greedy(cities);
            path_length += calculate_total_travel_distance(optimized_cities);
        }
        std::cout << number_of_cities << " " << path_length / average << std::endl;
    }
}
