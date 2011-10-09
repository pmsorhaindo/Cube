/*
 * Vertex.cpp
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

#include "Vertex.h"

Vertex::Vertex(){

}

Vertex::Vertex(float newX, float newY, float newZ) {
	x = newX;
	y = newY;
	z = newZ;
}

Vertex::~Vertex() {
	// TODO Auto-generated destructor stub
}

float Vertex::getX(){
	return x;
}

float Vertex::getY(){
	return y;
}


float Vertex::getZ(){
	return z;
}

