import pytest

from city import create_cities

import random


@pytest.mark.parametrize("amount", [1, 2, 5, 10, 20, 30])
def test_create_cities_returns_correct_amount_of_cities(amount):
    cities = create_cities(amount)

    assert len(cities) == amount


@pytest.mark.parametrize("amount", [2, 5, 10, 20, 30])
def test_create_cities_returns_unique_cities(amount):
    cities = create_cities(amount)

    assert len(set(cities)) == len(cities)


@pytest.mark.parametrize("seed, amount", [(1, 1), (1, 2), (2, 2), (1, 5), (2, 10)])
def test_create_cities_returns_random_cities(seed, amount):
    random.seed(seed)
    citiesA = create_cities(amount)
    citiesB = create_cities(amount)

    assert not set(citiesA).intersection(set(citiesB))
