#pragma once

#include <dlib/clustering.h>
#include <optional>
#include <vector>

namespace otus {
  struct Point {
    using Cluster = std::optional<unsigned long>;

    Cluster cluster { };
    float x { }, y { };
  };

  class Clusterer {
  public:
    Clusterer(std::vector<Point> &data, float gamma=0.1, float accuracy=0.01):
    data(data),
    kCentroid(kernel_type(gamma), accuracy) { }

    void operator()(int numberOfClusters);

  private:
    using sample_type = dlib::matrix<float, 2, 1>;
    using kernel_type = dlib::radial_basis_kernel<sample_type>;

    std::vector<Point> & data;
    dlib::kcentroid<kernel_type> kCentroid;
  };
}
