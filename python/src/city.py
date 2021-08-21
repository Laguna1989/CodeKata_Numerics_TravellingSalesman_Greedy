from math import sqrt
from random import random


class City:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def __hash__(self):
        return hash((self.x, self.y))


def compute_distance(cityA: City, cityB: City):
    return sqrt((cityA.x - cityB.x) ** 2 + (cityA.y - cityB.y) ** 2)


def create_cities(amount: int):
    cities = []
    for i in range(amount):
        cities.append(City(random(), random()))
    return cities


def calculate_total_path_length(cities):
    distance_sum = 0.0
    for i in range(1, len(cities)):
        distance_sum += compute_distance(cities[i - 1], cities[i])

    return distance_sum
