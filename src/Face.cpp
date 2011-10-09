/*
 * Face.cpp
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

#include "Face.h"

Face::Face(){

}

Face::Face(Edge newa, Edge newb, Edge newc){
	a=newa;
	b=newb;
	c=newc;
}

Face::~Face() {
	// TODO Auto-generated destructor stub
}

Edge Face::getEdgeA(){
	return a;
}

Edge Face::getEdgeB(){
	return b;
}

Edge Face::getEdgeC(){
	return c;
}

