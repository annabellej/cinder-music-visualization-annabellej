#include <catch2/catch.hpp>
#include "core/spotify-model/audio_segment.h"
#include "../tests/testing_utils.h"
#include <string>

using std::string;
using nlohmann::json;
using testingutils::PutFileInJson;
using musicvisualizer::spotifyhandler::Segment;

TEST_CASE("Valid Audio Segment is deserialized properly") {
  Segment test_segment;
  REQUIRE_NOTHROW(test_segment = Segment(PutFileInJson("resources/validSegment.json")));

  SECTION("Correct start time is read in from file") {
    REQUIRE(test_segment.GetStartTime() == Approx(0.23).epsilon(0.05));
  }

  SECTION("Correct time duration is read in from file") {
    REQUIRE(test_segment.GetDuration() == Approx(1.23).epsilon(0.05));
  }

  SECTION("Correct segment loudness is read in from file") {
    REQUIRE(test_segment.GetLoudness() == Approx(15.12).epsilon(0.05));
  }

  SECTION("Correct brightness value is read in from file") {
    REQUIRE(test_segment.GetBrightness() == Approx(0.2).epsilon(0.05));
  }

  SECTION("Correct pitches and values read in from file") {
    REQUIRE(test_segment.GetPitchCount() == 12);

    //check first and last values for accuracy
    REQUIRE(test_segment.GetPitchDominanceAt(0) == Approx(0.12).epsilon(0.05));
    REQUIRE(test_segment.GetPitchDominanceAt(11) == Approx(0.2).epsilon(0.05));
  }
}

TEST_CASE("Invalid Audio Segment files are not accepted") {
  SECTION("Start time of an audio segment cannot be negative") {
    REQUIRE_THROWS_AS(Segment(PutFileInJson("resources/negStartTimeSegment.json")), std::invalid_argument);
  }

  SECTION("Time duration of an audio segment cannot be negative") {
    REQUIRE_THROWS_AS(Segment(PutFileInJson("resources/negDurationSegment.json")), std::invalid_argument);
  }

  SECTION("Number of pitches must be 12; exactly 12 notes in chromatic scale") {
    REQUIRE_THROWS_AS(Segment(PutFileInJson("resources/notTwelvePitchesSegment.json")), std::invalid_argument);
  }
}