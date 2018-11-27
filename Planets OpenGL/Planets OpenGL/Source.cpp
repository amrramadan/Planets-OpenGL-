#include "windows.h"
#include <iostream>
#include <glut.h>
#include <glext.h>
#include "imageloader.h"
#include <glu.h>
#define pi 3.14

GLfloat xRotated, yRotated, zRotated, sRotated;
GLdouble earth = 6.5;
GLdouble mars = 5;
GLdouble jup = 9;
GLdouble sat = 7.5;
GLdouble Sun = 11.5;

float x = 0;
float y = 0;
float earth_orbit = 30;
float mars_orbit = 50;
float jup_orbit = 65;
float sat_orbit = 90;
float sat_ring = 17;
float sat_ring2 = 15;
float sat_ring3 = 14;
float sat_ring4 = 13.5;

void Init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(1);
	glLineWidth(1);
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//.............................//Blue
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBegin(GL_POINTS);
	glColor3f(1.0, 1.0, 1.0);
	for (float i = 0; i < 2 * pi; i += pi / 360)
	{
		glVertex2f(x + sin(i)*earth_orbit, y + cos(i)*earth_orbit);
	}
	glEnd();
	// Red color used to draw.
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	// rotation about Y axis
	glRotatef(yRotated, 0.0, 0.0, 1.0);
	glTranslatef(30, 0.0, 0.0);
	// changing in transformation matrix.
	glRotatef(yRotated, 1.0, 1.0, 1.0);
	glutSolidSphere(earth, 20, 20);
	glPopMatrix();


	//.............................//white
	glMatrixMode(GL_MODELVIEW);

	glBegin(GL_POINTS);
	glColor3f(1.0, 1.0, 1.0);
	for (float i = 0; i < 2 * pi; i += pi / 360)
	{
		glVertex2f(x + sin(i)* jup_orbit, y + cos(i)*jup_orbit);
	}
	glEnd();
	// clear the identity matrix.
	glLoadIdentity();
	glPushMatrix();
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	glTranslatef(65, 0.0, 0.0);
	glRotatef(zRotated, 0.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(jup, 20, 20);
	glPopMatrix();


	//.............................//Red
	glMatrixMode(GL_MODELVIEW);

	glBegin(GL_POINTS);
	glColor3f(1.0, 1.0, 1.0);
	for (float i = 0; i < 2 * pi; i += pi / 360)
	{
		glVertex2f(x + sin(i)* mars_orbit, y + cos(i)*mars_orbit);
	}
	glEnd();
	// clear the identity matrix.
	glLoadIdentity();
	// traslate the draw by z = -4.0
	glPushMatrix();
	glRotatef(xRotated, 0.0, 0.0, 1.0);
	glTranslatef(50, 0.0, 0);
	glRotatef(xRotated, 1.0, 1.0, 1.0);
	// Red color used to draw.
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(mars, 20, 20);
	glPopMatrix();


	//.............................//Brown
	glMatrixMode(GL_MODELVIEW);

	glBegin(GL_POINTS);
	glColor3f(1.0, 1.0, 1.0);
	for (float i = 0; i < 2 * pi; i += pi / 360)
	{
		glVertex2f(x + sin(i)* sat_orbit, y + cos(i)*sat_orbit);
	}
	glEnd();
	// clear the identity matrix.
	glLoadIdentity();
	glPushMatrix();
	glRotatef(sRotated, 0.0, 0.0, 1.0);
	glTranslatef(90, 0.0, 0.0);
	glRotatef(sRotated, 0.0, 1.0, 0.0);
	glColor3f(0.5f, 0.35f, 0.05f);
	glutSolidSphere(sat, 20, 20);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.5f, 0.0f);
	for (float i = 0; i < 2 * pi; i += pi / 360)
	{
		glVertex2f(x + sin(i)*sat_ring, y + cos(i)*sat_ring);
	}
	for (float i = 0; i < 2 * pi; i += pi / 360)
	{
		glVertex2f(x + sin(i)*sat_ring2, y + cos(i)*sat_ring2);
	}
	for (float i = 0; i < 2 * pi; i += pi / 360)
	{
		glVertex2f(x + sin(i)*sat_ring3, y + cos(i)*sat_ring3);
	}
	for (float i = 0; i < 2 * pi; i += pi / 360)
	{
		glVertex2f(x + sin(i)*sat_ring4, y + cos(i)*sat_ring4);
	}
	glEnd();
	glPopMatrix();


	//.............................//Sun
	glMatrixMode(GL_MODELVIEW);
	// clear the identity matrix.
	glLoadIdentity();
	// Red color used to draw.
	glColor3f(1.0, 1.0, 0.0);
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	glRotatef(yRotated, 0.0, 1.0, 0.0);

	glutSolidSphere(Sun, 20, 20);


	// Flush buffers to screen
	glFlush();
}




void reshapeFunc(int x, int y)
{
	if (y == 0 || x == 0) return;  //Nothing is visible then, so return
								   //Set a new projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Angle of view:40 degrees
	//Near clipping plane distance: 0.5
	//Far clipping plane distance: 20.0
	glOrtho(-100, 100, -100, 100, -100, 100);
	glRotatef(75, 1, 0, 0);
	//gluPerspective(50.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);  //Use the whole window for rendering
}

void idleFunc(void)
{

	xRotated += 0.03;
	yRotated += 0.08;
	zRotated += 0.05;
	sRotated += 0.066;

	Display();
}




//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);
	//double buffering used to avoid flickering problem in animation
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// window size
	glutInitWindowSize(900, 900);
	glutInitWindowPosition(100, 50);
	// create the window 
	glutCreateWindow("Planets by: Omar-Amr-Hazem");
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//Assign  the function used in events
	glutReshapeFunc(reshapeFunc);
	glutIdleFunc(idleFunc);
	glutDisplayFunc(Display);
	Init();
	//Let start glut loop
	glutMainLoop();

	return 0;
}
