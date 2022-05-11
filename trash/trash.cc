#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main()
{
  std::string path = "../users";
  for (const auto & entry : fs::directory_iterator(path)) {
    std::string file_name = entry.path().string();
    std::cout << file_name << std::endl;
  }
}
