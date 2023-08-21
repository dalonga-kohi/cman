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
  Command *interpret(const std::vector<std::string> &) const;
  Command *interpret(const std::vector<std::string> &, int) const;
};

}  // namespace cman
