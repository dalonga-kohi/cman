#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../lib/utils.hpp"

TEST(ConvertArgs, ConvertSingleParameter) {
    std::vector<std::string> expected = {"cman", "init"};
    char* args[] = {(char*)"cman", (char*)"init"};

    std::vector<std::string> res = cman::convert_args(args); 
    
    ASSERT_EQ(res, expected);
}
TEST(ConvertArgs, ConvertMultipleParameters) {
    std::vector<std::string> expected = {"cman", "class", "add", "newclass"};
    char* args[] = {(char*)"cman", (char*)"class", (char*)"add", (char*)"newclass"};

    std::vector<std::string> res = cman::convert_args(args); 
    
    ASSERT_EQ(res, expected);
}
