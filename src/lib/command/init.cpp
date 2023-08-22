#include "command.hpp"

using namespace cman;

Command* Init::set_arguments(Arguments args) {
  arguments = args;
  return this;
}
