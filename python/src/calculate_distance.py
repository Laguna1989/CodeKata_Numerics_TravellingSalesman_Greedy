from math import sqrt


def calculate_distance(cityA, cityB):
    return sqrt((cityA.x - cityB.x) ** 2 + (cityA.y - cityB.y) ** 2)
