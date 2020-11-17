#pragma once

#include "core/spotify-model/track.h"
#include "core/spotify-model/artist.h"
#include "cinder/gl/gl.h"
#include <vector>
#include <string>

namespace musicvisualizer {

namespace visualizer {

using std::string;
using std::vector;
using musicvisualizer::spotifyhandler::Track;
using musicvisualizer::spotifyhandler::Artist;

/**
 * Represents the display of song information in Cinder.
 */
class SongInfoDisplayer {
  public:
    /**
     * Default constructor for a Song Information Displayer. By default,
     * song has blank information, positions are at origin, and separation
     * value for display text lines is 0.
     */
    SongInfoDisplayer();

    /**
     * Constructor for a song information displayer given display and position
     * information, no set song to display.
     *
     * @param x_position the x_position of this information display.
     * @param y_position the y_position of the first line of this display.
     *
     * @param line_separation number of pixels between lines of info display.
     */
    SongInfoDisplayer(size_t x_position, size_t y_position, size_t line_separation);

    /**
     * Set the song to display.
     *
     * @param song the track to display.
     */
    void SetDisplaySong(const Track& song);

    /**
     * Displays the current song's relevant information
     */
    void Draw();

  private:
    Track song_;

    //information to position song info on display
    size_t display_x_position_;
    size_t display_y_position_;
    size_t info_separation_; //pixel separation between lines of song in
};

} // namespace visualizer

} // namespace musicvisualizer