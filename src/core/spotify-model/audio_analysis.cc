#include "core/spotify-model/audio_analysis.h"

namespace musicvisualizer {

namespace spotifyhandler {

AudioAnalysis::AudioAnalysis(const json &analysis_file) {
  //read in time intervals for each beat of the track
  for (const json& beat_object: analysis_file["beats"]) {
    beats_.push_back(RoundToNearestTenth(beat_object["start"]));
  }

  //read in audio analysis segments
  for (const json& segment_object: analysis_file["segments"]) {
    audio_segments_.push_back(Segment(segment_object));
  }
}

double AudioAnalysis::GetBeatTimeAt(size_t index) const {
  return beats_.at(index);
}

Segment AudioAnalysis::GetAudioSegmentAt(size_t index) const {
  return audio_segments_.at(index);
}

bool AudioAnalysis::IsBeat(double timestamp) const {
  for (double beat_time: beats_) {
    if (AreDoublesEqual(timestamp, beat_time)) {
      return true;
    }
  }

  return false;
}

Segment AudioAnalysis::GetSegmentAtTime(double timestamp) const {
  for (const Segment& segment: audio_segments_) {
    if (timestamp >= segment.GetStartTime() &&
        timestamp <= segment.GetStartTime() + segment.GetDuration()) {
      return segment;
    }
  }

  return Segment();
}

} // namespace spotifyhandler

} // namespace musicvisualizer