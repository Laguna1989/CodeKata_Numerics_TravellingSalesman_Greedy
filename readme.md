# Overview

This is a Code Nummy about the travelling salesman problem and the greedy solution approach. Please check out the
other [Code Nummies](https://github.com/Laguna1989/CodeNummies_Overview).

# Theory

## The Travelling Salesman problem

The Travelling Salesman Problem describes a salesman who wants to visit `N` cities. He must visit all the cities exactly
once and is looking for the shortest total travelling distance.

The Travelling Salesman Problem is a popular example for a certain class of optimization problems (so-called NP-hard
problems). There are many ways to find a good (though not necessarily optimal) solution.

Details:

* The cities are uniformly distributed on a two-dimensional euclidean plane with x,y in the range `[0,1]`.
* Travel time between two cities is equal to the distance between the two cities.
* There are special versions, in which the salesman has to end at the starting city, but for this Nummy this can be
  omitted.

## The greedy algorithm

A greedy algorithm is one of the simplest ways to solve the problem. Most likely, it will not find the optimal solution
for a given set of cities.

The greedy solution starts at a random city. In every step, the algorithm searches for the nearest neighbor city that
has not yet been visited and chooses this city as the next travelling destination.

# Exercise

* Start with the distance calculation between two Points. Implement the
  function `double calculate_distance(Point const& a, Point const& b)` in the file `src/calculate_distance`. The tests
  in `tests/calculate_distance_test` will test the implementation.
* Next, create the functionality to sample N cities. Implement the
  function `std::vector<Point> create_cities(std::size_t N, std::uint32_t seed = 1)` in the file `src/create_cities`.
  The tests in the file `create_cities_test` will test the implementation.
* Implement a function which calculates the total travel distance for a given set of cities. The
  function `calculate_total_travel_distance(std::vector<Point> const& cities)` can be found in the
  file `src/calculate_total_travel_distance`. The tests in the file `tests/calculate_total_travel_distance` will test
  the implementation.
* Before implementing the actual greedy optimization, let's get a feeling for the average travel distance of the random
  path. Implement the test case `UnoptimizedAveragePath` in the file `tests/statistics_test`. This test should calculate
  the path length for N cities (N = 3, 5, 10, 20, 50, 100, 200, 500), averaged over 1000 random instantiations. Plot the
  data in your favourite plotting program (gnuplot, matplotlib, ...) and see if you can find a relation.
* Now we are done with the helper functions. Implement the greedy algorithm, which optimizes the path as described above
  in the function `std::vector<Point> greedy(std::vector<Point> const& cities)` in the file `src/greedy_algorithm`.
* Create some statistical Analysis for the greedy-optimized solution for N cities (N = 3, 5, 10, 20, 50, 100, 200, 500)
  averaged over 1000 random instantiations. Compare this data to the unoptimized solution

# References

* [Travelling Salesman (wikipedia)](https://en.wikipedia.org/wiki/Travelling_salesman_problem)
