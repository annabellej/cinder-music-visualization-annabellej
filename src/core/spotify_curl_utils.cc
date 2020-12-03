#include "core/spotify_curl_utils.h"
#include <string>

namespace musicvisualizer {

namespace spotifyhandler {

namespace curlutils {

json SendRequest(const string& endpoint, const string& method,
                 const string& access_token, const string& request_body) {
  CURL * curl;
  curl = curl_easy_init();
  string readBuffer;

  if (!curl) {
    throw std::runtime_error("CURL failed to initiate.");
  }

  //endpoint to determine current user playback on Spotify
  curl_easy_setopt(curl, CURLOPT_URL, endpoint.c_str());
  //handle response from Spotify
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
  //don't have Spotify's server certificate, need to disable authentication
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
  //specify request type
  curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());

  //provide header with access token if authorization is needed
  if (!access_token.empty()) {
    //building custom header referenced from:
    //https://curl.se/libcurl/c/httpcustomheader.html
    string get_request_header = "Authorization: Bearer " + access_token;
    struct curl_slist *chunk = NULL;
    chunk = curl_slist_append(chunk, get_request_header.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
  }
  //include request body if needed
  if (!request_body.empty()) {
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request_body.c_str());
  }

  //perform request
  curl_easy_perform(curl);
  if (readBuffer.empty()) {
    throw std::logic_error("Requested nonexistent information.");
  }
  json request_result = json::parse(readBuffer);

  //check if request is successful
  long status_code;
  curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &status_code);
  if (status_code != 200 && status_code != 204) { //200 and 204 are success codes
    throw std::runtime_error(request_result["error"]);
  }

  //cleanup curl
  curl_easy_cleanup(curl);
  return request_result;
}

size_t WriteCallback(void *contents, size_t size,
                                         size_t nmemb, void *userp) {
  ((std::string*)userp)->append((char*)contents, size * nmemb);
  return size * nmemb;
}

} //namespace curlutils

} // namespace spotifyhandler

} //namespace musicvisualizer