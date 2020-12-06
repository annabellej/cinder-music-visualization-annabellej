#pragma once

#include <cmath>
#include "cinder/gl/gl.h"

namespace musicvisualizer {

namespace soundcolorutil {

//standard fixed note frequency of A4 used to pitch frequency calculations
const double kStandardNoteFrequency = 440.0;
//constant for the twelfth root of two, used in frequency calculations
const double kNoteFactor = pow(2.0, 1.0 / 12.0);
//kConversionFactor * 10^12 is multiplier for raising a frequency by 40 octaves (2^40)
const double kConversionFactor = 1.0995;
//speed of light 3x10^8 meters/second
const double kLightSpeed = 300000000.0;
//factor to adjust Spotify given brightness values
const double kBrightnessAdjustment = 5.0;

//visible light wavelength constants:
const double kMinVisibleWavelength = 380.0; //lower limit for violet range
const double kLowerBlueBound = 440.0; //lower limit for blue range
const double kLowerGreenBound = 490.0; //lower limit for green range
const double kLowerYellowBound = 510.0; //lower limit for yellow range
const double kLowerOrangeBound = 580.0; //lower limit for orange range
const double kLowerRedBound = 645.0; //lower limit for red range
const double kMaxVisibleWavelength = 780.0; //upper limit for red range

/**
 * Calculates the frequency in Hz for a musical note that is a given number of
 * half steps away from the standard A4 note of 440 Hz.
 *
 * Based on formula f(n) = f0 * a^n where n is number of half steps away from
 * fixed note, f0 is fixed note frequency (A4 in this case), a is constant
 * denoting the twelfth root of 2 (each note separated by factor of a).
 *
 * @param half_steps number of half note steps away from standard A4.
 *
 * @return the frequency in Hz of the given note w/ a certain number of steps
 *         away from A4.
 */
double CalculateNoteFrequency(int half_steps);

/**
 * Converts an audible sound frequency in the range 20 to 20,000 Hz to a
 * corresponding light frequency in THz (TerraHertz) range by raising the
 * given sound frequency by 40 octaves.
 *
 * @param sound_frequency the sound frequency value to convert.
 *
 * @return the corresponding light frequency in THz.
 */
double ConvertToLightFrequency(double sound_frequency);

/**
 * Calculates the wavelength for a given THz frequency of light based on formula
 * wavelength = speed of light / frequency.
 *
 * @param frequency the frequency to convert in THz.
 *
 * @return the corresponding wavelength in nanometers.
 */
double ConvertFrequencyToWavelength(double frequency);

/**
 * Given the wavelength of a color, convert to its approximate RGB color.
 * Based on approximation method by: http://www.physics.sfasu.edu/astro/color/spectra.html
 *
 * @param wavelength the wavelength in nanometers of the color to convert.
 *
 * @return the approximate color of a given wavelength.
 */
ci::Color ApproximatePitchColor(double wavelength);

/**
 * Adjust a color based on musical brightness/timbre to darken or lighten
 * the color. Color adjustment referenced from:
 * https://graphicdesign.stackexchange.com/questions/75417/how-to-make-a-given-color-a-bit-darker-or-lighter
 *
 * @param original_color original color to adjust.
 * @param brightness     musical brightness of a song.
 *
 * @return the color adjusted for brightness.
 */
ci::Color AdjustTimbreColor(const ci::Color& original_color, float brightness);

} // namespace soundcolorutil

} // namespace musicvisualizer