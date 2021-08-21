from city import create_cities, calculate_total_path_length
from greedy_path import find_greedy_path


def test_greedy_algorithm_returns_better_than_initial_path():
    cities = create_cities(10)

    default_length = calculate_total_path_length(cities)
    greedy_path = find_greedy_path(cities)
    greedy_length = calculate_total_path_length(greedy_path)

    assert greedy_length < default_length
