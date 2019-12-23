#pragma once
#ifndef NICOLAS_KLENERT_NOISE
#define NICOLAS_KLENERT_NOISE

#include "RandomNumberGenerator.h"

class Noise {
public: 
	bool setRNG(RandomNumberGenerator rng);
	double noise(double x);
	double noise(double x, double y);
	double noise(double x, double y, double z);
	double noise(double params[]);
};

#endif // !NICOLAS_KLENERT_NOISE

