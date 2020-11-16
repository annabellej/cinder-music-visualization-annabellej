#pragma once

#include "core/spotify_song.h"
#include "cinder/gl/gl.h"

namespace musicvisualizer {

namespace visualizer {

class SongInfoDisplayer {
  public:
    /**
     * Default constructor for a Song Information Displayer. By default,
     * song has blank information, positions are at origin, and separation
     * value for display text lines is 0.
     */
    SongInfoDisplayer();

    /**
     * Constructor for a song information displayer given a certain song.
     *
     * @param song the song whose information to display.
     *
     * @param x_position the x_position of this information display.
     * @param y_position the y_position of the first line of this display.
     *
     * @param line_separation number of pixels between lines of info display.
     */
    SongInfoDisplayer(const SpotifySong& song, size_t x_position, size_t y_position,
                      size_t line_separation);

    /**
     * Displays the current song's relevant information
     */
    void Draw();

  private:
    SpotifySong song_;

    //information to position song info on display
    size_t display_x_position_;
    size_t display_y_position_;
    size_t info_separation_; //pixel separation between lines of song in
};

} // namespace visualizer

} // namespace musicvisualizer