#pragma once

#include <vector>
#include <string>

namespace musicvisualizer {

using std::vector;
using std::string;

struct SpotifySong {
  vector<string> song_artists;
  string song_title;

  /**
   * Default constructor for a Spotify Song given no information.
   */
  SpotifySong() : song_artists(), song_title("Empty Song") {};

  /**
   * Constructor for a Spotify Song given an array of artist names and the
   * title of the song.
   *
   * @param title   the string title of this song.
   * @param artists an list of artists for this song.
   */
  SpotifySong(const string& title, const vector<string>& artists);
};

} // namespace musicvisualizer