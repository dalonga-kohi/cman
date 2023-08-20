#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "lib/reader/reader.hpp"

int main(int argc, char *argv[]) {
  std::vector<std::string> input = {argv[0], argv[1]};
  std::unique_ptr<cman::Reader> rd = std::make_unique<cman::Reader>();
  std::unique_ptr<cman::Command> cmd = std::make_unique<cman::Invalid>();

  cmd.reset(rd->interpret(input, argc));
  std::cout << cmd->execute() << std::endl;
  cmd.reset(nullptr);
  rd.reset(nullptr);

  return 0;
}
