#include "reader.hpp"

using namespace cman;

Reader::Reader() {
  command_aliases["init"] = new Init;
  command_aliases["i"] = new Init;
}

Command* Reader::interpret(const std::vector<std::string>& args,
                           int len) const {
  if (len == 1) return new Invalid;
  auto& main = args[1];

  if (command_aliases.count(main) == 0) return new Invalid;

  return command_aliases.at(main);
}

Command* Reader::interpret(const std::vector<std::string>& args) const {
  int len = args.size();
  if (len == 1) return new Invalid;

  auto& main = args[1];

  if (command_aliases.count(main) == 0) return new Invalid;

  return command_aliases.at(main);
}

Reader::~Reader() {}
