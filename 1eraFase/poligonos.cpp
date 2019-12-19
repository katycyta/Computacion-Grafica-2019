#include <iostream>
#include <GL/glut.h>
#include <cmath>
using namespace std;

#define ancho 600
#define largo 600

int sides;
GLfloat radio;
GLfloat angulo;

double X1, Y1, X2, Y2;

float redondeo(float v)
{
  return floor(v + 0.5);
}

void dibujar_linea( double X_1,double Y_1, double X_2,double Y_2)
{
  double dx=(X_2-X_1);
  double dy=(Y_2-Y_1);
  double incremento;
  float xInc,yInc,x=X_1,y=Y_1;
  incremento=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
  xInc=dx/(float)incremento;
  yInc=dy/(float)incremento;

 
  glVertex3f(x,y,0.0);
  
  for(int k=0;k<incremento;k++)
  {
    x+=xInc;
    y+=yInc;
    glVertex3f(redondeo(x), redondeo(y),0.0);
  }

}

void reshape(int width, int height)
{
 	glViewport(0, 0, width, height);
 	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
 	glOrtho(-1, 1, -1, 1, -1, 1);
 	glMatrixMode(GL_MODELVIEW);
}

void display()
{
 	glClear(GL_COLOR_BUFFER_BIT);
 	glColor3f(0,255,1);
 	glLoadIdentity();

  double ar = glutGet(GLUT_WINDOW_WIDTH) / (double)glutGet( GLUT_WINDOW_HEIGHT );
  glOrtho( -200 * ar, 200 * ar, -200, 200, -1, 1);

  radio=(GLfloat)largo/3.0;
  cout<<"radio:"<<radio<<endl;

  

  glBegin(GL_LINES);


  GLfloat pox=(GLfloat)radio*cos(0);
  GLfloat poy=(GLfloat)radio*sin(0);
  cout<<"pox"<<pox<<endl;
  cout<<"poy"<<poy<<endl;
  GLfloat x,y;

  
  //glVertex3f(pox, poy, 0.0f);
  for(int i=1;i<=sides;i++)
  {
     x=(GLfloat)radio*cos(i*angulo);
     y=(GLfloat)radio*sin(i*angulo);
    cout<<"x"<<x<<endl;
    cout<<"y"<<y<<endl;
    dibujar_linea(pox,poy,x,y);
    //glVertex3f(pox,poy,0.0);
    //glVertex3f(x,y,0.0);
    pox=x;
    poy=y;
  }
 	//glVertex3f(0.0f, 0.0f, 0.0f);
	//glVertex3f(10.0f, 10.0f, 0.0f);
 	/*glVertex3f(-1,-1,0);
 	glVertex3f(1,-1,0);
 	glVertex3f(0,1,0);*/
 	glEnd();
 	glFlush();
 }

void init()
{
 	glClearColor(0,0,0,0);
}
int main(int argc, char **argv)
{
  //obtengo los lados
  cout<<"insertar nro lados:\n";
  cin>>sides;
  angulo = (GLfloat)360/sides*3.14159f/180.0f; // grados a radianes
  //angulo = (GLfloat)360.0f/sides; // grados a radianes
  cout<<"angulo"<<angulo<<endl;
  //angulo = (GLfloat)i*3.14159f/180.0f; // grados a radianes
  //angulo=360.0/sides;
 	glutInit(&argc, argv);
 	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);

 	glutInitWindowSize(ancho, largo);
 	glutCreateWindow("Drawing with OpenGL");
 	init();
 	//glutDisplayFunc();

 	glutDisplayFunc(display);
 	glutReshapeFunc(reshape);
 	glutMainLoop();
 	return 0;
}
