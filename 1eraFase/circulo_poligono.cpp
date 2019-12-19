
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

void circulo()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glLoadIdentity();

	double radio = 0.8;
	int lados = 20;

	glBegin(GL_LINES);
	for(int i=0; i < lados; i++)
	{
		glVertex2f(cos(i*2*M_PI/lados)*radio, sin(i*2*M_PI/lados)*radio);
		glVertex2f(cos((i+1) * 2*M_PI/lados)*radio, sin((i+1) * 2*M_PI/lados)*radio);
	}
	glEnd();
	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400,300);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Hello World");
	glClearColor(0,0,0,0);
	glutDisplayFunc(circulo);
	glutMainLoop();
	return 0;
}
