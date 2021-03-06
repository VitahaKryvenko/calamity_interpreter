#include "vtem.h"
#include <cmath>


namespace Vtem {
    const char * toString(bool boolean){
		return boolean ? "true" : "false";
	}

	int doubleCompare(const double & left, const double & right, const double &epsilon){
		return fabs(left - right) < epsilon
					? 0
					: (left < right) ? -1 : 1;
	}

	bool doubleEquals(const double & left, const double & right, const double & epsilon) {
		return fabs(left - right) < epsilon;
	}
}
