#include <fstream>
#include <string>

namespace cman {

inline bool file_exist(const char *file_name)
{
    std::ifstream infile(file_name);
    return infile.good();
}
inline bool file_exist(const std::string& file_name)
{
    std::ifstream infile(file_name);
    return infile.good();
}
}
