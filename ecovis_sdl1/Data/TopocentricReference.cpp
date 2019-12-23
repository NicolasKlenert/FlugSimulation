/*
 * TopocentricReference.cpp
 *
 *  Created on: 02.01.2009
 *      Author: st
 */

#include "TopocentricReference.h"
#include "constants.h"
#include <math.h>

TopocentricReference::TopocentricReference()
{}

TopocentricReference::TopocentricReference(const GeographicCoordinate &datum):
	datum(datum)
{
	set(datum.getLatitude(), datum.getLongitude(), datum.getAltitude());
}

void TopocentricReference::set(double lat, double lon, double alt){
	if (!datum.testAndSet(lat,lon,alt)){

		double sinLat = sin(datum.getLatitude());
		double cosLat = cos(datum.getLatitude());
		double sinLon = sin(datum.getLongitude());
		double cosLon = cos(datum.getLongitude());

		double theta = WGS84_A/sqrt(1 - WGS84_E_SQR * sinLat * sinLat);

		X[e_X] = (theta + alt) * cosLat * cosLon;
		X[e_Y] = (theta + alt) * cosLat * sinLon;
		X[e_Z] = (theta*(1 - WGS84_E_SQR) + alt) * sinLat;

		Vector east(-sinLon, cosLon, 0);
		Vector north(-sinLat*cosLon, -sinLat*sinLon, cosLat);
		Vector up(cosLat*cosLon, cosLat*sinLon, sinLat);

		trafo.set(east, north, up);
		reverse = trafo.affineTranspose();
		trafo[12] = X[0];
		trafo[13] = X[1];
		trafo[14] = X[2];
		reverse[14] = - abs();
	}
}

TopocentricReference::~TopocentricReference() {
}

GeographicCoordinate TopocentricReference::getAbsoluteCoordinate(const TopocentricCoordinate &value) const{
	// what we do here:
	// result = R' * value + X_0
	return GeographicCoordinate(reverse * value);
}

TopocentricCoordinate TopocentricReference::getRelativeCoordinate(const GeographicCoordinate &value) const
{
	// what we do here:
	// result = R * (value - reference)
	TopocentricCoordinate result(this);
	result.set(trafo*(GeocentricCoordinate(value) - *this));
	return result;
}

const Matrix* TopocentricReference::getTrafo() const{
	return &trafo;
}
const Matrix* TopocentricReference::getReverseTrafo() const{
	return &reverse;
}
const GeographicCoordinate* TopocentricReference::getRefPoint(){
	return &datum;
}
