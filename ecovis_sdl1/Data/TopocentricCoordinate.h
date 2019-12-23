/*
 * TopocentricCoordinate.h
 *
 *  Created on: 01.01.2009
 *      Author: st
 */

#ifndef TOPOCENTRICCOORDINATE_H_
#define TOPOCENTRICCOORDINATE_H_

#include "Coordinate.h"

class TopocentricReference;

class TopocentricCoordinate:
	public Coordinate {
public:
	TopocentricCoordinate();
	TopocentricCoordinate(const TopocentricCoordinate &value);
	TopocentricCoordinate(const TopocentricReference *const reference);
	virtual ~TopocentricCoordinate();

	void setReference(const TopocentricReference *const reference);
	const TopocentricReference* getReference() const;

	void set(const Vector &value);

private:
	const TopocentricReference *reference;
};

#endif /* TOPOCENTRICCOORDINATE_H_ */
