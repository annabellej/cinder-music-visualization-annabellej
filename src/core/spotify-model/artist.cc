#include "core/spotify-model/artist.h"

namespace musicvisualizer {

namespace spotifyhandler {

Artist::Artist(const json& artist_file) {
  artist_name_ = artist_file["name"];
}

string Artist::GetName() {
  return artist_name_;
}

void Artist::SetName(const string &name) {
  artist_name_ = name;
}

} // namespace spotifyhandler

} // namespace musicvisualizer