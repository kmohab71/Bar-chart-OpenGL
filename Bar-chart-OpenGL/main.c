//
//  main.c
//  Bar-chart-OpenGL
//
//  Created by Khaled Mohab on 6/8/20.
//  Copyright © 2020 Khaled Mohab. All rights reserved.
//

#include <GLUT/glut.h>
#include <stdlib.h>      // LIBRARIES
#include <stdio.h>
#include <math.h>
typedef struct middle
{
    float x;
    float y;
}middle;
middle mid;
int angle = 5;
int rotate = 0;
void init()
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode (GL_PROJECTION);        //Viewport
    gluOrtho2D( 0.0,680,0.0,400.0);    //Viewport, i.e., camera position.

}

void display()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glFlush ();
}
void drawLetter()
{
    glLineWidth(3);
    glBegin( GL_LINES );
    glColor3f( 0., 0., 1. );
    glVertex2f( mid.x, mid.y);
    glVertex2f( mid.x, mid.y+300.);
    glEnd();
    
    glBegin( GL_LINES );
    glColor3f( 0., 0., 1. );
    glVertex2f( mid.x, mid.y);
    glVertex2f( mid.x+500.,mid.y);
    glEnd();
    
    for(int i = mid.x; i<=(mid.x+500); i+=100)
    {
        glBegin( GL_LINES );
        glColor3f( 1., 0., 0. );
        glVertex2f( i, mid.y+10);
        glVertex2f( i, mid.y-10);
        glEnd();
    }
    
    for(int i = mid.y; i<=(mid.y+300); i+=30)
    {
        glBegin( GL_LINES );
        glColor3f( 1., 0., 0. );
        glVertex2f( mid.x+10, i);
        glVertex2f( mid.x-10, i);
        glEnd();
    }

    glBegin(GL_POLYGON);
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex2f(  mid.x+(1*100-20), mid.y );
    glVertex2f(  mid.x+(1*100-20), mid.y+(30*3) );
    glVertex2f(  mid.x+(1*100+20), mid.y+(30*3) );
    glVertex2f(  mid.x+(1*100+20), mid.y );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex2f(  mid.x+(2*100-20), mid.y );
    glVertex2f(  mid.x+(2*100-20), mid.y+(30*3) );
    glVertex2f(  mid.x+(2*100+20), mid.y+(30*3) );
    glVertex2f(  mid.x+(2*100+20), mid.y );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex2f(  mid.x+(3*100-20), mid.y );
    glVertex2f(  mid.x+(3*100-20), mid.y+(30*8) );
    glVertex2f(  mid.x+(3*100+20), mid.y+(30*8) );
    glVertex2f(  mid.x+(3*100+20), mid.y );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex2f(  mid.x+(4*100-20), mid.y );
    glVertex2f(  mid.x+(4*100-20), mid.y+(30*1) );
    glVertex2f(  mid.x+(4*100+20), mid.y+(30*1) );
    glVertex2f(  mid.x+(4*100+20), mid.y );
    glEnd();

    glFlush ();
}
void Reshapefunc()
{
    glTranslatef(mid.x, mid.y, 1);
    glPushMatrix();
    glTranslatef(-mid.x, -mid.y, -1);
    glFlush ();
}

void Idlefunc()
{
    drawLetter();
}
int main(int argc, char** argv)
{
    mid.x=10;
    mid.y=10;
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 300);
    glutInitWindowPosition (100, 100);
    glutCreateWindow("Bar chart");
    
    glutDisplayFunc(display);
    glutReshapeFunc(Reshapefunc);
    glutIdleFunc(Idlefunc);
    init ();
    glutMainLoop();
    return 0;
}

