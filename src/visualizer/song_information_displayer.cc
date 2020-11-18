#include "visualizer/song_information_displayer.h"

namespace musicvisualizer {

namespace visualizer {

using glm::vec2;
using musicvisualizer::visualizer::SongInfoDisplayer;

SongInfoDisplayer::SongInfoDisplayer() {
  Artist placeholder_artist;
  placeholder_artist.SetName("No Artist");

  song_ = Track("0", "No Song Playing", vector<Artist>({placeholder_artist}));
  display_x_position_ = display_y_position_ = 0;
  info_separation_ = 0;
}

SongInfoDisplayer::SongInfoDisplayer(size_t x_position, size_t y_position,
                                     size_t line_separation) {
  display_x_position_ = x_position;
  display_y_position_ = y_position;
  info_separation_ = line_separation;
}

void SongInfoDisplayer::SetDisplaySong(const Track &song) {
  song_ = song;
}

void SongInfoDisplayer::Draw() const {
  //TODO: stylize song info display (font, style, etc.)
  //draw song title on display
  ci::gl::drawStringCentered(
          song_.GetTrackName(),
          vec2(display_x_position_, display_y_position_),
          ci::Color("white"));

  //create string of all song artists
  string artist_names;
  for (size_t index = 0; index < song_.GetNumArtists(); index++) {
    artist_names += song_.GetArtistAt(index).GetName();

    //add comma separator between artist names
    if (index != song_.GetNumArtists() - 1) {
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