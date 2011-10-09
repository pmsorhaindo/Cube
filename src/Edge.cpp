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


