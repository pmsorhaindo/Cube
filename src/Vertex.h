/*
 * Vertex.h
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

#ifndef VERTEX_H_
#define VERTEX_H_

class Edge;
class Vertex {

private:
	float x;
	float y;
	float z;


public:
	Vertex();
	Vertex(float newX, float newY, float newZ);
	virtual ~Vertex();
	float getX();
	float getY();
	float getZ();

};

#endif /* VERTEX_H_ */
