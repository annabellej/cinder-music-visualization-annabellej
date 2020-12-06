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
  if (wavelength >= kMinVisibleWavelength && wavelength < kLowerBlueBound) { //in violet range
    red = -(wavelength - kLowerBlueBound) / (kLowerBlueBound - kMinVisibleWavelength);
    green = 0.0;
    blue = 1.0;
  } else if (wavelength >= kLowerBlueBound && wavelength < kLowerGreenBound) { //in green/blue range
    red = 0.0;
    green = (wavelength - kLowerBlueBound) / (kLowerGreenBound - kLowerBlueBound);
    blue = 1.0;
  } else if (wavelength >= kLowerGreenBound && wavelength < kLowerYellowBound) { //in green range
    red = 0.0;
    green = 1.0;
    blue = -(wavelength - kLowerGreenBound) / (kLowerYellowBound - kLowerGreenBound);
  } else if (wavelength >= kLowerYellowBound && wavelength < kLowerOrangeBound) { //in yellow/green range
    red = (wavelength - kLowerYellowBound) / (kLowerOrangeBound - kLowerYellowBound);
    green = 1.0;
    blue = 0.0;
  } else if (wavelength >= kLowerOrangeBound && wavelength < kLowerRedBound) { //in orange/yellow range
    red = 1.0;
    green = -(wavelength - kLowerRedBound) / (kLowerRedBound - kLowerOrangeBound);
    blue = 0.0;
  } else if (wavelength >= kLowerRedBound && wavelength <= kMaxVisibleWavelength) { //in red range
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

  ci::Color adjusted_color = ci::Color(original_color.r + original_color.r * brightness_factor,
                                       original_color.g + original_color.g * brightness_factor,
                                       original_color.b + original_color.b * brightness_factor);

  //use original color if adjustments darkens to black (not visible on display)
  if (adjusted_color == ci::Color("black")) {
    return original_color;
  } else {
    return adjusted_color;
  }
}

} // namespace soundcolorutil

} // namespace musicvisualizer