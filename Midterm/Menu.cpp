#include <iostream>
#include ".\GL\freeglut.h"
#include "ObjLoader.h"
#include "Menu.h"

ObjLoader gourd = ObjLoader("./OBJs4/gourd.obj");
ObjLoader octahedron = ObjLoader("./OBJs4/octahedron.obj");
ObjLoader teapot = ObjLoader("./OBJs4/teapot.obj");
ObjLoader teddy = ObjLoader("./OBJs4/teddy.obj");
ObjLoader testobj = ObjLoader("");
unsigned char fileflag = 1;
unsigned char drawflag = 3;
bool colorflag = 0;

void creatmenu()
{
    int filemenu = glutCreateMenu(fileMenu);
    glutAddMenuEntry("gourd", 1);
    glutAddMenuEntry("octahedron", 2);
    glutAddMenuEntry("teapot", 3);
    glutAddMenuEntry("teddy", 4);
    glutAddMenuEntry("enter filename", 5);
    int colormenu = glutCreateMenu(colorMenu);
    glutAddMenuEntry("Single", 1);
    glutAddMenuEntry("Random", 2);
    int rendermenu = glutCreateMenu(renderMenu);
    glutAddMenuEntry("Point", 1);
    glutAddMenuEntry("Line", 2);
    glutAddMenuEntry("Face", 3);
    int menu = glutCreateMenu(mainMenu);
    glutAddSubMenu("File", filemenu);
    glutAddSubMenu("Color", colormenu);
    glutAddSubMenu("Render", rendermenu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void mainMenu(int index)
{
    switch (index)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    }
}
void fileMenu(int index)
{
    switch (index)
    {
    case 1:
        fileflag = 1;
        break;
    case 2:
        fileflag = 2;
        break;
    case 3:
        fileflag = 3;
        break;
    case 4:
        fileflag = 4;
        break;
    case 5:
        fileflag = 5;
        cout << "Enter your filepath + filename (ex: \"./OBJs4/teddy.obj\"): ";
        string filename;
        cin >> filename;
        testobj = ObjLoader(filename);
        break;
    }
    glutPostRedisplay();
}
void colorMenu(int index)
{
    switch (index)
    {
    case 1:
        colorflag = 0;
        break;
    case 2:
        colorflag = 1;
        break;
    }
}
void renderMenu(int index)
{
    switch (index)
    {
    case 1:
        drawflag = 1;
        break;
    case 2:
        drawflag = 2;
        break;
    case 3:
        drawflag = 3;
        break;
    }
}
void menudraw()
{
    switch (fileflag)
    {
    case 1:
        drawmode(gourd);
        setglOrtho(gourd);
        break;
    case 2:
        drawmode(octahedron);
        setglOrtho(octahedron);
        break;
    case 3:
        drawmode(teapot);
        setglOrtho(teapot);
        break;
    case 4:
        drawmode(teddy);
        setglOrtho(teddy);
        break;
    case 5:
        drawmode(testobj);
        setglOrtho(testobj);
        break;
    }
    drawline();
    ChangeSize2();
    glutPostRedisplay();
}

void drawmode(ObjLoader& obj)
{
    switch (drawflag)
    {
    case 1:
        obj.drawpoint(colorflag);
        break;
    case 2:
        obj.drawline(colorflag);
        break;
    case 3:
        obj.drawface(colorflag);
        break;
    }
}
void setglOrtho(ObjLoader& obj)
{
    float left = obj.getMinX();
    float right = obj.getMaxX();
    float bottom = obj.getMinY();
    float top = obj.getMaxY();

    float minf = min(left, bottom);
    float maxf = max(right, top);

    float nearVal = -100.0f;
    float farVal = 100.0f;

    glOrtho(1.2*minf, 1.2 * maxf, 1.2 * minf, 1.2 * maxf, nearVal, farVal);
}
void ChangeSize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    switch (fileflag)
    {
    case 1:
        setglOrtho(gourd);
        break;
    case 2:
        setglOrtho(octahedron);
        break;
    case 3:
        setglOrtho(teapot);
        break;
    case 4:
        setglOrtho(teddy);
        break;
    case 5:
        setglOrtho(testobj);
        break;
    default:
        gourd.drawface(colorflag);
        setglOrtho(gourd);
        break;
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}
void ChangeSize2()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    switch (fileflag)
    {
    case 1:
        setglOrtho(gourd);
        break;
    case 2:
        setglOrtho(octahedron);
        break;
    case 3:
        setglOrtho(teapot);
        break;
    case 4:
        setglOrtho(teddy);
        break;
    case 5:
        setglOrtho(testobj);
        break;
    default:
        gourd.drawface(colorflag);
        setglOrtho(gourd);
        break;
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}
void drawline()
{
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-100, 0, 0);
    glVertex3f(100, 0, 0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0, -100, 0);
    glVertex3f(0, 100, 0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0, 0, -100);
    glVertex3f(0, 0, 100);
    glEnd();
}