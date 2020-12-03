#include "testing_utils.h"

#include <iostream>

namespace testingutils {

json PutFileInJson(const string& filename) {
  std::ifstream file(filename);
  json json_file;

  try {
    json_file = json::parse(file);
  } catch (json::parse_error e) {
    throw std::invalid_argument("File has invalid JSON format.");
  }

  return json_file;
}

} // namespace testingutils