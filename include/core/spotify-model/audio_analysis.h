#pragma once

#include "core/spotify-model/audio_segment.h"
#include "nlohmann/json.hpp"
#include <vector>

namespace musicvisualizer {

namespace spotifyhandler {

using std::vector;
using std::pair;
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
     *
     * @throws std::invalid_argument if file does not provide sufficient info.
     */
    AudioAnalysis(const json& analysis_file);

    /**
     * Fetches the time for the beat at a given index.
     *
     * @param index the index at which to get the beat time.
     *
     * @return the pair denoting the given beat's time.
     */
    double GetBeatTimeAt(size_t index) const;

    /**
     * Fetch the audio segment object at a given index.
     *
     * @param index the index at which to get the segment.
     *
     * @return the audio segment at the given index.
     */
    Segment GetAudioSegmentAt(size_t index) const;

    /**
     * Given a certain time in seconds into a track, determines whether a beat
     * occurs during this time.
     *
     * @param timestamp the time to evaluate.
     *
     * @return true if the given time is a beat in the track, else
     *         false if the given time is not on a beat.
     */
    bool IsBeat(double timestamp) const;

    /**
     * Getches the audio analysis segment for a given time.
     *
     * @param timestamp the time to retrieve a segment for.
     *
     * @return the segment containing analyses for this time.
     */
    Segment GetSegmentAtTime(double timestamp) const;

  private:
    vector<double> beats_; //timestamp of each beat
    vector<Segment> audio_segments_;   //analysis segments for track.
};

} // namespace spotifyhandler

} // namespace musicvisualizer