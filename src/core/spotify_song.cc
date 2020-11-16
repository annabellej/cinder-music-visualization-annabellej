#include "core/spotify_song.h"

namespace musicvisualizer {

using musicvisualizer::SpotifySong;

SpotifySong::SpotifySong(const string& title, const vector<string>& artists) {
  song_title = title;
  song_artists = artists;
}

} // namespace musicvisualizer