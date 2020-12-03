#pragma once

#include <vector>
#include "nlohmann/json.hpp"
#include "core/utils.h"

namespace musicvisualizer {

namespace spotifyhandler {

using std::vector;
using nlohmann::json;

/**
 * Represents a segment of audio for a Spotify track with information about
 * the audio in this time section.
 */
class Segment {
  public:
    /**
     * Default constructor for a Segment object. Initiate values to 0.0.
     */
    Segment();

    /**
     * Constructor for an audio segment given data from JSON.
     *
     * @param segment_file data file containing data for this Segment.
     *
     * @throws std::invalid_argument if file values are invalid.
     */
    Segment(const json& segment_file);

    /**
     * Fetch the start time for this segment.
     *
     * @return return time in seconds of the beginning of this segment.
     */
    float GetStartTime() const;

    /**
     * Fetch the time duration of this segment.
     *
     * @return the time in seconds denoting how long this segment is.
     */
    float GetDuration() const;

    /**
     * Fetch the average volume of this segment.
     *
     * @return the loudness value for this segment.
     */
    float GetLoudness() const;

    /**
     * Fetch the brightness value for this segment.
     *
     * @return the brightness value.
     */
    float GetBrightness() const;

    /**
     * Get dominance value of a certain pitch on the chromatic scale of this
     * segment.
     *
     * @param pitch_index index of the pitch for which to retrieve the value.
     *
     * @return the dominance value of the given pitch.
     */
    float GetPitchDominanceAt(size_t pitch_index) const;

    /**
     * Finds the number of pitches stored in this segment.
     *
     * @return the number of pitches.
     */
    size_t GetPitchCount() const;

  private:
    float start_time_;      //beginning timestamp in seconds of this segment.
    float duration_;        //time duration in seconds of segment.
    float loudness_;        //loudness/"attack" of this segment.
    float brightness_;      //denotes how bright this audio segment sounds.
    vector<float> pitches_; //relative dominance of chromatic scale pitches (C to B).
};

} // namespace spotifyhandler

} // namespace musicvisualizer