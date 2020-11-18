#include "core/spotify-model/currently_playing.h"

namespace musicvisualizer {

namespace spotifyhandler {

CurrentlyPlaying::CurrentlyPlaying() {
  progress_ = 0;
  Artist placeholder_artist = Artist();
  placeholder_artist.SetName("No Artist");
  current_track_ = Track("0", "No Current Track", vector<Artist>({placeholder_artist}));
}

CurrentlyPlaying::CurrentlyPlaying(const json& currently_playing_file) {
  progress_ = currently_playing_file["progress_ms"];
  current_track_ = Track(currently_playing_file["item"]);
}

int CurrentlyPlaying::GetProgress() const {
  return progress_;
}

Track CurrentlyPlaying::GetCurrentTrack() const {
  return current_track_;
}

} // namespace spotifyhandler

} // namespace musicvisualizer