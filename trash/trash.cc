#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main()
{
  std::string path = "../users";
  for (const auto & entry : fs::directory_iterator(path)) {
    std::string file_name = entry.path().string();
    file_name.erase(0, 9);
    file_name.erase(file_name.size() - 4, file_name.size());
    std::cout << file_name << std::endl;
  }
}
