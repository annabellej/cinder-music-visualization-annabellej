#include "visualizer/sound_color_utils.h"

namespace musicvisualizer {

namespace soundcolorutil {

double CalculateNoteFrequency(int half_steps) {
  return kStandardNoteFrequency * pow(kNoteFactor, half_steps);
}

double ConvertToLightFrequency(double sound_frequency) {
  return sound_frequency * kConversionFactor;
}

double ConvertFrequencyToWavelength(double frequency) {
  //divide by 1000 for unit conversions in calculations
  return (kLightSpeed / frequency) / 1000.0;
}

ci::Color ApproximatePitchColor(double wavelength) {
  double red, green, blue;

  //adjust R,G,B values based on range in visible light spectrum (violet to red)
  if (wavelength >= 380.0 && wavelength < 440.0) { //in violet range
    red = -(wavelength - 440.0) / (440.0 - 380.0);
    green = 0.0;
    blue = 1.0;
  } else if (wavelength >= 440.0 && wavelength < 490.0) { //in green/blue range
    red = 0.0;
    green = (wavelength - 440.0) / (490.0 - 440.0);
    blue = 1.0;
  } else if (wavelength >= 490.0 && wavelength < 510.0) { //in green range
    red = 0.0;
    green = 1.0;
    blue = -(wavelength - 490.0) / (510.0 - 490.0);
  } else if (wavelength >= 510.0 && wavelength < 580.0) { //in yellow/green range
    red = (wavelength - 510.0) / (580.0 - 510.0);
    green = 1.0;
    blue = 0.0;
  } else if (wavelength >= 580.0 && wavelength < 645.0) { //in orange/yellow range
    red = 1.0;
    green = -(wavelength - 645.0) / (645.0 - 580.0);
    blue = 0.0;
  } else if (wavelength >= 645.0 && wavelength <= 780.0) { //in red range
    red = 1.0;
    green = blue = 0.0;
  } else { //black
    red = green = blue = 0.0;
  }

  return ci::Color(red, green, blue);
}

ci::Color AdjustTimbreColor(const ci::Color& original_color, float brightness) {
  //get brightness as decimal value
  float brightness_factor = kBrightnessAdjustment * (brightness / 1000.0);

  //add adjusted values
  return ci::Color(original_color.r + original_color.r * brightness_factor,
                   original_color.g + original_color.g * brightness_factor,
                   original_color.b + original_color.b * brightness_factor);
}

} // namespace soundcolorutil

} // namespace musicvisualizer