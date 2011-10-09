/*
 * GeometryOps.cpp
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

#include "GeometryOps.h"

GeometryOps::GeometryOps() {
	// TODO Auto-generated constructor stub

}

GeometryOps::~GeometryOps() {
	// TODO Auto-generated destructor stub
}

Vertex GeometryOps::edgeMidPoint(Edge e1, Edge e2){

	float tempvx = e1.getVertexA().getX()-e2.getVertexB().getX();
	float tempvy = e1.getVertexA().getY()-e2.getVertexB().getY();
	float tempvz = e1.getVertexA().getZ()-e2.getVertexB().getZ();
	Vertex vert(tempvx,tempvy,tempvz);
	return vert;
}
