#include "reader.hpp"

using namespace cman;

Reader::Reader() {
  command_aliases["init"] = new Init;
  command_aliases["i"] = new Init;
}

Command* Reader::interpret(Arguments args, int len) const {
  if (len == 1) return new Invalid;

  return initialize_command(args);
}

Command* Reader::interpret(Arguments args) const {
  int len = args.size();
  if (len == 1) return new Invalid;

  return initialize_command(args);
}

Command* Reader::initialize_command(Arguments a) const {
  auto& main = a[1];

  if (command_aliases.count(main) == 0) return new Invalid;

  return command_aliases.at(main);
}

Reader::~Reader() { command_aliases.clear(); }
