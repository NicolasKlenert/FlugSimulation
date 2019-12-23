/*
 * mathTools.h
 *
 *  Created on: 25.01.2009
 *      Author: st
 */

#ifndef MATHTOOLS_H_
#define MATHTOOLS_H_

	inline int sign(int xx)
	{
		if(xx<0) return -1;
		if(xx>0) return 1;
		return 0;
	}

	inline double sign(double xx)
	{
		if(xx<0) return -1;
		if(xx>0) return 1;
		return 0;
	}

	// r1 - radius from center to ring center -> phi corresponding angle
	// r2 - radius from ring center to ring surface -> theta corresponding angle
	inline void toroid2Cartesian(const double r1, const double phi, const double r2, const double theta, double result[3])
	{
		double r_eff = r1 + r2 * cos(theta);
		result[e_X] = cos(phi) * r_eff;
		result[e_Y] = sin(phi) * r_eff;
		result[e_Z] = r2 * sin(theta);
	}
#endif /* MATHTOOLS_H_ */
