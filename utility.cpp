#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
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


GLfloat eyex = 0;
GLfloat eyey = 5;
GLfloat eyez = 20;

GLfloat lookAtx = 0;
GLfloat lookAty = 5;
GLfloat lookAtz = 0;

extern float groundx;
extern float groundy;
extern float groundz;

extern float windowRotate;
extern float doorRotate;

extern float FileCabinetsingleDrawerOpen;

extern float cube_unit;

float verticalRotate = 0;
float horizontalRotate = 0;

float fanRotation = 0;
float fanRotationValue = 1;

bool mouseMovement = true;

bool roomLightSwitch=true;
bool officeLightSwitch=true;

bool ambientLightSwitch=false;
bool diffuseLightSwitch=false;
bool specularLightSwitch=false;
bool spotLightSwitch=false;

//extern float groundx;
//extern float groundz;
//extern float floorx;
//extern float floorz;
//extern float roadX;
//extern float parkBenchz;

bool keyStates[256] = {false};

void Scene()
{
    glPushMatrix();
    Ground(groundx/2,groundy,groundz/2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(groundx/2 - officeFloorx - 10,0,groundz/2 - floorz- 10);
    House();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(groundx/2 + roadX+10,0,groundz/2 - officeFloorz-10-10);
    Office();
    glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-0.75,0.75,2,5000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyex,eyey,eyez, lookAtx,lookAty,lookAtz, 0,1,0);

    glRotatef(verticalRotate,0,1,0);
    glRotatef(horizontalRotate,1,0,0);

    if(keyStates['x'])
    {
        glDisable(GL_TEXTURE_2D);
        glPushMatrix();
        axes();
        glPopMatrix();
    }
    //infront, behind, right, left,      height,        width
    float window[]= {1,          0,      1,    1,    grillHeight,   grillWidth};
    float door[] = {0,          0,      0,    1,    doorHeight,     doorWidth};
    float stair[] = {0,         0,      0,      0,  stairHeight,    stairWidth};
    //top, bottom, infront, behind, right, left
//    glPushMatrix();
//    Room(roomX,roomY,roomZ,true,true, true,    true,   true,   true, true,window,door,stair,-1,-1,-1,1);
//    glPopMatrix();

    glPushMatrix();
    glTranslatef(-groundx/2 - roadX/2,0,-groundz/2 - roadX/2);
    Scene();
    glPopMatrix();

//    glPushMatrix();
//    CeilingFan();
//    glPopMatrix();

//    glPushMatrix();
//    glScalef(0.2,0.2,0.2);
//    bulbCurve(1.0,1.0,0.0,1.0);
//    glPopMatrix();

//    glPushMatrix();
//    HeadTable();
//    glPopMatrix();

//    glPushMatrix();
//    HeadTableChair();
//    glPopMatrix();

//    glPushMatrix();
//    EmployeeTableChair(180);
//    glPopMatrix();

//    glPushMatrix();
//    EmployeeTable(false);
//    glPopMatrix();

//    glPushMatrix();
//    Tool();
//    glPopMatrix();

//    glPushMatrix();
//    DiningTableAndTools();
//    glPopMatrix();

//    glPushMatrix();
//    OfficeChair();
//    glPopMatrix();

//    glPushMatrix();
//    Desk();
//    glPopMatrix();

//    glPushMatrix();
//    DeskAndChair(90);
//    glPopMatrix();

//    glPushMatrix();
//    DiningTable();
//    glPopMatrix();

//    glPushMatrix();
//    CabinetInverse(true);
//    glPopMatrix();

//    glPushMatrix();
//    glRotatef(90,0,0,1);
//    manualCurve();
//    glPopMatrix();

//    glPushMatrix();
//    showNewPoints();
//    glPopMatrix();

//    glPushMatrix();
//    ParkBench();
//    glPopMatrix();

//    glPushMatrix();
//    ParkBenchPair();
//    glPopMatrix();

//    glPushMatrix();
//    FilingCabinet(3,4,270);
//    glPopMatrix();

//    glPushMatrix();
//    TableChairRotate(180);
//    TableChair();
//    glPopMatrix();

//    glPushMatrix();
////    glTranslatef(roomX + roomX/2 - stairHeight/2,cube_unit,roomZ);
//    Stair(stairWidth, stairHeight);
//    glPopMatrix();

//    glPushMatrix();
//    House();
//    glPopMatrix();

//    glPushMatrix();
//    LamppostZ();
//    glPopMatrix();

//    glPushMatrix();
//    RoadX(groundx/2,groundz/2,true);
//    glPopMatrix();

//    glPushMatrix();
//    WindowXY(8,8,false);
//    glPopMatrix();

//    glPushMatrix();
//    WindowYZ(8,8,true);
//    glPopMatrix();

//    glPushMatrix();
//    WindowPanelXY(8,8);
//    glPopMatrix();

//    glPushMatrix();
//    doorXY(6,3,false,true);
//    glPopMatrix();

//    glPushMatrix();
//    doorYZ(6,3,true,true);
//    glPopMatrix();

//    glPushMatrix();
//    Bed(0.2,1.5,0.5,1);
//    glPopMatrix();

//    glPushMatrix();
//    Chair();
//    glPopMatrix();

//    glPushMatrix();
//    Table(true);
//    glPopMatrix();

//    glPushMatrix();
//    Cabinet();
//    glPopMatrix();

//    glPushMatrix();
//    DrawerKnob();
//    glPopMatrix();

//    glPushMatrix();
//    Pillow();
//    glPopMatrix();

    /*if(glIsEnabled(GL_LIGHT0))
        cout<<"Light 0"<<endl;
    if(glIsEnabled(GL_LIGHT1))
        cout<<"Light 1"<<endl;
    if(glIsEnabled(GL_LIGHT2))
        cout<<"Light 2"<<endl;
    if(glIsEnabled(GL_LIGHT3))
        cout<<"Light 3"<<endl;
    if(glIsEnabled(GL_LIGHT4))
        cout<<"Light 4"<<endl;
    if(glIsEnabled(GL_LIGHT5))
        cout<<"Light 5"<<endl;
    if(glIsEnabled(GL_LIGHT6))
        cout<<"Light 6"<<endl;
    if(glIsEnabled(GL_LIGHT7))
        cout<<"Light 7"<<endl;*/

//    cout<<"Eye Point: ("<<eyex<<", "<<eyey<<", "<<eyez<<")"<<endl;

//    glPushMatrix();
//    glTranslatef(lookAtx,lookAty,lookAtz);
//    glTranslatef(-0.5,-0.5,-0.5);
//    cube(1.0,1.0,1.0);
//    glPopMatrix();

    glPushMatrix();
    RoomLight(GL_LIGHT2);
    glPopMatrix();

    glPushMatrix();
    OfficeLight(GL_LIGHT3);
    glPopMatrix();

//    glPushMatrix();
//    Spotlighting(GL_LIGHT4);
//    glPopMatrix();

//    directionLight(GL_LIGHT1);
//    lighting(keyStates['l'],GL_LIGHT0);

//    glPushMatrix();
//    Ground(groundx/2,groundy,groundz/2);
//    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

static int windowHeight = 600, windowWidth = 800;

float aspect_ratio = 1.0*windowHeight/windowWidth;

void screenSize(int width, int height)
{
    float new_ratio = 1.0*height/width;

    float vertical_gap = max(height/aspect_ratio - width, width - height/aspect_ratio);
    float horizontal_gap = max(height - aspect_ratio*width, width*aspect_ratio - height);
    vertical_gap /= 2.0;
    horizontal_gap /= 2.0;

    if(new_ratio < aspect_ratio)
    {
        glViewport(vertical_gap,0,height/aspect_ratio,height);
    }
    else if(new_ratio > aspect_ratio)
    {
        glViewport(0,0,width,aspect_ratio*width);
    }
    else if(new_ratio == aspect_ratio)
    {
        glViewport(0,0,windowWidth, windowHeight);
    }
}

void key(unsigned char key, int x, int y)
{
    if(key == 'q' || key == 27)
    {
        exit(1);
    }
    else
    {
        keyStates[key] = true;
    }

    glutPostRedisplay();
}

void keyUp(unsigned char key, int x, int y)
{
    keyStates[key] = false;

    glutPostRedisplay();
}

void idle(void)
{
    if(keyStates['8'])
    {
        walkStraightXZ(keyStates['8']);
        keyStates['8'] = false;
    }

    if(keyStates['5'])
    {
        walkStraightXZ(!keyStates['5']);
        keyStates['5'] = false;
    }

    if(keyStates['4'])
    {
        rotateLookAtPointXZ(true, true, true, -1.5);
        keyStates['4'] = false;
    }

    if(keyStates['6'])
    {
        rotateLookAtPointXZ(true, true, true, 1.5);
        keyStates['6'] = false;
    }

    if(keyStates['1'])
    {
        rotateEyeXZ(true, true, true);
        keyStates['1'] = false;
    }

    if(keyStates['3'])
    {
        rotateEyeXZ(true, true, true);
        keyStates['3'] = false;
    }

    if(keyStates['R'])
    {
        verticalRotate++;
        if(verticalRotate>=360)
            verticalRotate=0;
        keyStates['R'] = false;
    }

    if(keyStates['r'])
    {
        horizontalRotate++;
        if(horizontalRotate>=360)
            horizontalRotate=0;
        keyStates['r'] = false;
    }

    if(keyStates['E'])
    {
        verticalRotate--;
        if(verticalRotate<=0)
            verticalRotate=360;
        keyStates['E'] = false;
    }

    if(keyStates['e'])
    {
        horizontalRotate--;
        if(horizontalRotate>=360)
            horizontalRotate=360;
        keyStates['e'] = false;
    }

    if(keyStates['a'])
    {
        eyex--;
        lookAtx--;
        keyStates['a'] = false;
    }

    if(keyStates['d'])
    {
        eyex++;
        lookAtx++;
        keyStates['d'] = false;
    }

    if(keyStates['w'])
    {
        eyey++;
        lookAty++;
        keyStates['w'] = false;
    }

    if(keyStates['s'])
    {
        eyey--;
        lookAty--;
        keyStates['s'] = false;
    }

    if(keyStates['v'])
    {
        Angle();
        AngleReverse();
        keyStates['v'] = false;
    }

    if(keyStates['p'])
    {
        if(windowRotate<=90)
            windowRotate++;
        keyStates['p']=false;
    }

    if(keyStates['P'])
    {
        if(windowRotate>=0)
            windowRotate--;
        keyStates['P']=false;
    }

    if(keyStates['o'])
    {
        if(doorRotate<=90)
            ++doorRotate;
        keyStates['o']=false;
    }

    if(keyStates['O'])
    {
        if(doorRotate>=0)
            --doorRotate;
        keyStates['O']=false;
    }

    if(keyStates['<'])
    {
//        if(FileCabinetdrawerOpen>0)
//            FileCabinetdrawerOpen-=0.5;
        keyStates['<']=false;
    }

    if(keyStates['>'])
    {
//        if(FileCabinetsingleDrawerOpen > FileCabinetdrawerOpen)
//            FileCabinetsingleDrawerOpen -= 0.5;
//        if(FileCabinetdrawerOpen<4)
//        FileCabinetdrawerOpen+=0.5;
        keyStates['>']=false;
    }

    if(keyStates[','])
    {
        if(FileCabinetsingleDrawerOpen>0)
            FileCabinetsingleDrawerOpen -=0.5;
        keyStates[',']=false;
    }

    if(keyStates['.'])
    {
        if(FileCabinetsingleDrawerOpen<4)
            FileCabinetsingleDrawerOpen+=0.5;
        keyStates['.']=false;
    }

    if(keyStates['z'])
    {
//        glDisable(GL_LIGHT0);
////        glDisable(GL_LIGHT1);
//        glDisable(GL_LIGHT2);
//        glDisable(GL_LIGHT3);
//        glDisable(GL_LIGHT4);
//        glDisable(GL_LIGHT5);
//        glDisable(GL_LIGHT6);
//        glDisable(GL_LIGHT7);
        if(glIsEnabled(GL_LIGHT1))
            glDisable(GL_LIGHT1);
        else
            glEnable(GL_LIGHT1);
        keyStates['z']=false;
    }

    if(keyStates['c'])
    {
////        glDisable(GL_LIGHT0);
//        glDisable(GL_LIGHT1);
//        glDisable(GL_LIGHT2);
//        glDisable(GL_LIGHT3);
//        glDisable(GL_LIGHT4);
//        glDisable(GL_LIGHT5);
//        glDisable(GL_LIGHT6);
//        glDisable(GL_LIGHT7);
        roomLightSwitch=!roomLightSwitch;
        keyStates['c']=false;
    }

    if(keyStates['b'])
    {
////        glDisable(GL_LIGHT0);
//        glDisable(GL_LIGHT1);
//        glDisable(GL_LIGHT2);
//        glDisable(GL_LIGHT3);
//        glDisable(GL_LIGHT4);
//        glDisable(GL_LIGHT5);
//        glDisable(GL_LIGHT6);
//        glDisable(GL_LIGHT7);
        officeLightSwitch=!officeLightSwitch;
        keyStates['b']=false;
    }

    if(keyStates['m'])
    {
        if(glIsEnabled(GL_LIGHT0))
            glDisable(GL_LIGHT0);
        else
            glEnable(GL_LIGHT0);
        keyStates['m']=false;
    }

    if(keyStates['\''])
    {
        cout<<"Hello World"<<endl;
        mouseMovement=!mouseMovement;
        keyStates['\'']=false;
    }

    if(keyStates['y'])
    {
        ambientLightSwitch=!ambientLightSwitch;
        keyStates['y']=false;
    }

    if(keyStates['u'])
    {
        diffuseLightSwitch=!diffuseLightSwitch;
        keyStates['u']=false;
    }

    if(keyStates['i'])
    {
        specularLightSwitch=!specularLightSwitch;
        keyStates['i']=false;
    }

//    if(keyStates['t'])
//    {
//        spotLightSwitch=!spotLightSwitch;
//        keyStates['t']=false;
//    }

    if(true)
    {
        fanRotation+=fanRotationValue;
        if(fanRotation>=360)
            fanRotation=0;
    }

    if(keyStates['+'])
    {
        fanRotationValue++;
        if(fanRotationValue>5)
            fanRotationValue=5;
    }
    if(keyStates['-'])
    {
        fanRotationValue--;
        if(fanRotationValue<1)
            fanRotationValue=1;
    }

    if(keyStates['g'])
    {
        TopView();
        keyStates['g']=false;
    }

    if(keyStates['h'])
    {
        MiddleView();
        keyStates['h']=false;
    }

    if(keyStates['j'])
    {
        OldView();
        keyStates['j']=false;
    }

    glutPostRedisplay();
}


unsigned int ID;
vector <unsigned int> tex;

void LoadTexture(const char*filename)
{
    glGenTextures(1, &ID);
    tex.push_back(ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, ID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
}
