
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace cman {

class Command {
 public:
  inline Command() {}
  inline ~Command() {}

  virtual std::string execute() = 0;

 protected:
  std::string msg;

  std::string load(const std::string&);
};

class Invalid : public Command {
 public:
  inline Invalid() { msg = load("help"); }
  ~Invalid() {}
  inline std::string execute() override { return msg; }
};

}  // namespace cman
