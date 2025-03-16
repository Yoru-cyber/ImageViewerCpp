#include <filesystem>
#include <functional>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

/**
 * @brief Reads a directory and filters files based on a condition.
 *
 * @param name The path to the directory.
 * @param v A vector to store the filtered file paths.
 * @param condition A function to filter directory entries.
 *
 * @return void
 *
 * @note This function handles potential filesystem errors.
 */
void read_directory(
    const std::string &name, std::vector<std::string> &v,
    std::function<bool(const std::filesystem::directory_entry &)> condition) {
  std::filesystem::path p(name);
  if (!std::filesystem::exists(p) || !std::filesystem::is_directory(p)) {
    // Handle the case where the path is invalid or not a directory
    std::cerr << "Error: Invalid directory path: " << name << std::endl;
    return; // or throw an exception
  }

  try {
    for (const auto &entry : std::filesystem::directory_iterator(p)) {
      if (condition(entry)) {
        v.push_back(entry.path().filename().string());
      }
    }
  } catch (const std::filesystem::filesystem_error &e) {
    std::cerr << "Filesystem error: " << e.what() << std::endl;
  }
}

int main() {
  std::string directory_path = std::filesystem::current_path();
  std::vector<std::string> file_names;

  auto condition = [](const std::filesystem::directory_entry &entry) {
    if (!entry.is_regular_file()) {
      return false; // Skip directories and other non-regular files
    }

    std::string extension = entry.path().extension().string();
    return extension == ".jpg" || extension == ".webp" || extension == ".png";
  };

  read_directory(directory_path, file_names, condition);

  for (const auto &file_name : file_names) {
    std::cout << file_name << std::endl;
  }

  return 0;
}
