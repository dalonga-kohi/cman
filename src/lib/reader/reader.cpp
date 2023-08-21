#include "reader.hpp"

using namespace cman;

Reader::Reader() {}

Command* Reader::interpret(const std::vector<std::string>& args,
                           int len) const {
  if (len == 1) return new Invalid;
  if (args[1] != "run") return new Invalid;
  return new Invalid;
}

Command* Reader::interpret(const std::vector<std::string>& args) const {
  int len = args.size();
  if (len == 1) return new Invalid;
  if (args[1] != "run") return new Invalid;
  return new Invalid;
}

Reader::~Reader() {}
