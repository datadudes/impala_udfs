#include "geo_utils.h"
#include <math.h>

// In this sample we are declaring a UDF that adds two ints and returns an int.
DoubleVal Distance(FunctionContext* context, const DoubleVal& lat1, const DoubleVal& long1, const DoubleVal& lat2, const DoubleVal& long2) {
  if (lat1.is_null || long1.is_null || lat2.is_null || long2.is_null) return DoubleVal::null();

  const double R = 6378.1;
  
  // Convert latitude and longitude to
  // spherical coordinates in radians.
  double degrees_to_radians = M_PI / 180.0;
  
  // phi = 90 - latitude
  double phi1 = (90.0 - lat1.val) * degrees_to_radians;
  double phi2 = (90.0 - lat2.val) * degrees_to_radians;
  
  // theta = longitude
  double theta1 = long1.val * degrees_to_radians;
  double theta2 = long2.val * degrees_to_radians;
  
  // Compute spherical distance from spherical coordinates.
  
  // For two locations in spherical coordinates
  // (1, theta, phi) and (1, theta, phi)
  // cosine( arc length ) =
  //    sin phi sin phi' cos(theta-theta') + cos phi cos phi'
  // distance = rho * arc length
  
  double cosine = (sin(phi1) * sin(phi2) * cos(theta1 - theta2) + cos(phi1) * cos(phi2));
  double arc = acos(cosine);
  
  // Remember to multiply arc by the radius of the earth
  // in your favorite set of units to get length.
  return DoubleVal(arc * R);
}