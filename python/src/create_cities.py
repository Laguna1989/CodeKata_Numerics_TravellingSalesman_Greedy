from random import random

from city import City


def create_cities(amount: int):
    cities = []
    for i in range(amount):
        cities.append(City(random(), random()))
    return cities