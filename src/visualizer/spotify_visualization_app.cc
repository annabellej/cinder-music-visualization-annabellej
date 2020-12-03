#include "visualizer/spotify_visualization_app.h"

namespace musicvisualizer {

namespace visualizer {

SpotifyVisualizationApp::SpotifyVisualizationApp() : info_handler_() {
  info_displayer_ = SongInfoDisplayer(kWindowWidth / 2,
                                      kWindowHeight - kDisplayMargin,
                                      kSongInfoSeparation);
  ci::app::setWindowSize((int) kWindowWidth, (int) kWindowHeight);
}

void SpotifyVisualizationApp::update() {
  //check current song and set info display accordingly
  current_playing_object_ = info_handler_.FetchCurrentlyPlaying();
  Track current_track = current_playing_object_.GetCurrentTrack();
  info_displayer_.SetDisplaySong(current_track);

  //convert timestamp to seconds
  //int current_timestamp = current_playing_object_.GetProgress() / 1000;

  //TODO: finish implementing update for audio info for visualization
}

void SpotifyVisualizationApp::draw() {
  //set black backdrop of visualizer
  ci::Color8u background_color(0, 0, 0); //black
  ci::gl::clear(background_color);

  //draw current song information
  info_displayer_.Draw();

  //TODO: draw music visualizations
}

} // namespace visualizer

} // namespace musicvisualizer