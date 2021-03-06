#pragma once

#include "nlohmann/json.hpp"
#include <string>

namespace musicvisualizer {

namespace spotifyhandler {

using nlohmann::json;
using std::string;

/**
 * Represents an Artist of a Spotify song.
 */
class Artist {
  public:
    /**
     * Default constructor for an Artist object.
     */
    Artist() = default;

    /**
     * Constructor for an Artist object from a JSON file. Data must specify the
     * name of the Artist.
     *
     * @param artist_file the JSON file containing data for this Artist.
     *
     * @throws std::invalid_argument if no name is given for this Artist.
     */
    explicit Artist(const json& artist_file);

    /**
     * Get the name of this Artist.
     *
     * @return the string name of the Artist.
     */
    string GetName() const;

    /**
     * Sets this artists name.
     *
     * @param name the name to set the Artist to.
     *
     * @throws std::invalid_argument if name given is empty.
     */
    void SetName(const string& name);

  private:
    string artist_name_;
};

} // namespace spotifyhandler

} // namespace musicvisualizer