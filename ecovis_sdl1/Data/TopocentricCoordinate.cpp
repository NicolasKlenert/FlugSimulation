/*
 * TopocentricCoordinate.cpp
 *
 *  Created on: 01.01.2009
 *      Author: st
 */

#include "TopocentricCoordinate.h"
#include <string.h>
#include "constants.h"
#include <math.h>

TopocentricCoordinate::TopocentricCoordinate(const TopocentricCoordinate &value):
	Coordinate(value),
	reference(value.reference)
{}

TopocentricCoordinate::TopocentricCoordinate():
	reference(NULL)
{}

TopocentricCoordinate::TopocentricCoordinate(const TopocentricReference *const reference):
	reference(reference)
{}

TopocentricCoordinate::~TopocentricCoordinate() {
}

void TopocentricCoordinate::setReference(const TopocentricReference *const reference){
	this->reference = reference;
}

const TopocentricReference* TopocentricCoordinate::getReference() const
{
	return reference;
}

void TopocentricCoordinate::set(const Vector &value){
	memcpy(X, value, sizeof(double)*3);
}
