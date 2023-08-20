#pragma once

#include <stdexcept>
#include <string>
#include <vector>

#include "../command/command.hpp"

namespace cman {

class Reader {
 public:
  Reader();
  ~Reader();

  Command *interpret(std::vector<std::string> &, int);
};

}  // namespace cman
