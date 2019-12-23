/*
 * Vector.h
 *
 *  Created on: 04.01.2009
 *      Author: st
 */

#ifndef VECTOR_H_
#define VECTOR_H_
#include "constants.h"
#include <math.h>
class Vector {
public:
	inline Vector(){}
	inline Vector(const Vector& value){
		X[0] = value[0];
		X[1] = value[1];
		X[2] = value[2];
	}
	explicit inline Vector(const double value[3]){
		X[0] = value[0];
		X[1] = value[1];
		X[2] = value[2];
	}
	Vector(double x, double y, double z);

	inline double& operator[](int i){return X[i];}
	inline double operator[](int i) const{return X[i];}

	Vector& operator=(const Vector& value);
	const Vector operator+(const Vector& value)const;
	const Vector operator-(const Vector& value)const;
	const Vector operator-()const;
	inline double operator*(const Vector& value)const {
		return  X[e_X] * value[e_X]
		      + X[e_Y] * value[e_Y]
		      + X[e_Z] * value[e_Z];
	}
	inline const Vector operator*(double factor)const{
		Vector result;
		result[e_X] = X[e_X] * factor;
		result[e_Y] = X[e_Y] * factor;
		result[e_Z] = X[e_Z] * factor;
		return result;
	}
	const Vector times(const Vector& value)const;
	inline double abs()const{
		return  sqrt(
				X[e_X] * X[e_X] +
				X[e_Y] * X[e_Y] +
				X[e_Z] * X[e_Z]);
	}
	const Vector normalize()const;
	inline operator const double *const() const { return X;}
	Vector &operator+=(const Vector &value);
	Vector &operator-=(const Vector &value);
	Vector &operator*=(double value);

	double getAngleTo(const Vector &v) const;
	void zero();

private:
	double X[3];
};

#endif /* VECTOR_H_ */
