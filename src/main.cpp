#include <iostream>
#include <vector>

#include <dlib/clustering.h>
#include <dlib/rand.h>

using namespace std;
using namespace dlib;

int main() {
    using sample_type = matrix<float, 2, 1>;

    using kernel_type = radial_basis_kernel<sample_type>;

    kcentroid<kernel_type> kc(kernel_type(0.1), 0.01);

    kkmeans<kernel_type> test(kc);

    std::vector<sample_type> samples;
    std::vector<sample_type> initial_centers;

    samples.push_back({ 0.0, 0.0 });

    test.set_number_of_centers(3);

    pick_initial_centers(3, initial_centers, samples, test.get_kernel());

    test.train(samples, initial_centers);

    for (auto const &i: samples) {
      cout << i(0) << ';' << i(1) << ';' << test(i) << endl;
    }
}
