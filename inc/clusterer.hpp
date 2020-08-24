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

    void operator()(int numberOfClusters) {
      dlib::kkmeans<kernel_type> kMeans(kCentroid);

      std::vector<sample_type> samples;
      std::vector<sample_type> initialCenters;

      for (auto const & point: data)
        samples.push_back({ point.x, point.y });

      data.clear();

      kMeans.set_number_of_centers(numberOfClusters);
      pick_initial_centers(
          numberOfClusters,
          initialCenters,
          samples,
          kMeans.get_kernel());

      kMeans.train(samples, initialCenters);

      for (auto const &i: samples) data.push_back({kMeans(i), i(0), i(1)});
    }

  private:
    using sample_type = dlib::matrix<float, 2, 1>;
    using kernel_type = dlib::radial_basis_kernel<sample_type>;

    std::vector<Point> & data;
    dlib::kcentroid<kernel_type> kCentroid;
  };
}
