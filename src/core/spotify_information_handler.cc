#include "core/spotify_information_handler.h"

namespace musicvisualizer {

namespace spotifyhandler {

SpotifyInfoHandler::SpotifyInfoHandler() {
  //set up curl to read from API
  curl_global_init(CURL_GLOBAL_ALL);
  api_access_token_ = FetchAccessToken();
}

CurrentlyPlaying SpotifyInfoHandler::FetchCurrentlyPlaying() {
  CURL * curl;
  curl = curl_easy_init();
  string readBuffer;

  if (!curl) {
    throw std::runtime_error("CURL failed to initiate.");
  }

  //endpoint to determine current user playback on Spotify
  curl_easy_setopt(curl, CURLOPT_URL, "https://api.spotify.com/v1/me/player/currently-playing");

  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

  //don't have Spotify's server certificate, need to disable authentication
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);

  curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
  //building custom header referenced from:
  //https://curl.se/libcurl/c/httpcustomheader.html
  string get_request_header = "Authorization: Bearer " + api_access_token_;
  struct curl_slist *chunk = NULL;
  chunk = curl_slist_append(chunk, get_request_header.c_str());
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

  curl_easy_perform(curl);

  if (readBuffer.empty()) {
    return CurrentlyPlaying();
  }

  json request_result = json::parse(readBuffer);

  //check if request is successful
  long status_code;
  curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &status_code);
  if (status_code != 200 && status_code != 204) { //200 and 204 are success codes
    throw std::runtime_error(request_result["error"]);
  }

  curl_easy_cleanup(curl);
  return CurrentlyPlaying(request_result);
}

bool SpotifyInfoHandler::IsAuthorized() {
  return !api_access_token_.empty();
}

string SpotifyInfoHandler::FetchAccessToken() {
  CURL * curl;
  curl = curl_easy_init();
  string readBuffer;

  if (!curl) {
    throw std::runtime_error("CURL failed to initiate.");
  }

  //endpoint to retrieve access token from Spotify
  curl_easy_setopt(curl, CURLOPT_URL, "https://accounts.spotify.com/api/token");

  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

  //don't have Spotify's server certificate, need to disable authentication
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);

  curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
  //request body specified in Spotify API docs
  string post_request_body =
          "grant_type=refresh_token&refresh_token="+ refresh_token_ +
          "&client_id=" + kClientID +
          "&client_secret=" + kClientSecret;
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_request_body.c_str());

  curl_easy_perform(curl);
  curl_easy_cleanup(curl);

  json request_result = json::parse(readBuffer);
  return request_result["access_token"];
}

size_t SpotifyInfoHandler::WriteCallback(void *contents, size_t size,
                                                size_t nmemb, void *userp) {
  ((std::string*)userp)->append((char*)contents, size * nmemb);
  return size * nmemb;
}

} // namespace spotifyhandler

} // namespace musicvisualizer