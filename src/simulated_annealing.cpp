#include "simulated_annealing.hpp"
#include "calculate_total_travel_distance.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <random>

std::vector<Point> simulated_annealing(std::vector<Point> const& cities, double T0, uint32_t seed)
{
    std::default_random_engine rng { seed };
    std::uniform_real_distribution<double> dist_real { 0.0, 1.0 };
    std::uniform_int_distribution<size_t> dist_int { 0U, cities.size() - 1 };
    if (cities.size() <= 2) {
        return cities;
    }
    double t_factor = pow(0.9999, 1.0 / cities.size());

    std::vector<Point> optimized_cities { cities };
    double T = T0;
    while (true) {
        if (T <= 1e-4) {
            break;
        }

        double const L0 = calculate_total_travel_distance(optimized_cities);

        auto iter1 = optimized_cities.begin() + dist_int(rng);
        auto iter2 = optimized_cities.begin() + dist_int(rng);
        std::iter_swap(iter1, iter2);

        double const L1 = calculate_total_travel_distance(optimized_cities);

        if (L1 < L0) {
            continue;
        } else {
            auto const probability = exp(-(L1 - L0) / T);
            auto const v = dist_real(rng);
            if (v >= probability) {
                // swap back
                std::iter_swap(iter1, iter2);
            }
        }

        T *= t_factor;
    }
    return optimized_cities;
}
