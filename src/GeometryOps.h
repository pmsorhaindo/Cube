/*
 * GeometryOps.h
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

#ifndef GEOMETRYOPS_H_
#define GEOMETRYOPS_H_
#include "Face.h"

class GeometryOps {
public:
	GeometryOps();
	virtual ~GeometryOps();
	Vertex edgeMidPoint(Edge e1, Edge e2);
};

#endif /* GEOMETRYOPS_H_ */
