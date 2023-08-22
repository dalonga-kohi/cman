#include <stdexcept>
#include <string>

#include "command.hpp"

using namespace cman;

Init::Init() : Command() {
  try {
    msg = load("init");
    hint = load("init-hint");
  } catch (std::runtime_error& e) {
    std::cout << e.what() << std::endl;
  }
}

std::string Init::execute() noexcept { return hint; }
