#include "visualizer/spotify_visualization_app.h"
#include "core/utils.h"

namespace musicvisualizer {

namespace visualizer {

SpotifyVisualizationApp::SpotifyVisualizationApp() : info_handler_() {
  info_displayer_ = SongInfoDisplayer(kWindowWidth / 2,
                                      kWindowHeight - 0.5 * kDisplayMargin,
                                      kSongInfoSeparation);
  song_visualizer_ = SongVisualizationDisplayer(kWindowWidth / 2,
                                                kWindowHeight / 2 + kDisplayMargin,
                                                kVisualizationAmplification,
                                                kDisplayMargin / 3);
  ci::app::setWindowSize((int) kWindowWidth, (int) kWindowHeight);
  ci::app::setFrameRate(800.0f);
  ci::gl::enableVerticalSync(false);
}

void SpotifyVisualizationApp::update() {
  CurrentlyPlaying current_user_playing = info_handler_.FetchCurrentlyPlaying();

  //get current timestamp
  double current_timestamp = current_user_playing.GetProgress();
  current_timestamp = RoundToNearestTenth(current_timestamp);
  //reset internal timer to match current Spotify information
  music_timer_.stop();
  music_timer_.start(current_timestamp - kTimeOffset); //start timer w/ offset of timestamp

  if (current_playing_object_.GetCurrentTrack().GetTrackName() != current_user_playing.GetCurrentTrack().GetTrackName()) {
    //get updated current information
    current_playing_object_ = info_handler_.FetchCurrentlyPlaying();

    //get updated timestamp
    double updated_timestamp = current_playing_object_.GetProgress();
    updated_timestamp = RoundToNearestTenth(updated_timestamp);
    music_timer_.stop();
    music_timer_.start(updated_timestamp);

    //set info display according to current information
    Track current_track = current_playing_object_.GetCurrentTrack();
    info_displayer_.SetDisplaySong(current_track);

    //get track audio analysis and set music visualizer accordingly
    string current_id = current_track.GetSpotifyID();
    AudioAnalysis audio_analysis = AudioAnalysis(info_handler_.FetchAudioAnalysis(current_id));
    song_visualizer_.SetVisualizationInformation(music_timer_.getSeconds(), audio_analysis);
  }

  song_visualizer_.SetTime(music_timer_.getSeconds());
}

void SpotifyVisualizationApp::draw() {
  //set black backdrop of visualizer
  ci::Color8u background_color(0, 0, 0); //black
  ci::gl::clear(background_color);

  //draw current song information
  info_displayer_.Draw();

  //draw music visualizations
  song_visualizer_.Draw();
}

void SpotifyVisualizationApp::keyDown(ci::app::KeyEvent event) {
  if (event.getCode() == ci::app::KeyEvent::KEY_RETURN) {
    song_visualizer_.SwitchVisualizer();
  } else if (event.getCode() == ci::app::KeyEvent::KEY_RIGHT) {
    song_visualizer_.SwitchColorScheme();
  }
}

} // namespace visualizer

} // namespace musicvisualizer