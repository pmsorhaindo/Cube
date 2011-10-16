/*
 * Edge.cpp
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */
#include "Edge.h"

Edge::Edge(){

}

Edge::Edge(Vertex newa, Vertex newb){
	a=newa;
	b=newb;
	calcEdgeMidPoint();
}

Edge::~Edge() {
	// TODO Auto-generated destructor stub
}

Vertex Edge::getVertexA(){
	return a;
}

Vertex Edge::getVertexB(){
	return b;
}

void Edge::setJoinsFace(Face *a, Face *b){
	joinsFace1 = a;
	joinsFace2 = b;
}

Face * Edge::getFacesJoined1(){

	Face *joinedFaces;
	joinedFaces = joinsFace1;
	return joinedFaces;
}

Face * Edge::getFacesJoined2(){

	Face *joinedFaces;
	joinedFaces = joinsFace2;
	return joinedFaces;
}

void Edge::calcEdgeMidPoint()
{
	float tempvx = a.getX()-b.getX();
	float tempvy = a.getY()-b.getY();
	float tempvz = a.getZ()-b.getZ();
	Vertex midPoint = Vertex(tempvx,tempvy,tempvz);
}

Vertex Edge::getEdgeMidPoint()
{
	return midPoint;
}


