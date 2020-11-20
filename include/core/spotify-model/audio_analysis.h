#pragma once

#include "core/spotify-model/audio_segment.h"
#include "nlohmann/json.hpp"
#include <vector>

namespace musicvisualizer {

namespace spotifyhandler {

using std::vector;
using nlohmann::json;

/**
 * Represents an analysis for a given Spotify track.
 */
class AudioAnalysis {
  public:
    /**
     * Default Constructor for an Audio Analysis.
     */
    AudioAnalysis() = default;

    /**
     * Constructor for an Audio Analysis object given JSON data.
     *
     * @param analysis_file the file containing data for this Audio Analysis.
     */
    AudioAnalysis(const json& analysis_file);

  private:
    vector<std::pair<float, float>> beats_;
    vector<Segment> audio_segments_;
};

} // namespace spotifyhandler

} // namespace musicvisualizer