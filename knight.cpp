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

void fillKnight(void ){
    double t, y;
    double a = -1.5, b = 1.5, c = -.65, d = .65;

    glPushMatrix();
    glRotatef(-20, 0, 0, 1);
    glBegin(GL_TRIANGLE_STRIP);//back curve to base
    for(double x = 0; x < 100; x = x + 1){
        a = -1.45, b = 1.5, c = -.65, d = .65;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 1.0);
        glVertex3f(1.5, -1.05, 1);
    }
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(-20, 0, 0, 1);
    glBegin(GL_TRIANGLE_STRIP);//back curve to base
    for(double x = 0; x < 100; x = x + 1){
        a = -1.45, b = 1.5, c = -.65, d = .65;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 0.0);
        glVertex3f(1.5, -1.05, 0);
    }
    glEnd();
    glPopMatrix();

    glBegin(GL_TRIANGLE_STRIP);//nose
    glVertex3f(1.85, .3, 0);
    glVertex3f(1.5, -0.2, 0);
    
    glVertex3f(1.85, .3, 1);
    glVertex3f(1.5, -0.2, 1);
    
    glVertex3f(1.85, -0.2, 0);
    glVertex3f(1.85, -0.2, 0);
    
    glVertex3f(1.85, -0.2, 1);
    glVertex3f(1.85, -0.2, 1);
    glEnd();
    
    glPushMatrix();
    glTranslatef(1.08, .5, 0);
    glRotatef(45, 0, 0, 1);
    glBegin(GL_TRIANGLE_STRIP);//top curve to nose
    for(double x = 0; x < 50; x = x + 1){
        a = -.7, b = .7, c = -.65, d = .65;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 1);
        glVertex3f(-.2, -.8, 1);
    }
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.08, .5, 0);
    glRotatef(45, 0, 0, 1);
    glBegin(GL_TRIANGLE_STRIP);//top curve to nose
    for(double x = 0; x < 50; x = x + 1){
        a = -.7, b = .7, c = -.65, d = .65;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 0);
        glVertex3f(-.2, -.8, 0);
    }
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.35, -.85, 0);
    glBegin(GL_TRIANGLE_STRIP);//bottom right curve to base
    for(double x = 0; x < 100; x = x + 1)
    {
        a = -.67, b = .67, c = -.4, d = .4;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 1);
        glVertex3f(-1.45, -0.65, 1);
    }
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.35, -.85, 0);
    glBegin(GL_TRIANGLE_STRIP);//bottom right curve to base
    for(double x = 0; x < 100; x = x + 1)
    {
        a = -.67, b = .67, c = -.4, d = .4;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 0);
        glVertex3f(-1.45, -0.65, 0);
    }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glRotatef(-20, 0, 0, 1);
    glBegin(GL_TRIANGLE_STRIP);//back to nose
    for(double x = 0; x < 93; x = x + 1){
        a = -1.45, b = 1.5, c = -.65, d = .65;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 1.0);
        glVertex3f(1.5, .33, 1);
    }
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(-20, 0, 0, 1);
    glBegin(GL_TRIANGLE_STRIP);//back to nose
    for(double x = 0; x < 93; x = x + 1){
        a = -1.45, b = 1.5, c = -.65, d = .65;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 0.0);
        glVertex3f(1.5, .33, 0);
    }
    glEnd();
    glPopMatrix();
}
void drawTopKnight(void){
    glColor3f(0, 0, 0);
    double t, y;
    double a = -1.45, b = 1.5, c = -.65, d = .65;
    
    glPushMatrix();
    glRotatef(-20, 0, 0, 1);
    glBegin(GL_TRIANGLE_STRIP);//back curve
    for(double x = 0; x < 100; x = x + 1)
    {
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 0.0);
        glVertex3f(y*y, t, 1);
    }
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.08, .5, 0);
    glRotatef(45, 0, 0, 1);
    glBegin(GL_TRIANGLE_STRIP);//top curve
    for(double x = 0; x < 100; x = x + 1)
    {
        a = -.7, b = .7, c = -.65, d = .65;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 0.0);
        glVertex3f(y*y, t, 1);
    }
    glEnd();
    glPopMatrix();
    
    glBegin(GL_TRIANGLE_STRIP);//nose
    glVertex3f(1.85, .3, 0);
    glVertex3f(1.85, .3, 1);
    
    glVertex3f(1.85, -0.2, 0);
    glVertex3f(1.85, -0.2, 1);
    
    glVertex3f(1.85, -0.2, 0);
    glVertex3f(1.85, -0.2, 1);
    
    glVertex3f(1.5, -0.2, 0);
    glVertex3f(1.5, -0.2, 1);
    glEnd();
    
    glPushMatrix();
    glTranslatef(1.35, -.85, 0);
    glBegin(GL_TRIANGLE_STRIP);//bottom right curve
    for(double x = 0; x < 100; x = x + 1)
    {
        a = -.67, b = .67, c = -.4, d = .4;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 0.0);
        glVertex3f(y*y, t, 1);
    }
    glEnd();
    glPopMatrix();
    
    glBegin(GL_TRIANGLE_STRIP);//base
    glVertex3f(1.5, -1.5, 0);
    glVertex3f(1.5, -1.5, 1);
    
    glVertex3f(-.1, -1.5, 0);
    glVertex3f(-.1, -1.5, 1);
    glEnd();
    
}

void drawKnight(void) {
    glColor3f(0, 0, 0);
    
    //bottom up
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
    glTranslatef(-.6, -.65, -.35);
    glScalef(.85, .9, .7);
    fillKnight();
    drawTopKnight();
    glPopMatrix();
}

void drawScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glLoadIdentity();
    
    // Position the objects for viewing.
    gluLookAt(0.0, 0.0, 7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glColor3f(0, 0, 0);
    glPushMatrix();//1
    glRotatef(zrotate, 0.0, 0.0, 1.0);
    glRotatef(yrotate, 0.0, 1.0, 0.0);
    glRotatef(xrotate, 1.0, 0.0, 0.0);
    glPushMatrix();//2
    drawKnight();
    glPopMatrix();
    glPopMatrix();
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
