#include "core/spotify_information_handler.h"

namespace musicvisualizer {

namespace spotifyhandler {

SpotifyInfoHandler::SpotifyInfoHandler() {
  //set up curl to read from API
  curl_global_init(CURL_GLOBAL_ALL);
  api_access_token_ = FetchAccessToken();
}

CurrentlyPlaying SpotifyInfoHandler::FetchCurrentlyPlaying() {
  string request_endpoint = "https://api.spotify.com/v1/me/player/currently-playing";
  try {
    json request_result = SendRequest(request_endpoint, "GET", api_access_token_, "");
    return CurrentlyPlaying(request_result);
  } catch (const std::logic_error&) {
    return CurrentlyPlaying(); //return placeholder object with blank info
  }
}

bool SpotifyInfoHandler::IsAuthorized() {
  return !api_access_token_.empty();
}

string SpotifyInfoHandler::FetchAccessToken() {
  string request_endpoint = "https://accounts.spotify.com/api/token";
  //request body specified in Spotify API docs
  string post_request_body =
          "grant_type=refresh_token&refresh_token="+ refresh_token_ +
          "&client_id=" + kClientID +
          "&client_secret=" + kClientSecret;

  json request_result = SendRequest(request_endpoint, "POST", "", post_request_body);
  return request_result["access_token"];
}

} // namespace spotifyhandler

} // namespace musicvisualizer