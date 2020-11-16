#include "visualizer/spotify_visualization_app.h"

using musicvisualizer::visualizer::SpotifyVisualizationApp;

void prepareSettings(SpotifyVisualizationApp::Settings* settings) {
  settings->setResizable(false);
}

CINDER_APP(SpotifyVisualizationApp, ci::app::RendererGl, prepareSettings);