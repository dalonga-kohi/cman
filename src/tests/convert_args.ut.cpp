#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "../lib/utils.hpp"

TEST(ConvertArgs, ConvertSingleParameter) {
  std::vector<std::string> expected = {"cman", "init"};
  char* args[] = {(char*)"cman", (char*)"init"};

  std::vector<std::string> res = cman::convert_args(args, 2);

  ASSERT_EQ(res, expected);
}
TEST(ConvertArgs, ConvertMultipleParameters) {
  std::vector<std::string> expected = {"cman", "class", "add", "newclass"};
  char* args[] = {(char*)"cman", (char*)"class", (char*)"add",
                  (char*)"newclass"};

  std::vector<std::string> res = cman::convert_args(args, 4);

  ASSERT_EQ(res, expected);
}
TEST(ConvertArgs, ConvertNoParameter) {
  std::vector<std::string> expected = {};
  char* args[] = {};

  std::vector<std::string> res = cman::convert_args(args, 0);

  ASSERT_EQ(res, expected);
}
