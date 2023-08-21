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

    std::ifstream help("../src/data/help");
    expected << help.rdbuf();
    help.close();
  }
};

class ReadInitCommand : public testing::Test {
 protected:
  std::unique_ptr<Reader> rd;
  std::unique_ptr<Command> cmd;
  std::stringstream expected;
  std::stringstream hint;
  std::vector<std::string> args = {"cman", "init"};

  ReadInitCommand() {
    cmd.reset(new Invalid);
    rd.reset(new Reader);

    std::ifstream msg("../src/data/init");
    expected << msg.rdbuf();
    msg.close();
    msg.open("../src/data/init-hint");

    hint << msg.rdbuf();
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

TEST_F(ReadInvalidCommand, LongerInvalidCommand) {
  cmd.reset(rd->interpret(args_longer));
  std::string msg = cmd->execute();

  cmd.reset(nullptr);
  rd.reset(nullptr);

  ASSERT_EQ(msg, expected.str());
}
TEST_F(ReadInitCommand, InvalidInit) {
  args.push_back("inv");

  cmd.reset(rd->interpret(args));
  std::string res = cmd->execute();

  ASSERT_EQ(res, hint.str());
}
