#include <iostream>

#include "clusterer.hpp"

using namespace std;
using namespace otus;

int main() {
  int numberOfClusters { 3 }; // TODO

  std::vector<Point> points { };

  float x, y;
  char ch;

  while (cin >> x >> ch >> y >> ch)
    points.push_back({ Point::Cluster(), x, y});

  Clusterer clusterer { points, 0.001 };
  clusterer(numberOfClusters);

  for (auto const &point: points) {
    cout << point.cluster.value() << ';' << point.x << ';' << point.y << '\n';
  }
}
