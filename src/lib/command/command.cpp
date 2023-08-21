#include "command.hpp"

#include "../utils.hpp"

using namespace cman;

std::string Command::load(const std::string& file) {
  if (!file_exist(ABS_PATH + file)) {
    throw std::runtime_error("couldn't find data files");
  }
  std::stringstream buff;
  std::ifstream f(ABS_PATH + file);
  buff << f.rdbuf();
  f.close();

  return buff.str();
}
