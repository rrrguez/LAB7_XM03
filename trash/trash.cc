// #include <string>
// #include <iostream>
// #include <filesystem>
// #include <unistd.h>
// #include <iostream>
// #include <string>
// #include <filesystem>
// #include <unistd.h>
// // namespace fs = std::filesystem;
// using std::filesystem::current_path; 
// using std::cout; using std::cin;
// using std::endl; using std::string;
// using std::filesystem::current_path;

// int main()
// {
//   std::cout << current_path() << std::endl;
//   // std::string path = "../users";
//   // for (const auto & entry : fs::directory_iterator(path)) {
//   //   std::string file_name = entry.path().string();
//   //   file_name.erase(0, 9);
//   //   file_name.erase(file_name.size() - 4, file_name.size());
//   //   std::cout << file_name << std::endl;
//   // }
// }
#include <iostream>
#include <string>
#include <filesystem>
#include <unistd.h>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::filesystem::current_path;

int main() {
    cout << "Current working directory: " << current_path() << endl;

    return EXIT_SUCCESS;
}

