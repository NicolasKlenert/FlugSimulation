#include <math.h>

struct TimeFrame {
	double z0 = 0.0;   //z2 - z axis acceleration, z1 - z axis velocity, z0 - z axis position etc.
	double z1 = 0.0;
	double z2 = 0.0;
	double x0 = 0.0;   //x2 - x axis acceleration, x1 - x axis velocity, x0 - x axis position etc.
	double x1 = 0.0;
	double x2 = 0.0;
	double time = 0.0;
	double direction = 0.0; //in radians
	double power = 0.0;

	double forceLift = 0.0;
	double forceDragForm = 0.0;
	double forceDragInduced = 0.0;
	double forceTotalThrust = 0.0;
	double AoA = 0.0;

	double get_speed_squared() {
		return x1*x1 + z1*z1;
	}

	double get_speed_in_direction(const double angle) {
		return x1 * cos(angle) + z1 * sin(angle);
	}

	double get_direction_of_speed() {
		return atan2(z1,x1);
	}
};