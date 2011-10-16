/*
 * GeometryOps.cpp
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

#include "GeometryOps.h"
#include <iostream>

using namespace std;

GeometryOps::GeometryOps() {
	// TODO Auto-generated constructor stub

}

GeometryOps::~GeometryOps() {
	// TODO Auto-generated destructor stub
}

Vertex GeometryOps::edgeMidPoint(Edge e1){

	float tempvx = e1.getVertexA().getX()-e1.getVertexB().getX();
	float tempvy = e1.getVertexA().getY()-e1.getVertexB().getY();
	float tempvz = e1.getVertexA().getZ()-e1.getVertexB().getZ();
	Vertex vert(tempvx,tempvy,tempvz);
	return vert;
}

void GeometryOps::edgeMidPointArr(Edge*edgeArr,int size){
	for (int i=0;i<size;i++)
	{
		//cout << "Hi" << endl;
	}
	Vertex x = Vertex(1.0f,1.0f,1.0f);
}

Vertex GeometryOps::getCentroid(Vertex v1, Vertex v2, Vertex v3){
	float x =v1.getX()+v2.getX()+v3.getX();
	float y =v1.getY()+v2.getY()+v3.getY();
	float z =v1.getZ()+v2.getZ()+v3.getZ();
	Vertex v = Vertex(x,y,z);
	return v;
}

Vertex GeometryOps::getEdgePoint(Edge edg){

	Vertex v = Vertex(0.0f,0.0f,0.0f);
	return v;
}


