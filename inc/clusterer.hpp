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
    kCentroid(KernelType(gamma), accuracy) { }

    void operator()(int numberOfClusters);

  private:
    using SampleType = dlib::matrix<float, 2, 1>;
    using KernelType = dlib::radial_basis_kernel<SampleType>;

    std::vector<Point> & data;
    dlib::kcentroid<KernelType> kCentroid;
  };
}
