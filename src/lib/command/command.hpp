
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using Arguments = const std::vector<std::string>&;

namespace cman {

class Command {
 public:
  inline Command() {}
  inline ~Command() {}

  virtual std::string execute() = 0;
  virtual Command* set_arguments(Arguments) = 0;

 protected:
  std::string msg;

  std::string load(const std::string&);
};

class Invalid : public Command {
 public:
  inline Invalid() { msg = load("help"); }
  ~Invalid() {}

  inline Command* set_arguments(Arguments a) override { return this; }
  inline std::string execute() override { return msg; }
};

class Init : public Command {
 public:
  inline Init() {
    msg = load("init");
    hint = load("init-hint");
    arguments = {};
  }
  ~Init() {}
  Command* set_arguments(Arguments) override;
  std::string execute() override;

 private:
  std::string hint;
  std::vector<std::string> arguments;
};

}  // namespace cman
