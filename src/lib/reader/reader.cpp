#include "reader.hpp"

using namespace cman;

Reader::Reader() {}

Command* Reader::interpret(std::vector<std::string>& args, int len) {
  return new Invalid;
}
