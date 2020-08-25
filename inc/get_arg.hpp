#pragma once

#include <cstring>
#include <stdexcept>

namespace otus {
  class InvalidArgument: public std::logic_error {
  public:
    explicit InvalidArgument(const std::string &input):
    std::logic_error(input) { }
  };

  int get_arg(int argc, char const *argv[]);
}
