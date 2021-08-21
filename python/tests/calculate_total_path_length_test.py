import pytest

from city import City, create_cities, calculate_total_path_length


@pytest.mark.parametrize("amount", [0, 1])
def test_calculate_total_path_length_for_zero_length(amount):
    cities = create_cities(amount)

    assert calculate_total_path_length(cities) == pytest.approx(0.0)


def test_calculate_total_path_legnth_correct_result():
    cities = [City(0.0, 0.0), City(1.0, 0.0)]
    assert calculate_total_path_length(cities) == pytest.approx(1.0)


def test_calculate_total_path_legnth_correct_result_for_full_square():
    cities = [City(0.0, 0.0), City(1.0, 0.0), City(1.0, 1.0), City(0.0, 1.0), City(0.0, 0.0)]
    assert calculate_total_path_length(cities) == pytest.approx(4.0)
