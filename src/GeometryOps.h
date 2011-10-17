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

	typedef struct twoFaces_struct{
				Face faceOne;
				Face faceTwo;
			} twoFace;

public:
	GeometryOps();
	virtual ~GeometryOps();
	Vertex edgeMidPoint(Edge e1);
	Vertex getCentroid(Vertex v1, Vertex v2, Vertex v3);
	Vertex getEdgePoint(Edge edg);
	bool compareVertices(Vertex v1,Vertex v2);
	twoFace getOtherFace(Edge e);
};

#endif /* GEOMETRYOPS_H_ */
