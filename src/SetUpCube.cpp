/*
 * SetUpCube.cpp
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include "SetUpCube.h"
#include <iostream>

using namespace std;

SetUpCube::SetUpCube() {

	GeometryOps gOps = GeometryOps();

	Vertex v1 = Vertex(-0.5f,-0.5f,0.5f);//Front anti clock wise bottom left to top left
	Vertex v2 = Vertex(0.5f,-0.5f,0.5f);
	Vertex v3 = Vertex(0.5f,0.5f,0.5f);
	Vertex v4 = Vertex(-0.5f,0.5f,0.5f);
	Vertex v5 = Vertex(-0.5f,-0.5f,-0.5f);//Back anti clockwise From bottom left to top left
	Vertex v6 = Vertex(0.5f,-0.5f,-0.5f);
	Vertex v7 = Vertex(0.5f,0.5f,-0.5f);
	Vertex v8 = Vertex(-0.5f,0.5f,-0.5f);

	Edge a = Edge(v4,v3); //top front
	Edge b = Edge(v3,v7); //top right
	Edge c = Edge(v7,v8); //top back
	Edge d = Edge(v8,v4); //top left
	Edge e = Edge(v3,v8); //top middle
	Edge f = Edge(v2,v3); //front right
	Edge g = Edge(v1,v2); // front bottom
	Edge h = Edge(v1,v4); //front left
	Edge i = Edge(v3,v1); // front middle
	Edge j = Edge(v1,v5); //bottom left
	Edge k = Edge(v6,v2); //bottom right
	Edge l = Edge(v5,v6); //bottom back
	Edge m = Edge(v5,v2); // bottom middle
	Edge n = Edge(v8,v5); // back left
	Edge o = Edge(v6,v7); // back right
	Edge p = Edge(v5,v7); // back middle
	Edge q = Edge(v4,v5); // left middle
	Edge r = Edge(v3,v6); // right middle

	//surface -> face
	Face one = Face(c,reverseEdge(e),b); //top back g
	Face two = Face(d,a,e); //top front g
	Face three = Face(h,a,i); // front top g
	Face four = Face(i,g,f); //front bottom g
	Face five = Face(j,m,reverseEdge(g)); // bottom front g
	Face six = Face(reverseEdge(m),l,k); //bottom back g
	Face seven = Face(l,o,reverseEdge(p)); // back bottom g
	Face eight = Face(n,p,c); //Back top
	Face nine = Face(reverseEdge(d),n,reverseEdge(q)); // left top
	Face ten = Face(q,reverseEdge(j),h); //left bottom
	Face eleven = Face(reverseEdge(o),reverseEdge(r),b); // right top
	Face twelve = Face(r,k,f); // right bottom

	a.setJoinsFace(&two,&three);
	b.setJoinsFace(&two,&eleven);
	c.setJoinsFace(&one,&eight);
	d.setJoinsFace(&one,&nine);
	e.setJoinsFace(&one,&two);
	f.setJoinsFace(&four,&twelve);
	g.setJoinsFace(&four,&five);
	h.setJoinsFace(&three,&ten);
	i.setJoinsFace(&three,&four);
	j.setJoinsFace(&five,&ten);
	k.setJoinsFace(&six,&twelve);
	l.setJoinsFace(&six,&seven);
	m.setJoinsFace(&five,&six);
	n.setJoinsFace(&eight,&nine);
	o.setJoinsFace(&seven,&eleven);
	p.setJoinsFace(&seven,&eight);
	q.setJoinsFace(&nine,&ten);
	r.setJoinsFace(&eleven,&twelve);

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

	edgeArray[0] = a;
	edgeArray[1] = b;
	edgeArray[2] = c;
	edgeArray[3] = d;
	edgeArray[4] = e;
	edgeArray[5] = f;
	edgeArray[6] = g;
	edgeArray[7] = h;
	edgeArray[8] = i;
	edgeArray[9] = j;
	edgeArray[10] = k;
	edgeArray[11] = l;
	edgeArray[12] = m;
	edgeArray[13] = n;
	edgeArray[14] = o;
	edgeArray[15] = p;
	edgeArray[16] = q;
	edgeArray[17] = r;

	rotAng = 0.0f;

	//Looped!!

	for(int i=0; i<18; i++)
	{
		cout << "For face " <<i <<" the edge Midpoint is x: "<< edgeArray[i].getEdgeMidPoint().getX() << " y: " << edgeArray[i].getEdgeMidPoint().getY() << " z: " << edgeArray[1].getEdgeMidPoint().getZ() <<endl;
		float aq = (edgeArray[i].getVertexA().getX()+edgeArray[i].getVertexB().getX()+edgeArray[i].getFacesJoined1()->getCentroid().getX()+edgeArray[i].getFacesJoined2()->getCentroid().getX())/4.0f;
		float aw = (edgeArray[i].getVertexA().getY()+edgeArray[i].getVertexB().getY()+edgeArray[i].getFacesJoined1()->getCentroid().getY()+edgeArray[i].getFacesJoined2()->getCentroid().getY())/4.0f;
		float ae = (edgeArray[i].getVertexA().getZ()+edgeArray[i].getVertexB().getZ()+edgeArray[i].getFacesJoined1()->getCentroid().getZ()+edgeArray[i].getFacesJoined2()->getCentroid().getZ())/4.0f;
		Vertex edgeV = Vertex(aq,aw,ae);
		std::cout << i<<"'s Edge point is - X: " << edgeV.getX() << " Y: " << edgeV.getY() << " Z: " << edgeV.getZ() << std::endl;
	}

	//edgpoint

	float aq = (a.getVertexA().getX()+a.getVertexB().getX()+a.getFacesJoined1()->getCentroid().getX()+a.getFacesJoined2()->getCentroid().getX())/4.0f;
	float aw = (a.getVertexA().getY()+a.getVertexB().getY()+a.getFacesJoined1()->getCentroid().getY()+a.getFacesJoined2()->getCentroid().getY())/4.0f;
	float ae = (a.getVertexA().getZ()+a.getVertexB().getZ()+a.getFacesJoined1()->getCentroid().getZ()+a.getFacesJoined2()->getCentroid().getZ())/4.0f;
	Vertex edgeV = Vertex(aq,aw,ae);
	std::cout << "A's edge point is - X: " << edgeV.getX() << " Y: " << edgeV.getY() << " Z: " << edgeV.getZ() << std::endl;

	cout << "a Vertex A: " << a.getVertexA().getX() << ":" << a.getVertexA().getY() << ":" << a.getVertexA().getZ() << endl;
	cout << "a Vertex B: " << b.getVertexB().getX() << ":" << b.getVertexB().getY() << ":" << a.getVertexB().getZ() << endl;
	cout << "a face1 centroid: " << a.getFacesJoined1()->getCentroid().getX()<<" : "<<a.getFacesJoined1()->getCentroid().getY()<<" : "<<a.getFacesJoined1()->getCentroid().getZ()<<endl;
	cout << "a face2 centroid: " << a.getFacesJoined2()->getCentroid().getX()<<" : "<<a.getFacesJoined2()->getCentroid().getY()<<" : "<<a.getFacesJoined2()->getCentroid().getZ()<<endl;
	cout << "centroid 1 composed of" << a.getFacesJoined1()->getEdgeA().getVertexA().getX() << ":"<<a.getFacesJoined1()->getEdgeA().getVertexA().getY()<<":" << a.getFacesJoined1()->getEdgeA().getVertexA().getX()<<endl;
	cout << "\t\t "<< a.getFacesJoined1()->getEdgeA().getVertexB().getX() << ":"<< a.getFacesJoined1()->getEdgeA().getVertexB().getY() << ":" << a.getFacesJoined1()->getEdgeA().getVertexB().getZ() << endl;
	cout << "\t\t "<< a.getFacesJoined1()->getEdgeB().getVertexB().getX() <<":"<<a.getFacesJoined1()->getEdgeB().getVertexB().getY()<<":"<<a.getFacesJoined1()->getEdgeB().getVertexB().getZ()<<endl;
	cout <<""<<endl;
	cout << "centroid 2 composed of" << a.getFacesJoined2()->getEdgeA().getVertexA().getX() << ":"<<a.getFacesJoined2()->getEdgeA().getVertexA().getY()<<":" << a.getFacesJoined2()->getEdgeA().getVertexA().getX()<<endl;
	cout << "\t\t "<< a.getFacesJoined2()->getEdgeA().getVertexB().getX() << ":"<< a.getFacesJoined2()->getEdgeA().getVertexB().getY() << ":" << a.getFacesJoined2()->getEdgeA().getVertexB().getZ() << endl;
	cout << "\t\t "<< a.getFacesJoined2()->getEdgeB().getVertexB().getX() <<":"<<a.getFacesJoined2()->getEdgeB().getVertexB().getY()<<":"<<a.getFacesJoined2()->getEdgeB().getVertexB().getZ()<<endl;
	cout <<""<<endl;
	cout <<""<<endl;
	cout <<"some more centroids" <<endl;
	cout << "a face1 centroid: " << a.getFacesJoined1()->getCentroid().getX()<<" : "<<a.getFacesJoined1()->getCentroid().getY()<<" : "<<a.getFacesJoined1()->getCentroid().getZ()<<endl;
	cout << "a face1 centroid: " << a.getFacesJoined2()->getCentroid().getX()<<" : "<<a.getFacesJoined2()->getCentroid().getY()<<" : "<<a.getFacesJoined2()->getCentroid().getZ()<<endl;
	cout << "a face1 centroid: " << c.getFacesJoined1()->getCentroid().getX()<<" : "<<c.getFacesJoined1()->getCentroid().getY()<<" : "<<c.getFacesJoined1()->getCentroid().getZ()<<endl;
	cout << "a face1 centroid: " << d.getFacesJoined1()->getCentroid().getX()<<" : "<<d.getFacesJoined1()->getCentroid().getY()<<" : "<<d.getFacesJoined1()->getCentroid().getZ()<<endl;
	cout << "a face1 centroid: " << e.getFacesJoined1()->getCentroid().getX()<<" : "<<e.getFacesJoined1()->getCentroid().getY()<<" : "<<e.getFacesJoined1()->getCentroid().getZ()<<endl;

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
		glRotatef(rotAng,0.0f,0.5f,1.0);

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
