#pragma once

#include <stdexcept>
#include <string>
#include <vector>

#include "../command/command.hpp"

namespace cman {

class Reader {
 public:
  Reader();
  Reader(Reader &&) = default;
  Reader(const Reader &) = default;
  Reader &operator=(Reader &&) = default;
  Reader &operator=(const Reader &) = default;
  bool operator==(Reader &&);
  bool operator==(const Reader &);

  Command *interpret(std::vector<std::string> &, int);

  ~Reader();
};

}  // namespace cman
