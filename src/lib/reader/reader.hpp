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
  Command *interpret(Arguments) const;
  Command *interpret(Arguments, int) const;

 private:
  std::map<std::string, Command *> command_aliases;
  Command *initialize_command(Arguments) const;
};

}  // namespace cman
