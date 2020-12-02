#include <catch2/catch.hpp>
#include "core/spotify-model/audio_analysis.h"
#include "../tests/testing_utils.h"
#include <string>

using std::string;
using nlohmann::json;
using testingutils::PutFileInJson;
using musicvisualizer::spotifyhandler::AudioAnalysis;

TEST_CASE("Valid Audio Analysis file is deserialized properly") {
  AudioAnalysis test_analysis;
  REQUIRE_NOTHROW(test_analysis = AudioAnalysis(PutFileInJson("resources/validAudioAnalysis.json")));

  SECTION("Correct file beat values are read into AudioAnalysis object") {
    REQUIRE(test_analysis.GetBeatTimeAt(0) == Approx(0.5).epsilon(0.05));
    REQUIRE(test_analysis.GetBeatTimeAt(1) == Approx(1.2).epsilon(0.05));
  }

  SECTION("Correct file Audio Segments are read into object") {
    REQUIRE(test_analysis.GetAudioSegmentAt(0).GetStartTime() == Approx(0.23).epsilon(0.05));
    REQUIRE(test_analysis.GetAudioSegmentAt(1).GetStartTime() == Approx(0.42).epsilon(0.05));
  }
}

TEST_CASE("Invalid Audio Analysis files are not accepted") {
  SECTION("Data cannot have no beats") {
    REQUIRE_THROWS_AS(AudioAnalysis(PutFileInJson("resources/noBeatsAudioAnalysis.json")), std::invalid_argument);
  }

  SECTION("Data cannot have no audio segments") {
    REQUIRE_THROWS_AS(AudioAnalysis(PutFileInJson("resources/noSegmentsAudioAnalysis.json")), std::invalid_argument);
  }
}