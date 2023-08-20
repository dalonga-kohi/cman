#pragma once

#include "../lib/reader/reader.hpp"

#include <gtest/gtest.h>

#include <iostream>
#include <memory>
#include <vector>

#include "../lib/command/command.hpp"

using namespace cman;

class ReadInvalidCommand : public testing::Test {
 protected:
  std::unique_ptr<Reader> rd = std::make_unique<Reader>();
  std::unique_ptr<Command> cmd = std::make_unique<Invalid>();
  std::string expected = "";

  std::vector<std::string> args = {"cman", "invalid"};
  std::vector<std::string> args_longer = {"cman", "invalid", "cmd"};
  int len = args.size();
  int len_longer = args_longer.size();
};

TEST_F(ReadInvalidCommand, InvalidCommandWithLen) {
  cmd.reset(rd->interpret(args, len));
  std::string msg = cmd->execute();
  cmd.reset(nullptr);

  ASSERT_EQ(msg, expected);
}
TEST_F(ReadInvalidCommand, LongerInvalidCommandWithLen) {
  cmd.reset(rd->interpret(args_longer, len_longer));
  std::string msg = cmd->execute();
  cmd.reset(nullptr);

  ASSERT_EQ(msg, expected);
}
