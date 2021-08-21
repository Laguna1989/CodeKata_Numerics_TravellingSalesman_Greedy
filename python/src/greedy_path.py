from calculate_distance import calculate_distance


def find_greedy_path(cities):
    remaining_cities = cities.copy()
    optimized_cities = [remaining_cities.pop(0)]
    while remaining_cities:
        current_city = optimized_cities[-1]
        best_distance = 2.0
        best_index = -1
        for i, city in enumerate(remaining_cities):
            distance = calculate_distance(city, current_city)
            if distance < best_distance:
                best_distance = distance
                best_index = i
        optimized_cities.append(remaining_cities.pop(best_index))

    return optimized_cities

