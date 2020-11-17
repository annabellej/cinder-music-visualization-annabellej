#pragma once

#include "nlohmann/json.hpp"
#include "core/spotify-model/artist.h"
#include <string>
#include <vector>

namespace musicvisualizer {

namespace spotifyhandler {

using nlohmann::json;
using std::string;
using std::vector;

/**
 * Represents a specific song in Spotify
 */
class Track {
  public:
    /**
     * Default constructor for a Track.
     */
    Track() = default;

    /**
     * Constructs a Track object from a JSON file.
     *
     * @param track_file JSON file containing data for this Track.
     */
    Track(const json& track_file);

    /**
     * Constructor for a Track object without file.
     *
     * @param id        Spotify id of this track.
     * @param name      name of this track.
     * @param artists   the artists for this track.
     */
    Track(const string& id, const string& name, const vector<Artist>& artists);

    /**
     * Gets the Spotify ID for this track.
     *
     * @return the string ID for this track.
     */
    string GetSpotifyID();

    /**
     * Gets the name of this track.
     *
     * @return the string name of the track.
     */
    string GetTrackName();

    /**
     * Get the number of artists this Track has.
     *
     * @return the number of artists for this Track.
     */
    size_t GetNumArtists();

    /**
     * Gets one of the Artists of this Track by index.
     *
     * @param index the index of the Artist to retrieve from the list.
     *
     * @return the Artist at the given position.
     */
    Artist GetArtistAt(size_t index);

  private:
    string spotify_id_;
    string track_name_;
    vector<Artist> track_artists_;
};

} // namespace spotifyhandler

} // namespace musicvisualizer