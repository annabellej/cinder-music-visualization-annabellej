#include <catch2/catch.hpp>
#include "core/spotify-model/track.h"
#include "../tests/testing_utils.h"
#include <string>

using std::string;
using nlohmann::json;
using testingutils::PutFileInJson;
using musicvisualizer::spotifyhandler::Track;

TEST_CASE("Valid Spotify Track is deserialized properly") {
  Track test_track;
  REQUIRE_NOTHROW(test_track = Track(PutFileInJson("resources/validTrack.json")));

  SECTION("Correct id value is read from file") {
    REQUIRE(test_track.GetSpotifyID() == "randomid");
  }

  SECTION("Correct track name is read from file") {
    REQUIRE(test_track.GetTrackName() == "randomname");
  }

  SECTION("Correct artists for track are read in") {
    REQUIRE(test_track.GetNumArtists() > 0);
    REQUIRE(test_track.GetArtistAt(0).GetName() == "random");
    REQUIRE(test_track.GetArtistAt(1).GetName() == "anotherrandom");
  }
}

TEST_CASE("Invalid Track values from json are not accepted") {
  SECTION("Empty value for track's unique id is not accepted") {
    REQUIRE_THROWS_AS(Track(PutFileInJson("resources/noIDTrack.json")),std::invalid_argument);
  }

  SECTION("Empty value for track title is not accepted") {
    REQUIRE_THROWS_AS(Track(PutFileInJson("resources/noTitleTrack.json")),std::invalid_argument);
  }

  SECTION("A track with no artists is not accepted") {
    REQUIRE_THROWS_AS(Track(PutFileInJson("resources/noArtistsTrack.json")),std::invalid_argument);
  }
}