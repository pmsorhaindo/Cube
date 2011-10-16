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
	Vertex edgeMidPoint(Edge e1);
	void edgeMidPointArr(Edge edgeArr[],int size);
	Vertex getCentroid(Vertex v1, Vertex v2, Vertex v3);
	Vertex getEdgePoint(Edge edg);
};

#endif /* GEOMETRYOPS_H_ */
