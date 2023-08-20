#include "command.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

#include "../utils.hpp"

using namespace cman;

std::string Command::load(const std::string& file) {
  if (!file_exist(file)) {
    throw std::runtime_error("couldn't find data files");
  }
  std::stringstream buff;
  std::ifstream f(file);
  buff << f.rdbuf();
  f.close();

  return buff.str();
}
