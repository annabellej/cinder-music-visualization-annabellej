#include <catch2/catch.hpp>
#include "core/spotify_information_retriever.h"
#include "core/spotify-model/currently_playing.h"
#include "../tests/testing_utils.h"

using testingutils::PutFileInJson;
using musicvisualizer::spotifyhandler::SpotifyInfoRetriever;
using musicvisualizer::spotifyhandler::CurrentlyPlaying;

SpotifyInfoRetriever test_handler = SpotifyInfoRetriever();

TEST_CASE("Spotify Info Handler properly acquires authorization for API") {
  REQUIRE(test_handler.IsAuthorized());
}

TEST_CASE("Info Handler records blank information when no music is played") {
  CurrentlyPlaying test_current_playing;

  SECTION("No error should be thrown if user not currently playing music") {
    REQUIRE_NOTHROW(test_current_playing = test_handler.FetchCurrentlyPlaying());
  }

  SECTION("Blank/default information stored when user not current playing music") {
    SECTION("Time progress of song should be at 0 since no song is playing") {
      REQUIRE(test_current_playing.GetProgress() == 0);
    }

    SECTION("Blank song information stored") {
      REQUIRE(test_current_playing.GetCurrentTrack().GetTrackName() == "No Current Track");
    }

    SECTION("Blank song artist information stored") {
      REQUIRE(test_current_playing.GetCurrentTrack().GetArtistAt(0).GetName() == "No Artist");
    }
  }
}

TEST_CASE("Empty JSON files handled by nlohmann library, cannot be used at all") {
  REQUIRE_THROWS_AS(PutFileInJson("resources/emptyFile.json"), std::invalid_argument);
}