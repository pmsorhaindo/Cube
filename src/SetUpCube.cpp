/*
 * SetUpCube.cpp
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include "SetUpCube.h"

SetUpCube::SetUpCube() {
	Vertex v1 = Vertex(0.0f,1.0f,0.0f);//Top anti clock wise Front left to back left
	Vertex v2 = Vertex(1.0f,1.0f,0.0f);
	Vertex v3 = Vertex(1.0f,1.0f,-1.0f);
	Vertex v4 = Vertex(0.0f,1.0f,-1.0f);
	Vertex v5 = Vertex(0.0f,0.0f,0.0f);//Bottom anti clockwise From bottom left to back left
	Vertex v6 = Vertex(1.0f,0.0f,0.0f);
	Vertex v7 = Vertex(1.0f,0.0f,-1.0f);
	Vertex v8 = Vertex(0.0f,0.0f,-1.0f);

	Edge a = Edge(v1,v2); //top front
	Edge b = Edge(v2,v3); //top right
	Edge c = Edge(v3,v4); //top back
	Edge d = Edge(v4,v1); //top left
	Edge e = Edge(v1,v3); //top middle
	Edge f = Edge(v1,v5); //front left
	Edge g = Edge(v5,v6); // front bottom
	Edge h = Edge(v6,v2); //front right
	Edge i = Edge(v1,v6); // front middle
	Edge j = Edge(v8,v5); //bottom left
	Edge k = Edge(v6,v7); //bottom right
	Edge l = Edge(v7,v8); //bottom back
	Edge m = Edge(v7,v5); // bottom middle
	Edge n = Edge(v4,v8); // back left
	Edge o = Edge(v7,v3); // back right
	Edge p = Edge(v4,v7); // back middle
	Edge q = Edge(v1,v8); // left middle
	Edge r = Edge(v3,v6); // right middle

	//surface -> face
	Face one = Face(e,c,d); //top back
	Face two = Face(a,b,e); //top front
	Face three = Face(i,h,a); // front top
	Face four = Face(f,g,i); //front bottom
	Face five = Face(m,g,k); // bottom front
	Face six = Face(l,j,m); //bottom back
	Face seven = Face(n,reverseEdge(l),reverseEdge(p)); // back bottom
	Face eight = Face(o,c,p); //Back top
	Face nine = Face(q,reverseEdge(n),f); // left top
	Face ten = Face(f,reverseEdge(j),reverseEdge(q)); //left bottom
	Face eleven = Face(reverseEdge(b),reverseEdge(h),reverseEdge(r)); // right top
	Face twelve = Face(k,o,r); // right bottom

	faceArray[0] = one;
	faceArray[1] = two;
	faceArray[2] = three;
	faceArray[3] = four;
	faceArray[4] = five;
	faceArray[5] = six;
	faceArray[6] = seven;
	faceArray[7] = eight;
	faceArray[8] = nine;
	faceArray[9] = ten;
	faceArray[10] = eleven;
	faceArray[11] = twelve;

	rotAng = 0.0f;

}

SetUpCube::~SetUpCube() {
	// TODO Auto-generated destructor stub
}

Edge SetUpCube::reverseEdge(Edge reversing){
	Edge tempEdge = Edge(reversing.getVertexB(),reversing.getVertexA());
	return tempEdge;
}

Face * SetUpCube::getFaceArray(){
	return faceArray;
}

void SetUpCube::draw(){
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
		// Reset The Current Modelview Matrix
		glLoadIdentity();
		// put the thing somewhere between the near and far clipping panes
		glTranslatef(0.0f,0.0f,-5.0f);
		glRotatef(rotAng,0.0f,1.0f,1.0);

		for(int i = 0; i<12;i++)
			{
				glBegin(GL_TRIANGLES);
				//OpenGL must be counter clockwise!

				if(i%2==1)
				{
					glColor3f(1.0f,0.0f,0.0f); //Red
				}
				else
				{
					glColor3f(0.0f,0.0f,1.0f); //Blue
				}

				glVertex3f(faceArray[i].getEdgeA().getVertexA().getX(),faceArray[i].getEdgeA().getVertexA().getY(),faceArray[i].getEdgeA().getVertexA().getZ()); //
				glVertex3f(faceArray[i].getEdgeA().getVertexB().getX(),faceArray[i].getEdgeA().getVertexB().getY(),faceArray[i].getEdgeA().getVertexB().getZ());
				glVertex3f(faceArray[i].getEdgeB().getVertexB().getX(),faceArray[i].getEdgeB().getVertexB().getY(),faceArray[i].getEdgeB().getVertexB().getZ());

				glEnd();
			}
		rotAng += 0.2;
}
