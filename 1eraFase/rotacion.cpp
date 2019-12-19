//Prespinar la tecla r y rotara el poligono

	#include <GL/gl.h>
	#include <GL/glut.h> 
	 #include <cmath>  
	 int screenheight = 600;  
	 int screenwidth = 800;  
	 bool flag = true;  
	 int first = 0;  
	 double angle = 30;   
	 //The angle for the rotation (in degrees)  
	 typedef struct{  
	   float x;  
	   float y;  
	 }Point2D;  
	 Point2D p1,p2,p3,p4;  
	 void DrawPolygonSegment(Point2D pt1, Point2D pt2, Point2D pt3, Point2D pt4){  
		  glClear(GL_COLOR_BUFFER_BIT);       
		 glPointSize(1.0);  
		    glBegin(GL_POLYGON);  
		         glVertex2i(pt1.x, pt1.y);  
		         glVertex2i(pt2.x, pt2.y);  
		         glVertex2i(pt3.x, pt3.y);  
		         glVertex2i(pt4.x, pt4.y);  
		 glEnd();  
		 glPointSize(6.0);  
		 glBegin(GL_POINTS);  
		    glVertex2i(pt1.x, pt1.y);  
		 glVertex2i(pt2.x, pt2.y);  
		    glVertex2i(pt3.x, pt3.y);  
		    glVertex2i(pt4.x, pt4.y);  
		 glEnd();  
		 glFlush();  
	 }  
	 Point2D translate(Point2D p, float tx, float ty){  
		 p.x =p.x; //.....wite the equations for translation   
		 p.y = p.y; //.....wite the equations for translation  
		 return p;  
	 }  
	 Point2D rotate(Point2D p,Point2D c,float ang){  
	   ang = ang * 3.14 / 180.0;                 //angle in radians  
	   Point2D ptemp;  
	   ptemp.x = p.x * cos(ang) - p.y * sin(ang)+(c.x- cos(ang)*c.x +sin(ang)*c.y);  
	   ptemp.y = p.x * sin(ang) + p.y * cos(ang)+(c.y- sin(ang)*c.x-cos(ang)*c.y);  
		  return ptemp;  
	 }  
	 void myMouse()  
	 {  
		  glClear(GL_COLOR_BUFFER_BIT);  
		                           p1.x = 200;  
		                           p1.y =200;  
		                           p2.x = 400;  
		                           p2.y = 200;  
		                           p3.x = 400;  
		                           p3.y =400;  
		                           p4.x=200;  
		                           p4.y=400;  
		                           DrawPolygonSegment(p1,p2,p3,p4);  
	 }  
	 void translatepolygon_R()  
	 {  
		  Point2D c;  
		  c.x=(p1.x+p2.x)/2;  
		  c.y=(p1.y+p4.y)/2;  
		  Point2D Rotated_p1 = rotate(p1,c,angle);  
	   Point2D Rotated_p2 = rotate(p2,c,angle);  
		  Point2D Rotated_p3 = rotate(p3,c,angle);  
		  Point2D Rotated_p4 = rotate(p4,c,angle);  
	   DrawPolygonSegment(Rotated_p1,Rotated_p2,Rotated_p3,Rotated_p4);  
	 }  
	 void key(unsigned char key, int x, int y)  
	 {  
		  if(key=='r') glutIdleFunc(translatepolygon_R);  
		  angle=angle+4;  
		  p1.x=p1.x+4;  
		  p2.x=p2.x+4;  
		  p3.x=p3.x+4;  
		  p4.x=p4.x+4;  
	 }  
	 void myDisplay(){  
		 glClearColor(1.0f, 1.0f, 1.0f, 0.0f);  
		 glClear(GL_COLOR_BUFFER_BIT);  
		 glColor3f(0.0f, 0.0f, 0.0f);  
	 }  
	 int main( int argc, char ** argv ) {  
		 glutInit( &argc, argv );  
		 glutInitWindowPosition( 0, 0 );  
		 glutInitWindowSize( 800, 600 );  
		 glutCreateWindow( "My Drawing Screen" );  
		    glMatrixMode( GL_PROJECTION );  
		 glLoadIdentity();  
		 gluOrtho2D( 0, 800, 0, 600 );  
		 glViewport(0, 0, 800, 600);  
		    glutDisplayFunc( myDisplay );  
		 glutDisplayFunc( myMouse );  
		    glutKeyboardFunc(key);  
		 glutMainLoop();  
		 return( 0 );  
	 }  
