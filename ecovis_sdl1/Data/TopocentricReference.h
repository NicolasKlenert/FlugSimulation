/*
 * TopocentricReference.h
 *
 *  Created on: 02.01.2009
 *      Author: st
 */

#ifndef TOPOCENTRICREFERENCE_H_
#define TOPOCENTRICREFERENCE_H_

#include "GeographicCoordinate.h"
#include "GeocentricCoordinate.h"
#include "Matrix.h"
#include "TopocentricCoordinate.h"

class TopocentricReference:
	public GeocentricCoordinate{
public:
	TopocentricReference();
	TopocentricReference(const GeographicCoordinate &datum);
	virtual ~TopocentricReference();

	GeographicCoordinate getAbsoluteCoordinate(const TopocentricCoordinate &value) const;
	TopocentricCoordinate getRelativeCoordinate(const GeographicCoordinate &value) const;

	void set(double lat, double lon, double alt);
	const Matrix* getTrafo() const;
	const Matrix* getReverseTrafo() const;
	const GeographicCoordinate* getRefPoint();
private:
	GeographicCoordinate datum;
	Matrix trafo;
	Matrix reverse;
};

#endif /* TOPOCENTRICREFERENCE_H_ */
