#pragma once

#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <vector>

using Arguments = const std::vector<std::string>&;

namespace cman {

class Command {
 public:
  inline Command() {}
  inline ~Command() {}

  virtual std::string execute() noexcept = 0;
  Command* set_arguments(Arguments);

 protected:
  std::string msg;
  std::vector<std::string> arguments;

  std::string load(const std::string&);
};

class Invalid : public Command {
 public:
  inline Invalid() {
    try {
      msg = load("help");
    } catch (std::runtime_error& e) {
      std::cout << e.what() << std::endl;
    }
  }
  ~Invalid() {}

  inline std::string execute() noexcept { return msg; }
};

class Init : public Command {
 public:
  Init();
  ~Init() {}

  std::string execute() noexcept;

 private:
  std::string hint;
};

}  // namespace cman
