#include <fstream>
#include <string>
#include <vector>

#ifdef _WIN32
#define ABS_PATH "C:\\Program Files\\cman\\"
#else
#define ABS_PATH "/etc/cman/"
#endif  // _WIN32

namespace cman {

inline bool file_exist(const char* file_name) {
  std::ifstream infile(file_name);
  return infile.good();
}
inline bool file_exist(const std::string& file_name) {
  std::ifstream infile(file_name);
  return infile.good();
}

inline std::vector<std::string> convert_args(char* args[], int len) noexcept {
  std::vector<std::string> result = {};

  for (int i = 0; i < len; i++) {
    result.push_back(args[i]);
  }
  return result;
}

}  // namespace cman
