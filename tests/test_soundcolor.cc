#include <catch2/catch.hpp>
#include "visualizer/sound_color_utils.h"

//using entire sound color namespace
using namespace musicvisualizer::soundcolorutil;

TEST_CASE("Note frequencies for 12 basic pitches around standard A4 are calculated correctly") {
  SECTION("C4 pitch frequency is correct") {
    REQUIRE(CalculateNoteFrequency(-9) == Approx(261.63).epsilon(0.05));
  }

  SECTION("C#4 pitch frequency is correct") {
    REQUIRE(CalculateNoteFrequency(-8) == Approx(277.18).epsilon(0.05));
  }

  SECTION("D4 pitch frequency is correct") {
    REQUIRE(CalculateNoteFrequency(-7) == Approx(293.66).epsilon(0.05));
  }

  SECTION("D#4 pitch frequency is correct") {
    REQUIRE(CalculateNoteFrequency(-6) == Approx(311.13).epsilon(0.05));
  }

  SECTION("E4 pitch frequency is correct") {
    REQUIRE(CalculateNoteFrequency(-5) == Approx(329.63).epsilon(0.05));
  }

  SECTION("F4 pitch frequency is correct") {
    REQUIRE(CalculateNoteFrequency(-4) == Approx(349.23).epsilon(0.05));
  }

  SECTION("F#4 pitch frequency is correct") {
    REQUIRE(CalculateNoteFrequency(-3) == Approx(369.99).epsilon(0.05));
  }

  SECTION("G4 pitch frequency is correct") {
    REQUIRE(CalculateNoteFrequency(-2) == Approx(392.00).epsilon(0.05));
  }

  SECTION("G#4 pitch frequency is correct") {
    REQUIRE(CalculateNoteFrequency(-1) == Approx(415.30).epsilon(0.05));
  }

  SECTION("A4 pitch frequency is correct") {
    REQUIRE(CalculateNoteFrequency(0) == Approx(440.00).epsilon(0.05));
  }

  SECTION("A#4 pitch frequency is correct") {
    REQUIRE(CalculateNoteFrequency(1) == Approx(466.16).epsilon(0.05));
  }

  SECTION("B4 pitch frequency is correct") {
    REQUIRE(CalculateNoteFrequency(2) == Approx(493.88).epsilon(0.05));
  }
}

TEST_CASE("Corresponding light frequencies for 12 basic pitches are calculated correctly") {
  SECTION("C4 light frequency is correct (in THz)") {
    REQUIRE(ConvertToLightFrequency(261.63) == Approx(287.66).epsilon(0.05));
  }

  SECTION("C#4 light frequency is correct (in THz)") {
    REQUIRE(ConvertToLightFrequency(277.18) == Approx(304.76).epsilon(0.05));
  }

  SECTION("D4 light frequency is correct (in THz)") {
    REQUIRE(ConvertToLightFrequency(293.66) == Approx(322.88).epsilon(0.05));
  }

  SECTION("D#4 light frequency is correct (in THz)") {
    REQUIRE(ConvertToLightFrequency(311.13) == Approx(342.09).epsilon(0.05));
  }

  SECTION("E4 light frequency is correct (in THz)") {
    REQUIRE(ConvertToLightFrequency(329.63) == Approx(362.43).epsilon(0.05));
  }

  SECTION("F4 light frequency is correct (in THz)") {
    REQUIRE(ConvertToLightFrequency(349.23) == Approx(383.98).epsilon(0.05));
  }

  SECTION("F#4 light frequency is correct (in THz)") {
    REQUIRE(ConvertToLightFrequency(369.99) == Approx(406.80).epsilon(0.05));
  }

  SECTION("G4 light frequency is correct (in THz)") {
    REQUIRE(ConvertToLightFrequency(392.00) == Approx(431.00).epsilon(0.05));
  }

  SECTION("G#4 light frequency is correct (in THz)") {
    REQUIRE(ConvertToLightFrequency(415.30) == Approx(456.62).epsilon(0.05));
  }

  SECTION("A4 light frequency is correct (in THz)") {
    REQUIRE(ConvertToLightFrequency(440.00) == Approx(483.78).epsilon(0.05));
  }

  SECTION("A#4 light frequency is correct (in THz)") {
    REQUIRE(ConvertToLightFrequency(466.16) == Approx(512.87).epsilon(0.05));
  }

  SECTION("B4 light frequency is correct (in THz)") {
    REQUIRE(ConvertToLightFrequency(493.88) == Approx(543.02).epsilon(0.05));
  }
}

TEST_CASE("Wavelengths from light frequencies calculated correctly for 12 pitches") {
  SECTION("C4 pitch wavelength is correct") {
    REQUIRE(ConvertFrequencyToWavelength(287.66) == Approx(1042.90).epsilon(0.05));
  }

  SECTION("C#4 pitch wavelength is correct") {
    REQUIRE(ConvertFrequencyToWavelength(304.76) == Approx(984.38).epsilon(0.05));
  }

  SECTION("D4 pitch wavelength is correct") {
    REQUIRE(ConvertFrequencyToWavelength(322.88) == Approx(929.14).epsilon(0.05));
  }

  SECTION("D#4 pitch wavelength is correct") {
    REQUIRE(ConvertFrequencyToWavelength(342.09) == Approx(876.96).epsilon(0.05));
  }

  SECTION("E4 pitch wavelength is correct") {
    REQUIRE(ConvertFrequencyToWavelength(362.43) == Approx(827.75).epsilon(0.05));
  }

  SECTION("F4 pitch wavelength is correct") {
    REQUIRE(ConvertFrequencyToWavelength(383.98) == Approx(781.29).epsilon(0.05));
  }

  SECTION("F#4 pitch wavelength is correct") {
    REQUIRE(ConvertFrequencyToWavelength(406.80) == Approx(737.46).epsilon(0.05));
  }

  SECTION("G4 pitch wavelength is correct") {
    REQUIRE(ConvertFrequencyToWavelength(431.00) == Approx(696.06).epsilon(0.05));
  }

  SECTION("G#4 pitch wavelength is correct") {
    REQUIRE(ConvertFrequencyToWavelength(456.62) == Approx(657.00).epsilon(0.05));
  }

  SECTION("A4 pitch wavelength is correct") {
    REQUIRE(ConvertFrequencyToWavelength(483.78) == Approx(620.12).epsilon(0.05));
  }

  SECTION("A#4 pitch wavelength is correct") {
    REQUIRE(ConvertFrequencyToWavelength(512.87) == Approx(584.94).epsilon(0.05));
  }

  SECTION("B4 pitch wavelength is correct") {
    REQUIRE(ConvertFrequencyToWavelength(543.02) == Approx(552.47).epsilon(0.05));
  }
}

TEST_CASE("RGB approximation of wavelength values is accurate") {
  SECTION("Violet range wavelength is correct") {
    REQUIRE(ApproximatePitchColor(400.0) == ci::Color(0.67, 0.0, 1.0));
  }

  SECTION("Blue range wavelength is correct") {
    REQUIRE(ApproximatePitchColor(450.0) == ci::Color(0.0, 0.2, 1.0));
  }

  SECTION("Green range wavelength is correct") {
    REQUIRE(ApproximatePitchColor(500.0) == ci::Color(0.0, 1.0, 0.5));
  }

  SECTION("Yellow range wavelength is correct") {
    REQUIRE(ApproximatePitchColor(550.0) == ci::Color(0.57, 1.0, 0.0));
  }

  SECTION("Orange range wavelength is correct") {
    REQUIRE(ApproximatePitchColor(600.0) == ci::Color(1.0, 0.69, 0.0));
  }

  SECTION("Red range wavelength is correct") {
    REQUIRE(ApproximatePitchColor(700.0) == ci::Color(1.0, 0.0, 0.0));
  }

  SECTION("Out of range wavelength is black") {
    REQUIRE(ApproximatePitchColor(781.0) == ci::Color("black"));
    REQUIRE(ApproximatePitchColor(379.0) == ci::Color("black"));
  }
}

TEST_CASE("Timbre is adjusted properly by brightness value") {
  ci::Color original = ci::Color(0.5, 0.5, 0.5);

  SECTION("Color is adjusted to be brighter by the right amount") {
    REQUIRE(AdjustTimbreColor(original, 80) == ci::Color(0.7, 0.7, 0.7));
  }

  SECTION("Color is adjusted to be darker by the right amount") {
    REQUIRE(AdjustTimbreColor(original, -150) == ci::Color(0.13, 0.13, 0.13));
  }

  SECTION("Color is original color if adjusted to be black (too dark)") {
    REQUIRE(AdjustTimbreColor(original, -200000) == original);
  }
}