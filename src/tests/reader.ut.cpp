#include <gtest/gtest.h>
#include <memory>
#include <iostream>
#include <fstream>

#include "../lib/command/command.hpp"
#include "../lib/reader/reader.hpp"

using namespace cman;

class ReadInvalidCommand : public testing::Test {
protected:
    std::unique_ptr<Reader> rd = std::make_unique<Reader>();
    std::unique_ptr<Command> cmd = std::make_unique<Command>();

    char* cmd[2] = ["cman", "invalid"];
    char* cmd_longer[2] = ["cman", "invalid", "cmd"];
    int len = sizeof(args)/sizeof(args[0]);
    int len_longer = sizeof(args)/sizeof(args[0]);
};

TEST_F(ReadInvalidCommand, InvalidCommandWithLen1) {
    std::string expected = ""

    cmd.reset(rd.interpret(cmd, len));
    std::string msg = cmd->execute();
    cmd.reset(nullptr)

    ASSERT_EQ(msg,expected);
}
TEST_F(ReadInvalidCommand, LongerInvalidCommandWithLen) {
    std::string expected = ""

    cmd.reset(rd.interpret(cmd_longer, len_longer));
    std::string msg = cmd->execute();
    cmd.reset(nullptr)

    ASSERT_EQ(msg,expected);
}