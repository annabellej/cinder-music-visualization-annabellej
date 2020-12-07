#pragma once

#include "curl/curl.h"
#include "nlohmann/json.hpp"
#include <string>

namespace musicvisualizer {

namespace spotifyhandler {

/**
 * Use of curl references tutorials/examples:
 * https://curl.se/libcurl/c/libcurl-tutorial.html
 * https://github.com/curl/curl/blob/master/docs/examples/getinmemory.c
 */
namespace curlutils {

using std::string;
using nlohmann::json;

/**
 * Sends an HTTP request to Spotify given the specified arguments.
 *
 * @param endpoint      URL endpoint to send request to.
 * @param method        request method type; GET, POST, etc.
 * @param access_token  token used if request requires authorization.
 * @param request_body  body of request if needed.
 *
 * @return JSON file containing response data.
 *
 * @throws  std::runtime_error  when CURL is unable to initiate or perform request.
 * @throws  std::logic_error    when request produces nonexistent information.
 */
json SendRequest(const string& endpoint, const string& method,
                 const string& access_token, const string& request_body);

/**
 * Curl function used to handle receiving a response from Spotify.
 */
size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                            void *userp);

/**
 * Opens the given link in a browser.
 *
 * @param url the url to visit.
 */
void OpenBrowserLink(const string& url);

} // namespace curlutils

} // namespace spotifyhandler

} //namespace musicvisualizer