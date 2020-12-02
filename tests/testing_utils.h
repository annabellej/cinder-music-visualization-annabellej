#pragma once

#include <fstream>
#include <string>
#include "nlohmann/json.hpp"

namespace testingutils {

using std::string;
using nlohmann::json;

/**
 * Passes a file into a JSON.
 *
 * @param filename name of the file to use.
 *
 * @return JSON of the given file.
 *
 * @throws std::invalid_argument if file has invalid json formatting.
 */
json PutFileInJson(const string& filename);

} // namespace testingutils