#include "core/spotify-model/artist.h"

namespace musicvisualizer {

namespace spotifyhandler {

Artist::Artist(const json& artist_file) {
  artist_name_ = artist_file["name"];

  if (artist_name_.empty()) {
    throw std::invalid_argument("Given data does not specify name of artist.");
  }
}

string Artist::GetName() const {
  return artist_name_;
}

void Artist::SetName(const string &name) {
  if (name.empty()) {
    throw std::invalid_argument("Artist name cannot be empty.");
  }

  artist_name_ = name;
}

} // namespace spotifyhandler

} // namespace musicvisualizer