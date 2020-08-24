#include <iostream>

#include "clusterer.hpp"

using namespace std;
using namespace otus;

int main() {
  std::vector<Point> points { };
  for (int i { }; i < 100; ++i)
    points.push_back({ Point::Cluster(), float(i), float(i) });
  Clusterer clusterer { points };
  clusterer(3);

  for (auto const &point: points) {
    cout << point.cluster.value() << ';' << point.x << ';' << point.y << '\n';
  }
}
