#include "core/spotify_information_retriever.h"
#include <fstream>

namespace musicvisualizer {

namespace spotifyhandler {

SpotifyInfoRetriever::SpotifyInfoRetriever() {
  //set up curl to read from API
  curl_global_init(CURL_GLOBAL_ALL);

  refresh_token_ = FetchRefreshToken();
  api_access_token_ = FetchAccessToken();
}

CurrentlyPlaying SpotifyInfoRetriever::FetchCurrentlyPlaying() const {
  string request_endpoint = "https://api.spotify.com/v1/me/player/currently-playing";
  try {
    json request_result = SendRequest(request_endpoint, "GET", api_access_token_, "");
    return CurrentlyPlaying(request_result);
  } catch (const std::logic_error&) {
    return CurrentlyPlaying(); //return placeholder object with blank info
  }
}

AudioAnalysis SpotifyInfoRetriever::FetchAudioAnalysis(const string& song_id) const {
  string request_endpoint = "https://api.spotify.com/v1/audio-analysis/" + song_id;
  json request_result = SendRequest(request_endpoint, "GET", api_access_token_, "");
  return AudioAnalysis(request_result);
}

bool SpotifyInfoRetriever::IsAuthorized() const {
  return !api_access_token_.empty();
}

string SpotifyInfoRetriever::FetchRefreshToken() const {
  //check if fetching from API is needed or if token already stored (returning user)
  std::ifstream read_file(refresh_file_);
  if (read_file.peek() != std::ifstream::traits_type::eof()) {
    string token;
    std::getline(read_file, token);
    return token;
  }

  string request_endpoint = "https://accounts.spotify.com/api/token";
  string post_request_body = "grant_type=authorization_code&code=" + authorization_code_ +
          "&redirect_uri=" + kRedirectURI + "&client_id=" + kClientID +
          "&client_secret=" + kClientSecret;

  json request_result = SendRequest(request_endpoint, "POST", "", post_request_body);
  string token = request_result["refresh_token"];

  //store token in file to be reused by application
  std::ofstream write_file;
  write_file.open(refresh_file_);
  write_file << token;
  write_file.close();

  return token;
}

string SpotifyInfoRetriever::FetchAccessToken() const {
  string request_endpoint = "https://accounts.spotify.com/api/token";
  //request body specified in Spotify API docs
  string post_request_body =
          "grant_type=refresh_token&refresh_token=" + refresh_token_ +
          "&client_id=" + kClientID +
          "&client_secret=" + kClientSecret;

  json request_result = SendRequest(request_endpoint, "POST", "", post_request_body);
  return request_result["access_token"];
}

} // namespace spotifyhandler

} // namespace musicvisualizer