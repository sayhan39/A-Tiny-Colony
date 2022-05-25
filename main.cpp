#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "BmpLoader.h"

#include "accessories.h"
#include "building.h"
#include "cubes.h"
#include "curves.h"
#include "dimensions.h"
#include "furnitures.h"
#include "land.h"
#include "lights.h"
#include "movement.h"
#include "spheres.h"
#include "textures.h"
#include "utility.h"

using namespace std;

extern int windowHeight = 600;
extern int windowWidth = 800;
//float aspect_ratio = 1.0*windowHeight/windowWidth;



//GLfloat eyex = 0;
//GLfloat eyey = 5;
//GLfloat eyez = 20;
//
//GLfloat lookAtx = 0;
//GLfloat lookAty = 5;
//GLfloat lookAtz = 0;

/* GLUT callback Handlers */

/*static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}*/

/*static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-0.75,0.75,2,5000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyex,eyey,eyez, lookAtx,lookAty,lookAtz, 0,1,0);

    glPushMatrix();
    cube(1.0,1.0,1.0);
    glPopMatrix();


    glutSwapBuffers();
}*/

/*void printEyePosition()
{
    cout<<getEyePosition()[0]<<' '<<getEyePosition()[1]<<' '<<getEyePosition()[2]<<endl;
}*/

/*static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
    }

    glutPostRedisplay();
}*/

/*static void idle(void)
{
    glutPostRedisplay();
}*/

/* Program entry point */

int main(int argc, char *argv[])
{
    cout<<"**************************************************************"<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<"****************                                  ************"<<endl;
    cout<<"****************    Road Junction With Building   ************"<<endl;
    cout<<"****************                                  ************"<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<"\nUse 8,5,1,3 to move your Eye point"<<endl;
    cout<<"\nUse 4 and 6 to move your Eye point to the left and to the right"<<endl;
    cout<<"\nUse w and s to move your Eye point and LookAt point higher and lower"<<endl;
    cout<<"\nUse z,c,b and m to switch LIGHT1, LIGHT2, LIGHT3 and LIGHT0"<<endl;
    cout<<"\nUse p and P to open and close the doors"<<endl;
    cout<<"\nUse o and O to open and close window panels"<<endl;
    cout<<"\nUse y, u and i to switch ambient, diffusion and specular lighting effect"<<endl;
    cout<<"\nUse ' to pause Mouse Movement function"<<endl;

    glutInit(&argc, argv);
    glutInitWindowSize(windowWidth,windowHeight);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("1607039");

    glutReshapeFunc(screenSize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutKeyboardUpFunc(keyUp);
    glutPassiveMotionFunc(passiveMouseMovement);
    glutIdleFunc(idle);

//    glClearColor(1,1,1,1);
//    glEnable(GL_CULL_FACE);
//    glCullFace(GL_BACK);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_NORMALIZE);
//    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    LoadFiles();

    directionLight(GL_LIGHT1);

    Angle();
    AngleReverse();


    glutMainLoop();

    return EXIT_SUCCESS;
}
