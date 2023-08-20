#include "reader.hpp"

using namespace cman;

Reader::Reader() {}

Command* Reader::interpret(std::vector<std::string>& args, int len) {
  if (len == 1) return new Invalid;
  if (args[1] != "run") return new Invalid;
  return new Invalid;
}

Reader::~Reader() {}
