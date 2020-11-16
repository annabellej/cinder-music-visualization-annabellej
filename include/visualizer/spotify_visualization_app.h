#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "visualizer/song_information_displayer.h"

namespace musicvisualizer {

namespace visualizer {

/**
 * Displays a visualization of a user's Spotify playlist.
 */
class SpotifyVisualizationApp : public ci::app::App {
  public:
    /**
     * Default constructor for a Spotify Music Visualization App.
     */
    SpotifyVisualizationApp();

    void setup() override;
    void update() override;
    void draw() override;

    const size_t kSongInfoSeparation = 20; //space between lines of song info

    //constants for display dimensions
    const size_t kWindowWidth = 800;
    const size_t kWindowHeight = 500;
    const size_t kDisplayMargin = 150;

  private:
    SongInfoDisplayer info_displayer_;
    //TODO: add in music visualizer displayer
};

} // namespace visualizer

} // namespace musicvisualizer