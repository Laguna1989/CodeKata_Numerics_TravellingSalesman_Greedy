import pytest
from matplotlib import pyplot as plt

from calculate_total_travel_distance import calculate_total_travel_distance
from create_cities import create_cities
from greedy_path import find_greedy_path


def test_statistics():
    number_of_averages = 100
    city_amounts = [3, 5, 10, 20,50,100, 200]
    average_default_lengths = []
    average_optimized_lengths = []
    for number_of_cities in city_amounts:

        default_length_sum = 0.0
        optimized_length_sum = 0.0
        for n in range (number_of_averages):
            cities = create_cities(number_of_cities)
            default_length = calculate_total_travel_distance(cities)
            default_length_sum += default_length

            greedy_path = find_greedy_path(cities)
            greedy_length = calculate_total_travel_distance(greedy_path)
            optimized_length_sum += greedy_length

        average_default_lengths.append(float(default_length_sum)/float(number_of_averages))
        average_optimized_lengths.append(float(optimized_length_sum) / float(number_of_averages))

    fig = plt.figure()
    ax = fig.add_subplot()
    ax.scatter(city_amounts, average_default_lengths, label='default')
    ax.scatter(city_amounts, average_optimized_lengths, label='greedy')

    ax.legend()

    plt.show()