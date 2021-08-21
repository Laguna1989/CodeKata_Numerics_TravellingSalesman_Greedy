from calculate_distance import calculate_distance


def calculate_total_travel_distance(cities):
    distance_sum = 0.0
    for i in range(1, len(cities)):
        distance_sum += calculate_distance(cities[i - 1], cities[i])

    return distance_sum