
#include <string>
namespace cman {

class Command {
 public:
  Command() {}
  Command(Command &&) = default;
  Command(const Command &) = default;
  Command &operator=(Command &&) = default;
  Command &operator=(const Command &) = default;

  virtual std::string execute() = 0;

  ~Command() {}
};

class Invalid : public Command {
 public:
  Invalid() {}
  Invalid(Invalid &&) = default;
  Invalid(const Invalid &) = default;
  Invalid &operator=(Invalid &&) = default;
  Invalid &operator=(const Invalid &) = default;
  ~Invalid() {}

  std::string execute() { return ""; }
};

}  // namespace cman
