#include "calculate_total_travel_distance.hpp"
#include "calculate_distance.hpp"

double calculate_total_travel_distance(std::vector<Point> const& cities)
{
    if (cities.size() <= 1) {
        return 0.0;
    }
    double summed_travel_distance = 0.0;
    for (auto i = 1U; i != cities.size(); ++i) {
        auto const p1 = cities.at(i - 1);
        auto const p2 = cities.at(i);
        summed_travel_distance += calculate_distance(p1, p2);
    }

    return summed_travel_distance;
}
