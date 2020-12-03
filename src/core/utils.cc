#include "core/utils.h"

namespace musicvisualizer {

double RoundToNearestTenth(double number) {
  double result = (int) (number * 10 + 0.5);
  return result / 10;
}

bool AreDoublesEqual(double first, double second) {
  return trunc(10. * first) == trunc(10. * second);
}

}