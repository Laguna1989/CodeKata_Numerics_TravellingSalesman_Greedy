import pytest

from city import create_cities

@pytest.mark.parametrize("amount", [1, 2, 5, 10, 20, 30])
def test_create_cities_returns_correct_amount_of_cities(amount):
    cities = create_cities(amount)

    assert len(cities) == amount