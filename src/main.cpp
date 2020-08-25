#include <iostream>

#include "clusterer.hpp"
#include "get_arg.hpp"

using namespace std;
using namespace otus;

int main(int argc, char const ** argv) {
  int numberOfClusters;

  try {
    numberOfClusters = get_arg(argc, argv);
  }
  catch (InvalidArgument const &e) {
    cerr << "Error: " << e.what() << endl;
    return 1;
  }

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
