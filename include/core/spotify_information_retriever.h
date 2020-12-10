#pragma once

#include <string>
#include "nlohmann/json.hpp"
#include "curl/curl.h"
#include "core/spotify-model/artist.h"
#include "core/spotify-model/currently_playing.h"
#include "core/spotify-model/track.h"
#include "core/spotify-model/audio_analysis.h"
#include "core/spotify_curl_utils.h"

namespace musicvisualizer {

namespace spotifyhandler {

using std::string;
using nlohmann::json;
using musicvisualizer::spotifyhandler::CurrentlyPlaying;
using musicvisualizer::spotifyhandler::AudioAnalysis;
using musicvisualizer::spotifyhandler::curlutils::SendRequest;
using musicvisualizer::spotifyhandler::curlutils::OpenBrowserLink;

/**
 * Class handling information retrieval from Spotify API and Spotify Account
 * Services.
 *
 * Use of curl references tutorials/examples:
 * https://curl.se/libcurl/c/libcurl-tutorial.html
 * https://github.com/curl/curl/blob/master/docs/examples/getinmemory.c
 */
class SpotifyInfoRetriever {
  public:
    /**
     * Default constructor for a Spotify Information Handler.
     */
    SpotifyInfoRetriever();

    /**
     * Gets a Currently Playing object representing the music the user is
     * currently playing on Spotify.
     *
     * @return a Currently Playing object with information on what user is
     *         listening to currently.
     *
     * @throws std::runtime_error if error occurs trying to get information.
     */
    CurrentlyPlaying FetchCurrentlyPlaying() const;

    /**
     * Gets the Audio Analysis for a Spotify Song given the ID of the track.
     *
     * @param   song_id the Spotify ID for the song to fetch and analysis of.
     *
     * @return the Audio Analysis for the given song.
     */
    AudioAnalysis FetchAudioAnalysis(const string& song_id) const;

    /**
     * Determines if this application has been authorized (i.e. access token
     * has been retrieved) by Spotify and can work with user data.
     *
     * @return  true    if access token is retrieved from Spotify, else
     *          false   if access token is still empty.
     */
    bool IsAuthorized() const;

  private:
    //=====================
    //Member Variables
    //=====================
    string api_access_token_; //token needed to access Spotify user information

    //registered id for this app
    const string kClientID = "e4f67126c52e44129ece0e0b44cb1ba4";
    //app secret for secure calls to Spotify
    const string kClientSecret = "2394e5d88bce4dd49b02626b9e9902a3";
    //redirect uri to navigate to after authorizing
    const string kRedirectURI = "https://www.google.com/";
    //file containing refresh token information
    const string refresh_file_ = "project-files/refresh_token";
    //authorization code to retrieve tokens for user information
    const string authorization_code_ = "PASTE YOUR CODE HERE";
    //user-specific token used to retrieve access token from Spotify
    string refresh_token_;

    //=====================
    //Private Helper Methods
    //=====================
    /**
     * Retrieves a refresh token for the Spotify user.
     *
     * @return the refresh token for this user.
     */
    string FetchRefreshToken() const;

    /**
     * Retrieves a new access token from Spotify Account Services using a given
     * refresh token.
     *
     * @return the access token retrieved.
     *
     * @throws std::runtime_error when curl is unable to initiate to get token.
     * @throws std::logic_error   if refresh token does not give an access token.
     */
    string FetchAccessToken() const;
};

} // namespace spotifyhandler

} // namespace musicvisualizer