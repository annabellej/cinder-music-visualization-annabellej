#include "core/spotify-model/audio_segment.h"
#include <cmath>

namespace musicvisualizer {

namespace spotifyhandler {

Segment::Segment() {
  start_time_ = 0.0;
  duration_ = 0.0;
  loudness_ = 0.0;
  brightness_ = 0.0;

  for (size_t index = 0; index < 12; index++) {
    pitches_.push_back(0.0);
  }
}

Segment::Segment(const json &segment_file) {
  start_time_ = segment_file["start"];
  duration_ = segment_file["duration"];
  loudness_ = segment_file["loudness_start"];
  brightness_ = segment_file["timbre"][1]; //brightness is second quality in timbre array

  for (float pitch_value: segment_file["pitches"]) {
    pitches_.push_back(pitch_value);
  }
}

float Segment::GetStartTime() const {
  return start_time_;
}

float Segment::GetDuration() const {
  return duration_;
}

float Segment::GetLoudness() const {
  return loudness_;
}

float Segment::GetBrightness() const {
  return brightness_;
}

float Segment::GetPitchDominanceAt(size_t pitch_index) const {
  return pitches_.at(pitch_index);
}

} // namespace spotifyhandler

} // namespace musicvisualizer