#include "visualizer/song_information_displayer.h"

namespace musicvisualizer {

namespace visualizer {

using glm::vec2;
using musicvisualizer::visualizer::SongInfoDisplayer;

SongInfoDisplayer::SongInfoDisplayer() {
  song_ = SpotifySong(" ", vector<string>({""}));
  display_x_position_ = display_y_position_ = 0;
  info_separation_ = 0;
}

SongInfoDisplayer::SongInfoDisplayer(const SpotifySong &song, size_t x_position,
                                     size_t y_position, size_t line_separation) {
  display_x_position_ = x_position;
  display_y_position_ = y_position;
  info_separation_ = line_separation;
  song_ = song;
}

void SongInfoDisplayer::Draw() {
  //draw song title on display
  ci::gl::drawStringCentered(
          song_.song_title,
          vec2(display_x_position_, display_y_position_),
          ci::Color("white"));

  //create string of all song artists
  string artist_names;
  for (size_t index = 0; index < song_.song_artists.size(); index++) {
    artist_names += song_.song_artists.at(index);
    //add comma separator between artist names
    if (index != song_.song_artists.size() - 1) {
      artist_names += ", ";
    }
  }

  //draw song artists on display
  ci::gl::drawStringCentered(
          artist_names,
          vec2(display_x_position_, display_y_position_ + info_separation_),
          ci::Color("white"));
}

} // namespace visualizer

} // namespace musicvisualizer