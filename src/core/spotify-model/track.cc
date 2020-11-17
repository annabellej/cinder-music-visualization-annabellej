#include "core/spotify-model/track.h"

namespace musicvisualizer {

namespace spotifyhandler {

Track::Track(const json& track_file) {
  spotify_id_ = track_file["id"];
  track_name_ = track_file["name"];

  for (json artist_object: track_file["artists"]) {
    track_artists_.push_back(Artist(artist_object));
  }
}

Track::Track(const string& id, const string& name, const vector<Artist>& artists) {
  spotify_id_ = id;
  track_name_ = name;
  track_artists_ = artists;
}

string Track::GetSpotifyID() {
  return spotify_id_;
}

string Track::GetTrackName() {
  return track_name_;
}

size_t Track::GetNumArtists() {
  return track_artists_.size();
}

Artist Track::GetArtistAt(size_t index) {
  return track_artists_.at(index);
}

} // namespace spotifyhandler

} // namespace musicvisualizer