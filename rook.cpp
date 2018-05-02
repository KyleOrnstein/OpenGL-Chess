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
//rook top
double eqn0[4] = { -1, 0, 0, .85 };
double eqn1[4] = { 1, 0, 0, 0.85 };
double eqn2[4] = {0, 0, 1, 0.85};
double eqn3[4] = {0, 0, -1, 0.85};



void animate(int someValue) {
    glutTimerFunc(animationPeriod, animate, 1);
}

void drawRook(void) {
    glColor3f(0, 0, 0);
    
    //bottom up
    glPushMatrix();//1
    glRotatef(zrotate, 0.0, 0.0, 1.0);
    glRotatef(yrotate, 0.0, 1.0, 0.0);
    glRotatef(xrotate, 1.0, 0.0, 0.0);
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
    glTranslatef(0, -1.9, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .75, 1, .3, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -1.8, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .75, .75, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -1.7, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .7, .7, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -.2, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .6, .65, 1.5, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -0.15, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .65, .6, .05, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -0.05, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .8, .65, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glScalef(1, .2, 1);
    gluSphere(qobj, .9, 40, 40);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0.05, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .85, .9, .05, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0.1, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .9, .85, .05, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0.4, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .9, .9, .3, 20, 20);
    glPopMatrix();
    
    glClipPlane(GL_CLIP_PLANE0, eqn0);//right side
    glEnable(GL_CLIP_PLANE0);
    glClipPlane(GL_CLIP_PLANE1, eqn1);//right side
    glEnable(GL_CLIP_PLANE1);
    glClipPlane(GL_CLIP_PLANE2, eqn2);//right side
    glEnable(GL_CLIP_PLANE2);
    glClipPlane(GL_CLIP_PLANE3, eqn3);//right side
    glEnable(GL_CLIP_PLANE3);
    glPushMatrix();
    glTranslatef(0, 0.6, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .9, .9, .2, 20, 20);
    glDisable(GL_CLIP_PLANE0);
    glDisable(GL_CLIP_PLANE1);
    glDisable(GL_CLIP_PLANE2);
    glDisable(GL_CLIP_PLANE3);
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
    drawRook();
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
