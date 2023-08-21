#pragma once

#include <map>
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

 private:
  std::map<std::string, Command *> command_aliases;
};

}  // namespace cman
