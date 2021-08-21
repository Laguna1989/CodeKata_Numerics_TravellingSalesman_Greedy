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


def create_cities(amount: int, rng=random):
    cities = []
    for i in range(amount):
        cities.append(City(rng(), rng()))
    return cities
