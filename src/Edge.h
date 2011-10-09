/*
 * Edge.h
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

#ifndef EDGE_H_
#define EDGE_H_
#include "Vertex.h"

class Edge {

private:
	Vertex a;
	Vertex b;

public:
	Edge();
	Edge(Vertex newa, Vertex newb);
	virtual ~Edge();
	Vertex getVertexA();
	Vertex getVertexB();
};

#endif /* EDGE_H_ */
