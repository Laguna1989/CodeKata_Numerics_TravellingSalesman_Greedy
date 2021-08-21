from calculate_total_travel_distance import calculate_total_travel_distance
from create_cities import create_cities
from greedy_path import find_greedy_path


def test_greedy_algorithm_returns_better_than_initial_path():
    cities = create_cities(10)

    default_length = calculate_total_travel_distance(cities)
    greedy_path = find_greedy_path(cities)
    greedy_length = calculate_total_travel_distance(greedy_path)

    assert greedy_length < default_length
