#include "visualizer/spotify_visualization_app.h"

namespace musicvisualizer {

namespace visualizer {

SpotifyVisualizationApp::SpotifyVisualizationApp() {
  ci::app::setWindowSize((int) kWindowWidth, (int) kWindowHeight);
}

void SpotifyVisualizationApp::setup() {
  //TODO: implement setup to get user authorization for spotify account
  //should use spotify information handler
}

void SpotifyVisualizationApp::update() {
  //TODO: implement update
  //check current song and set info_displayer_ accordingly

  //get current song's timestamp and get song (track) information:
  //use timestamp to match with song info at that time: get current
}

void SpotifyVisualizationApp::draw() {
  //set black backdrop of visualizer
  ci::Color8u background_color(0, 0, 0); //black
  ci::gl::clear(background_color);

  //draw current song information
  info_displayer_.Draw();
  //TODO: draw music visualizations (icosahedron + bar visualizer)

}

} // namespace visualizer

} // namespace musicvisualizer