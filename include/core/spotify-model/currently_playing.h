#pragma once

#include "nlohmann/json.hpp"
#include "core/spotify-model/track.h"

namespace musicvisualizer {

namespace spotifyhandler {

using nlohmann::json;

/**
 * Represents the currently playing item of a Spotify user.
 */
class CurrentlyPlaying {
  public:
    /**
     * Default constructor for a Currently Playing object.
     */
    CurrentlyPlaying();

    /**
     * Constructor for a Currently Playing object from a JSON file.
     *
     * @param currently_playing_file json file storing info for this object.
     */
    explicit CurrentlyPlaying(const json& currently_playing_file);

    /**
     * Gets the progress in milliseconds into the currently playing track.
     *
     * @return the millisecond timestamp of progress.
     */
    int GetProgress();

    /**
     * Gets the current track that is playing.
     *
     * @return the Track that is currently playing.
     */
    Track GetCurrentTrack();

  private:
    int progress_; //progress in milliseconds into the current track
    Track current_track_;
};

} // namespace spotifyhandler

} // namespace musicvisualizer