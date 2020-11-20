#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "visualizer/song_information_displayer.h"
#include "visualizer/song_visualization_displayer.h"
#include "core/spotify_information_retriever.h"
#include "core/spotify-model/currently_playing.h"
#include "curl/curl.h"

namespace musicvisualizer {

namespace visualizer {

using musicvisualizer::spotifyhandler::SpotifyInfoRetriever;
using musicvisualizer::spotifyhandler::CurrentlyPlaying;

/**
 * Displays a visualization of a user's Spotify music.
 */
class SpotifyVisualizationApp : public ci::app::App {
  public:
    /**
     * Default constructor for a Spotify Music Visualization App.
     */
    SpotifyVisualizationApp();

    void update() override;
    void draw() override;

    //constants for display dimensions
    const size_t kWindowWidth = 800;
    const size_t kWindowHeight = 500;
    const size_t kDisplayMargin = 150;
    const size_t kSongInfoSeparation = 20; //space between lines of song info

  private:
    SpotifyInfoRetriever info_handler_;
    SongInfoDisplayer info_displayer_;
    //TODO: add in music visualizer displayer


    //information on current song being visualized
    CurrentlyPlaying current_playing_object_;
};

} // namespace visualizer

} // namespace musicvisualizer