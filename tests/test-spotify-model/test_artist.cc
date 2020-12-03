#include <catch2/catch.hpp>
#include "core/spotify-model/artist.h"
#include "../tests/testing_utils.h"
#include <string>

using std::string;
using nlohmann::json;
using testingutils::PutFileInJson;
using musicvisualizer::spotifyhandler::Artist;

TEST_CASE("Valid Artist JSON file is deserialized properly") {
  Artist test_artist;
  REQUIRE_NOTHROW(test_artist = Artist(PutFileInJson("resources/validArtistFile.json")));
  REQUIRE_FALSE(test_artist.GetName().empty());
}

TEST_CASE("JSON file with empty Artist name is not accepted") {
  REQUIRE_THROWS_AS(Artist(PutFileInJson("resources/emptyArtistName.json")), std::invalid_argument);
}

TEST_CASE("Artist name cannot be set to empty.") {
  Artist test_artist;
  REQUIRE_THROWS_AS(test_artist.SetName(""), std::invalid_argument);
}