#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include ".\GL\freeglut.h"
#include "ObjLoader.h"
#include "Menu.h"

void RenderScene(void);
void My_Keyboard(unsigned char key, int x, int y);
float anglex = 0;
float angley = 0;
float anglez = 0;
float x01 = 0;
float y01 = 0;
float z01 = 0; 
float cameraX = 0.0f;
float cameraY = 0.0f;
float cameraZ = 10.0f;
float lookAtX = 0.0f;
float lookAtY = 0.0f;
float lookAtZ = 0.0f;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(600, 80);
    glutCreateWindow("Simple Triangle");

    glEnable(GL_DEPTH_TEST);

    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(&RenderScene);
    glutKeyboardFunc(My_Keyboard);
    creatmenu();
    glutMainLoop();
    return 0;
}
void RenderScene(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cameraX, cameraY, cameraZ, lookAtX, lookAtY, lookAtZ, 0, 1, 0);
    glRotatef(anglex, 1, 0, 0);
    glRotatef(angley, 0, 1, 0);
    glRotatef(anglez, 0, 0, 1);
    glTranslated(x01, 0, 0);
    glTranslated(0, y01, 0);
    glTranslated(0, 0, z01);
    menudraw();
    glutSwapBuffers();
}
void My_Keyboard(unsigned char key, int x, int y)
{
    if (key == 'x')
    {
        anglex += 5;
    }
    else if (key == 'X')
    {
        anglex -= 5;
    }
    else if (key == 'y')
    {
        angley += 5;
    }
    else if (key == 'Y')
    {
        angley -= 5;
    }
    else if (key == 'z')
    {
        anglez += 5;
    }
    else if (key == 'Z')
    {
        anglez -= 5;
    }
    else if (key == 'q')
    {
        anglex = 0;
        angley = 0;
        anglez = 0;
        x01 = 0;
        y01 = 0;
        z01 = 0;
        cameraX = 0.0f;
        cameraY = 0.0f;
        cameraZ = 10.0f;
        lookAtX = 0.0f;
        lookAtY = 0.0f;
        lookAtZ = 0.0f;
    }
    else if (key == 'a')
    {
        x01 += 0.25f;
    }
    else if (key == 's')
    {
        y01 += 0.25f;
    }
    else if (key == 'd')
    {
        z01 += 0.25f;
    }
    else if (key == 'A')
    {
        x01 -= 0.25f;
    }
    else if (key == 'S')
    {
        y01 -= 0.25f;
    }
    else if (key == 'D')
    {
        z01 -= 0.25f;
    }
    else if (key == 'i')
    {
        cameraX += 0.05f;
    }
    else if (key == 'o')
    {
        cameraY += 0.05f;
    }
    else if (key == 'p')
    {
        cameraZ += 0.05f;
    }
    else if (key == 'j')
    {
        lookAtX += 0.05f;
    }
    else if (key == 'k')
    {
        lookAtY += 0.05f;
    }
    else if (key == 'l')
    {
        lookAtZ += 0.05f;
    }
    else if (key == 'I')
    {
        cameraX -= 0.05f;
    }
    else if (key == 'O')
    {
        cameraY -= 0.05f;
    }
    else if (key == 'P')
    {
        cameraZ -= 0.05f;
    }
    else if (key == 'J')
    {
        lookAtX -= 0.05f;
    }
    else if (key == 'K')
    {
        lookAtY -= 0.05f;
    }
    else if (key == 'L')
    {
        lookAtZ -= 0.05f;
    }
    glutPostRedisplay();
}