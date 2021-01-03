/**
    Name: attitudelib
    Description: a pure template header-only library for orientation representations

    @author Tommaso Marroni
*/

#include <iostream>
#include <Eigen/Dense>

#define EPSILON 0.000001

namespace attitudelib {

//#include "declarations.h"

#include "utils.h"
#include "dcm.h"    // Direction Cosine Matrix
#include "ea.h"     // Euler Angles
#include "prp.h"    // Principal Rotation Parameters (Axis, Vector)
#include "quat.h"   // Quaternions
#include "crp.h"    // Classical Rodrigues Parameters
#include "mrp.h"    // Modified Rodrigues Parameters
#include "sop.h"    // Stereographic Orientation Parameters
//#include "utils.h"  // Utilities: transformations between representations, ...

}
