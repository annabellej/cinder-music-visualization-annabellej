#pragma once

#include <math.h>

namespace musicvisualizer {

/**
 * Rounds a double to the nearest tenth.
 *
 * @param number the number to round.
 *
 * @return the given number rounded to the nearest tenth.
 */
double RoundToNearestTenth(double number);

/**
 * Compares whether two double values are equal up to 1 decimal place.
 *
 * @param first  the first value to compare.
 * @param second the second value to compare.
 *
 * @return true  if the values are equal up to the first decimal place, else
 *         false if they are not equal.
 */
bool AreDoublesEqual(double first, double second);

}