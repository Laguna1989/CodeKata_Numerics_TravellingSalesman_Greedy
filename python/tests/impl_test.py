import pytest

from src.city import compute_distance, City


def test_distance_calculation_returns_correct_value():
    cityA = City(1.0, 1.0)
    cityB = City(0.5, 1.0)

    distance = compute_distance(cityA, cityB)

    assert distance == pytest.approx(0.5)
