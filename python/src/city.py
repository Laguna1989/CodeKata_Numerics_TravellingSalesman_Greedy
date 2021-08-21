from math import sqrt


class City:
    def __init__(self, x, y):
        self.x = x
        self.y = y


def compute_distance(cityA: City, cityB: City):
    return sqrt((cityA.x - cityB.x) ** 2 + (cityA.y - cityB.y) ** 2)