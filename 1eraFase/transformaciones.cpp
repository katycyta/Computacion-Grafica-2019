  

 #include<GL/glut.h>  
 #include<cmath>  
   
 double angle=120;
   
 typedef struct {  
      float x;  
      float y;  
 }Point2D;  
   
 Point2D p1,p2,p3;  
   
 void drawLineSegment(Point2D p1,Point2D p2,Point2D p3)  
 {  
      glPointSize(1.0);  
      glBegin(GL_LINES);  
           glVertex2i(p1.x,p1.y);  
           glVertex2i(p2.x,p2.y);  
           glVertex2i(p2.x,p2.y);  
           glVertex2i(p3.x,p3.y);  
      glEnd();  
      glFlush();  
 }  
   
 void drawPolygonSegment(Point2D p1,Point2D p2,Point2D p3)  
 {  
      glPointSize(1.0);  
      glBegin(GL_LINES);  
           glVertex2i(p1.x,p1.y);  
           glVertex2i(p2.x,p2.y);  
           glVertex2i(p2.x,p2.y);  
           glVertex2i(p3.x,p3.y);  
           glVertex2i(p3.x,p3.y);  
           glVertex2i(p1.x,p1.y);  
      glEnd();  
      glFlush();  
 }  
 Point2D translate(Point2D p,float tx,float ty)  
 {  
      p.x=p.x+tx;  
      p.y=p.y+ty;  
      return p;  
 }  
   
 Point2D  rotate(Point2D p,float ang){
    ang = ang * 3.14 / 180.0;                                 //angle in radians
    Point2D ptemp;

    ptemp.x = p.x * cos(ang) - p.y * sin(ang);
    ptemp.y = p.x * sin(ang) + p.y * cos(ang);  

    return ptemp;
}
   
 Point2D ref_4(Point2D p)  
 {  
      p.x=-p.x;  
      p.y=p.y;  
   
      return p;  
 }  
   
 Point2D Scale(Point2D p,float sx,float sy)  
 {  
      p.x=p.x*sx;  
      p.y=p.y*sy;  
   
      return p;  
 }  
   
 void mouse(int button,int state,int x,int y){   
    if(state == GLUT_DOWN) {   
     if(button == GLUT_LEFT_BUTTON) {   
                
                    p1.x=400;   
                    p1.y=200;   
                    p2.x=400;   
                    p2.y=200;   
                    p3.x=200;   
                    p3.y=400;   
                       
       }   
    }   
  }   
     
 void trans()
{
					    drawLineSegment(translate(p1,500,500),translate(p2,500,500),translate(p3,500,500));
	Point2D scale1_p1=translate(Scale(p1,0.75,0.75),0,200);
	Point2D scale1_p2=translate(Scale(p2,0.75,0.75),0,200);
	Point2D scale1_p3=translate(Scale(p3,0.75,0.75),0,200);
	drawLineSegment(translate(scale1_p1,500,500),translate(scale1_p2,500,500),translate(scale1_p3,500,500));

	Point2D scale2_p1=translate(Scale(p1,0.5,0.5),0,350);
	Point2D scale2_p2=translate(Scale(p2,0.5,0.5),0,350);
	Point2D scale2_p3=translate(Scale(p3,0.5,0.5),0,350);
	drawLineSegment(translate(scale2_p1,500,500),translate(scale2_p2,500,500),translate(scale2_p3,500,500));

	Point2D ref_p1=ref_4(p1);
	Point2D ref_p2=ref_4(p2);
	Point2D ref_p3=ref_4(p3);
	drawLineSegment(translate(ref_p1,500,500),translate(ref_p2,500,500),translate(ref_p3,500,500));

	Point2D refscale1_p1=ref_4(scale1_p1);
	Point2D refscale1_p2=ref_4(scale1_p2);
	Point2D refscale1_p3=ref_4(scale1_p3);
	drawLineSegment(translate(refscale1_p1,500,500),translate(refscale1_p2,500,500),translate(refscale1_p3,500,500));

	Point2D refscale2_p1=ref_4(scale2_p1);
	Point2D refscale2_p2=ref_4(scale2_p2);
	Point2D refscale2_p3=ref_4(scale2_p3);
	drawLineSegment(translate(refscale2_p1,500,500),translate(refscale2_p2,500,500),translate(refscale2_p3,500,500));

	int i=1;
	while(i<=2){

		Point2D rotate_p1=rotate(p1,angle*i);
		Point2D rotate_p2=rotate(p2,angle*i);
		Point2D rotate_p3=rotate(ref_p2,angle*i);
		drawPolygonSegment(translate(rotate_p1,500,500),translate(rotate_p2,500,500),translate(rotate_p3,500,500));

		Point2D rotateScale1_p1=rotate(scale1_p1,angle*i);
		Point2D rotateScale1_p2=rotate(scale1_p2,angle*i);
		Point2D rotateScale1_p3=rotate(refscale1_p2,angle*i);
		drawPolygonSegment(translate(rotateScale1_p1,500,500),translate(rotateScale1_p2,500,500),translate(rotateScale1_p3,500,500));

		Point2D rotateScale2_p1=rotate(scale2_p1,angle*i);
		Point2D rotateScale2_p2=rotate(scale2_p2,angle*i);
		Point2D rotateScale2_p3=rotate(refscale2_p2,angle*i);
		drawPolygonSegment(translate(rotateScale2_p1,500,500),translate(rotateScale2_p2,500,500),translate(rotateScale2_p3,500,500));
		i++;
	}
}
 void key(unsigned char key,int x,int y)  
 {  
      if(key=='k')glutIdleFunc(trans); 
      angle=angle+4;  
      p1.x=p1.x+4;  
      p2.x=p2.x+4;  
      p3.x=p3.x+4;  
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
     glutMouseFunc( mouse );   
     glutKeyboardFunc(key);   
    glutMainLoop();   
    return( 0 );   
  } 
