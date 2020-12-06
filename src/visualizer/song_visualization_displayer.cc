#include "visualizer/song_visualization_displayer.h"

namespace musicvisualizer {

namespace visualizer {

using glm::vec2;

SongVisualizationDisplayer::SongVisualizationDisplayer(size_t x_pos,
                                                       size_t y_pos,
                                                       size_t amplification,
                                                       size_t bar_width) {
  visualizer_count_ = 1; //currently support 2 types of visualization
  current_visualizer_index_ = 0; //default starts at first vis type (bar graph)
  x_position_ = x_pos;
  y_position_ = y_pos;
  amplification_factor_ = amplification;
  bar_visualizer_width_ = bar_width;
  timestamp_ = 0.0;

  //set up colors corresponding to musical pitches for visualization
  musical_pitch_colors_ = vector<ci::Color>(12, "white");
  FetchPitchColors();
}

void SongVisualizationDisplayer::SetVisualizationInformation(double timestamp,
                                                             const AudioAnalysis &analysis) {
  timestamp_ = timestamp;
  audio_analysis_ = analysis;
}

void SongVisualizationDisplayer::SetTime(double timestamp) {
  timestamp_ = timestamp;
}

void SongVisualizationDisplayer::Draw() const {
  //more cases can be added for more visualization types
  switch (current_visualizer_index_) {
    case 0: {
      DrawBarVisualizer();
      break;
    }
  }
}

void SongVisualizationDisplayer::SwitchVisualizer() {
  current_visualizer_index_ = (current_visualizer_index_ + 1) % visualizer_count_;
}

void SongVisualizationDisplayer::FetchPitchColors() {
  //F#4:
  musical_pitch_colors_.at(6) = CalculateColorOfNote(-3);
  //G4:
  musical_pitch_colors_.at(7) = CalculateColorOfNote(-2);
  //G#4:
  musical_pitch_colors_.at(8) = CalculateColorOfNote(-1);
  //A4:
  musical_pitch_colors_.at(9) = CalculateColorOfNote(0);
  //A#4:
  musical_pitch_colors_.at(10) = CalculateColorOfNote(1);
  //B4:
  musical_pitch_colors_.at(11) = CalculateColorOfNote(2);
  //C5:
  musical_pitch_colors_.at(0) = CalculateColorOfNote(3);
  //C#5:
  musical_pitch_colors_.at(1) = CalculateColorOfNote(4);
  //D5:
  musical_pitch_colors_.at(2) = CalculateColorOfNote(5);
  //D#5:
  musical_pitch_colors_.at(3) = CalculateColorOfNote(6);
  //E5:
  musical_pitch_colors_.at(4) = CalculateColorOfNote(7);
  //F5:
  musical_pitch_colors_.at(5) = CalculateColorOfNote(8);
}

void SongVisualizationDisplayer::DrawBarVisualizer() const {
  Segment current_audio_segment = audio_analysis_.GetSegmentAtTime(timestamp_);
  //12 bars in total for 12 pitches, 6 on each side of display center
  vec2 bottom_right = vec2(x_position_ + 6 * bar_visualizer_width_, y_position_);

  //loop through pitches in this segment, draw bar heights accordingly
  for (int pitch_index = 11; pitch_index >= 0; --pitch_index) {
    //get pitch dominance value + adjust to get percentage value
    double bar_height = 100 * current_audio_segment.GetPitchDominanceAt(pitch_index);
    bar_height += current_audio_segment.GetLoudness() / amplification_factor_;

    //if loudness is low (large negative), set bar to lowest 1 pixel high
    if (bar_height < 0) {
      bar_height = 1;
    }

    //amplify bar if on beat
    if (audio_analysis_.IsBeat(timestamp_)) {
      bar_height *= amplification_factor_;
    }

    //adjust color of bar based on musical brightness/timbre of current segment
    ci::Color bar_color = AdjustTimbreColor(musical_pitch_colors_.at(pitch_index),
                                            current_audio_segment.GetBrightness());
    //draw bar
    ci::gl::color(bar_color);
    vec2 top_left = vec2(bottom_right.x - bar_visualizer_width_, y_position_ - bar_height);
    ci::Rectf bar_box(top_left, bottom_right);
    ci::gl::drawSolidRect(bar_box);

    bottom_right -= vec2(bar_visualizer_width_, 0);
  }
}

ci::Color SongVisualizationDisplayer::CalculateColorOfNote(
        int half_steps) const {
  double sound_frequency = CalculateNoteFrequency(half_steps);
  double light_frequency = ConvertToLightFrequency(sound_frequency);
  double wavelength = ConvertFrequencyToWavelength(light_frequency);
  return ApproximatePitchColor(wavelength);
}

} // namespace visualizer

} // namespace musicvisualizer