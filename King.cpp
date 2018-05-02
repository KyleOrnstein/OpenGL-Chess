
/////////////////////////////////////////////////////////////////////
// Name: Kyle Ornstein
// Email: kjornste@syr.edu
// Assignment: Assignment 4
// Compiler: Visual Studio 2017
// Date: 3/19/18
// References:
/* Interactions:*/
/////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <functional>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define PI 3.14159265

using namespace std;

static GLsizei width, height;
static GLUquadricObj *qobj;
static int animationPeriod = 50;
static double xrotate = 0;
static double yrotate = 0;
static double zrotate = 0;

void animate(int someValue) {
    glutTimerFunc(animationPeriod, animate, 1);
}

void drawKing(double x, double y, double z, int c) {
    if(c == 1 )
        glColor3f(0.961, 0.961, 0.961);
    else if(c == 2)
        glColor3f(0, 0, 0);
    else if (c == 3)
        glColor3f(1.000, 0.973, 0.863);
    else if (c == 4)
        glColor3f(0.804, 0.522, 0.247);
    
    //bottom up
    glPushMatrix();//1
    glTranslatef(x, y, z);
    glRotatef(90, 1, 0, 0);
    glPushMatrix();//2
    
    glPushMatrix();
    glTranslatef(0, -2.35, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, 1.1, 1.1, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2.25, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .9, 1.1, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2.2, 0);
    glScalef(1, .2, 1);
    gluSphere(qobj, 1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .75, 1, .2, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -1.9, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .7, .75, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -1.9, 0);
    glScalef(1, .1, 1);
    gluSphere(qobj, .7, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .4, .6, 2, 40, 40);
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .5, .4, 1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, .1, 0);
    glScalef(1, .2, 1);
    gluSphere(qobj, 1, 40, 40);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, .3, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .7, .8, .2, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, .4, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .6, .6, .3, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, .45, 0);
    glScalef(1, .1, 1);
    gluSphere(qobj, .7, 40, 40);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 1.1, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .6, .4, .6, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 1.3, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .2, .6, .2, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 1.33, 0);
    glScalef(1, .2, 1);
    gluSphere(qobj, .2, 40, 40);
    glPopMatrix();
    
    //cross
    glPushMatrix();//vertical
    glTranslatef(0, 1.62, 0);
    glScalef(.3, 1, .3);
    glutSolidCube(.5);
    glPopMatrix();
    
    glPushMatrix();//horizontal
    glTranslatef(0, 1.62, 0);
    glScalef(1, .3, .3);
    glutSolidCube(.5);
    glPopMatrix();
    
    glPopMatrix();//2
    glPopMatrix();//1
}

void drawScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glLoadIdentity();
    
    // Position the objects for viewing.
    gluLookAt(0.0, 0.0, 7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    //gluQuadricDrawStyle(qobj, GLU_LINE);
    drawKing(0, 0, 0, 1);
    glutSwapBuffers();
}

void setup(void)
{
    glClearColor(1, 1, 1, 0.0);
    glEnable(GL_DEPTH_TEST);
    qobj = gluNewQuadric();
}

void resize(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w / (float)h, 1.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
            exit(0);
        case 27:
            break;
        case 'x':
            xrotate += 5.0;
            if (xrotate > 360.0) xrotate -= 360.0;
            glutPostRedisplay();
            break;
        case 'X':
            xrotate -= 5.0;
            if (xrotate < 0.0) xrotate += 360.0;
            glutPostRedisplay();
            break;
        case 'y':
            yrotate += 5.0;
            if (yrotate > 360.0) yrotate -= 360.0;
            glutPostRedisplay();
            break;
        case 'Y':
            yrotate -= 5.0;
            if (yrotate < 0.0) yrotate += 360.0;
            glutPostRedisplay();
            break;
        case 'z':
            zrotate += 5.0;
            if (zrotate > 360.0) zrotate -= 360.0;
            glutPostRedisplay();
            break;
        case 'Z':
            zrotate -= 5.0;
            if (zrotate < 0.0) zrotate += 360.0;
            glutPostRedisplay();
        default:
            break;
    }
}

void specialKeyInput(int key, int x, int y) {
}

void mousePicking(int button, int state, int x, int y) {
    
}

void mouseMotion(int x, int y) {
    
}

void printInteraction(void)
{
}

int main(int argc, char **argv)
{
    printInteraction();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(1000, 50);
    glutCreateWindow("Kyle's drawscene");
    setup();
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    glutSpecialFunc(specialKeyInput);
    glutMouseFunc(mousePicking);
    glutMotionFunc(mouseMotion);
    
    glutTimerFunc(5, animate, 1);
    glutMainLoop();
    return 0;
}
