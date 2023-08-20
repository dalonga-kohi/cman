#include "../lib/reader/reader.hpp"

#include <gtest/gtest.h>

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

using namespace cman;

class ReadInvalidCommand : public testing::Test {
 protected:
  std::unique_ptr<Reader> rd;
  std::unique_ptr<Command> cmd;
  std::stringstream expected;
  std::vector<std::string> args = {"cman", "invalid"};
  std::vector<std::string> args_longer = {"cman", "invalid", "cmd"};

  int len = args.size();
  int len_longer = args_longer.size();

  ReadInvalidCommand() {
    cmd.reset(new Invalid);
    rd.reset(new Reader);

    std::ifstream help("data/help");
    expected << help.rdbuf();
    help.close();
  }
};

TEST_F(ReadInvalidCommand, InvalidCommandWithLen) {
  cmd.reset(rd->interpret(args, len));
  std::string msg = cmd->execute();

  cmd.reset(nullptr);
  rd.reset(nullptr);

  ASSERT_EQ(msg, expected.str());
}
TEST_F(ReadInvalidCommand, LongerInvalidCommandWithLen) {
  cmd.reset(rd->interpret(args_longer, len_longer));
  std::string msg = cmd->execute();

  cmd.reset(nullptr);
  rd.reset(nullptr);

  ASSERT_EQ(msg, expected.str());
}
