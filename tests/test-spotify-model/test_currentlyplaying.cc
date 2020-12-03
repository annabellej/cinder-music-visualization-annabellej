#include <catch2/catch.hpp>
#include "core/spotify-model/currently_playing.h"
#include "../tests/testing_utils.h"
#include <string>

using std::string;
using nlohmann::json;
using testingutils::PutFileInJson;
using musicvisualizer::spotifyhandler::CurrentlyPlaying;

TEST_CASE("Valid CurrentlyPlaying json is deserialized properly") {
  CurrentlyPlaying test_info;
  REQUIRE_NOTHROW(test_info = CurrentlyPlaying(PutFileInJson("resources/validCurrentlyPlaying.json")));

  SECTION("Correct song time progress in seconds is read from file") {
    REQUIRE(test_info.GetProgress() == Approx(12.38).epsilon(0.05));
  }

  SECTION("Correct track is read in") {
    REQUIRE(test_info.GetCurrentTrack().GetTrackName() == "random");
  }
}

TEST_CASE("Time progress for a CurrentlyPlaying object cannot be negative") {
  REQUIRE_THROWS_AS(CurrentlyPlaying(PutFileInJson("resources/netProgressCP.json")), std::invalid_argument);
}