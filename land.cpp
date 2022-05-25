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
extern float cube_unit;
extern float lampY;
extern float lampWidth;
extern float lampHandlex;
extern float lampHandley;
extern float lampRadious;
extern float footpathX;
extern float pathX;
extern float roadX;
extern float numberOfLamps;

extern vector<unsigned int> tex;
extern float cube_unit;

void LamppostX()
{
    float a,b,c,d;
//    glTranslatef(0,-lampY+radious+width+width,0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex[17]);
    glPushMatrix();
    glTranslatef(lampWidth/2,lampY/2,lampWidth/2);
    glScalef(lampWidth,20,lampWidth);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    c = 0;
    d = 0;
    a = lampWidth/lampWidth + c;
    b = lampY/lampY + d;
    cube(1.0,1.0,1.0,a,b,c,d);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(lampHandlex/2 + lampWidth,lampWidth/2 + lampY - lampWidth,lampWidth/2);
    glScalef(lampHandlex,lampWidth,lampWidth);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    c = 0;
    d = 0;
    a = lampHandlex/lampHandlex + c;
    b = lampWidth/lampWidth + d;
    cube(1.0,1.0,1.0,a,b,c,d);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(lampWidth/2 + lampHandlex - lampWidth,lampHandley/2 + lampY - lampWidth - lampWidth,lampWidth/2);
    glScalef(lampWidth,lampHandley,lampWidth);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    c = 0;
    d = 0;
    a = lampWidth/lampWidth + c;
    b = lampHandley/lampHandley + d;
    cube(1.0,1.0,1.0,a,b,c,d);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(lampRadious + lampHandlex - lampRadious - lampWidth/2,lampY - lampRadious - lampWidth - lampWidth,lampWidth/2);
    sphere(1.0,1.0,1.0,lampRadious);
    glPopMatrix();
}


void LamppostZ()
{
    glPushMatrix();
    glTranslatef(lampWidth/2,0,lampWidth/2);
    glRotatef(90,0,1,0);
    glTranslatef(-lampWidth/2,0,-lampWidth/2);
    LamppostX();
    glPopMatrix();
}

//float numberOfLamps = 5;

void LamppostRowZ(float lengthx, float lengthz)
{
    glPushMatrix();
    glTranslatef(0,0,lampRadious-lampWidth);
    LamppostX();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);
    for(float i=0; i<lengthz-(lengthz/numberOfLamps); i+=(lengthz/numberOfLamps))
    {
        glTranslatef(0,0,(lengthz/numberOfLamps));
        LamppostX();
    }
    glPopMatrix();
}

void LamppostRowX(float lengthx,float lengthz)
{
    glPushMatrix();
    glTranslatef(0,0,0);
    LamppostZ();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);
    for(float i=0; i<lengthx - (lengthx/numberOfLamps); i+=(lengthx/numberOfLamps))
    {
        glTranslatef((lengthx/numberOfLamps),0,0);
        LamppostZ();
    }
    glPopMatrix();
}

void LamppostRowZinverse(float lengthx,float lengthz)
{
    glPushMatrix();
    glTranslatef(0,0,lampRadious-lampWidth);
    glTranslatef(lampWidth/2,0,lampWidth/2);
    glRotatef(180,0,1,0);
    glTranslatef(-lampWidth/2,0,-lampWidth/2);
    LamppostX();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);
    for(float i=0; i<lengthz-(lengthz/numberOfLamps); i+=(lengthz/numberOfLamps))
    {
        glTranslatef(0,0,(lengthz/numberOfLamps));
        glPushMatrix();
        glTranslatef(lampWidth/2,0,lampWidth/2);
        glRotatef(180,0,1,0);
        glTranslatef(-lampWidth/2,0,-lampWidth/2);
        LamppostX();
        glPopMatrix();
    }
    glPopMatrix();
}

void LamppostRowXinverse(float lengthx,float lengthz)
{
    glPushMatrix();
    glTranslatef(0,0,0);
    glTranslatef(lampWidth/2,0,lampWidth/2);
    glRotatef(180,0,1,0);
    glTranslatef(-lampWidth/2,0,-lampWidth);
    LamppostZ();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);
    for(float i=0; i<lengthx - (lengthx/numberOfLamps); i+=(lengthx/numberOfLamps))
    {
        glTranslatef((lengthx/numberOfLamps),0,0);
        glPushMatrix();
        glTranslatef(lampWidth/2,0,lampWidth/2);
        glRotatef(180,0,1,0);
        glTranslatef(-lampWidth/2,0,-lampWidth/2);
        LamppostZ();
        glPopMatrix();
    }
    glPopMatrix();
}

void DualLamppostRowZ(float lengthx,float lengthz)
{
    glPushMatrix();
    LamppostRowZ(lengthx,lengthz);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(roadX - footpathX*8/5,0,0);
    LamppostRowZinverse(lengthx,lengthz);
    glPopMatrix();
}

void DualLamppostRowX(float lengthx,float lengthz)
{
    glPushMatrix();
    glTranslatef(0,0,roadX - footpathX*8/5);
    LamppostRowX(lengthx,lengthz);
    glPopMatrix();

    glPushMatrix();
    LamppostRowXinverse(lengthx,lengthz);
    glPopMatrix();
}


void Footpath(float lengthx, float lengthz)
{
    float a,b,c,d;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex[14]);
    glPushMatrix();
    glTranslatef(lengthx/2,0,lengthz/2);
    glScalef(lengthx,1,lengthz);
    glTranslatef(-cube_unit/2,-cube_unit,-cube_unit/2);
    c = 0;
    d = 0;
    a = lengthx/lengthx + c;
    b = lengthz/lengthz + d;
    cube(1.0,1.0,1.0,a,(lengthz/footpathX)*b,c,(lengthz/footpathX)*d);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void Path(float lengthx, float lengthz)
{
    float middle = 2*cube_unit;
    float sideWidth = (lengthx-2*cube_unit)/2;
    float yellow = middle/3;
    float a,b,c,d;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex[15]);
    glPushMatrix();
    glTranslatef(sideWidth/2,0,lengthz/2);
    glScalef(sideWidth,1,lengthz);
    glTranslatef(-cube_unit/2,-cube_unit,-cube_unit/2);
    c = 0;
    d = 0;
    a = sideWidth/lengthx + c;
    b = lengthz/lengthz + d;
    cube(1.0,1.0,1.0,a,(lengthz/lengthx)*b,c,(lengthz/lengthx)*d);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(sideWidth/2 + middle + sideWidth,0,lengthz/2);
    glScalef(sideWidth,1,lengthz);
    glTranslatef(-cube_unit/2,-cube_unit,-cube_unit/2);
    c = (sideWidth + middle)/lengthx;
    d = 0;
    a = sideWidth/lengthx + c;
    b = lengthz/lengthz + d;
    cube(1.0,1.0,1.0,a,(lengthz/lengthx)*b,c,(lengthz/lengthx)*d);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(yellow/2 + sideWidth + yellow,0,lengthz/2);
    glScalef(yellow,1,lengthz);
    glTranslatef(-cube_unit/2,-cube_unit,-cube_unit/2);
    c = (sideWidth + yellow)/lengthx;
    d = 0;
    a = yellow/lengthx + c;
    b = lengthz/lengthz + b;
    cube(1.0,1.0,1.0,a,(lengthz/lengthx)*b,c,(lengthz/lengthx)*d);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D,tex[16]);
    glPushMatrix();
    glTranslatef(yellow/2 + sideWidth,0,lengthz/2);
    glScalef(yellow,1,lengthz);
    glTranslatef(-cube_unit/2,-cube_unit,-cube_unit/2);
    c = 0;
    d = 0;
    a = yellow/yellow + c;
    b = lengthz/lengthz + d;
    cube(1.0,1.0,1.0,a,(lengthz/middle)*b,c,(lengthz/middle)*d);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(yellow/2 + sideWidth + yellow + yellow,0,lengthz/2);
    glScalef(yellow,1,lengthz);
    glTranslatef(-cube_unit/2,-cube_unit,-cube_unit/2);
    c = 0;
    d = 0;
    a = yellow/yellow + c;
    b = lengthz/lengthz + d;
    cube(1.0,1.0,1.0,a,(lengthz/middle)*b,c,(lengthz/middle)*d);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void RoadZ(float lengthx, float lengthz, bool infront /*= true*/)
{
    glPushMatrix();
    Footpath(footpathX,lengthz);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(footpathX,0,0);
    Path(pathX,lengthz);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(footpathX + pathX,0,0);
    Footpath(footpathX,lengthz);
    glPopMatrix();

    glPushMatrix();
    if(!infront)
        glTranslatef(0,0,(lengthz/numberOfLamps) - lampWidth - lampRadious + lampWidth/2);
    glTranslatef(footpathX*4/5,0,0);
    DualLamppostRowZ(lengthx,lengthz);
    glPopMatrix();
}

void RoadX(float lengthx, float lengthz, bool infront/*=true*/)
{
    glPushMatrix();
    glTranslatef(lengthx/2,0,roadX/2);
    glRotatef(90,0,1,0);
    glTranslatef(-roadX/2,0,-lengthx/2);
    RoadZ(lengthx, lengthz, infront);
    glPopMatrix();

}

void JunctionFootpath(float lengthx)
{
    float a,b,c,d;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[14]);
    glPushMatrix();
    glScalef(footpathX,1,footpathX);
    glTranslatef(-cube_unit/2,-cube_unit,-cube_unit/2);
    c = 0;
    d = 0;
    a = footpathX/footpathX + c;
    b = footpathX/footpathX + d;
    cube(1.0,1.0,1.0,a,(footpathX/footpathX)*b,c,(footpathX/footpathX)*d);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void Junction(float lengthx, float lengthz)
{
    float a,b,c,d;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex[15]);
    glPushMatrix();
    glTranslatef(pathX/2,0,pathX/2);
    glScalef(pathX,1,pathX);
    glTranslatef(-cube_unit/2,-cube_unit,-cube_unit/2);
    c = footpathX/(footpathX + pathX + footpathX);
    d = footpathX/(footpathX + pathX + footpathX);
    a = pathX/(footpathX + pathX + footpathX)+ c;
    b = pathX/(footpathX + pathX + footpathX) + d;
    cube(1.0,1.0,1.0,a,(lengthz/lengthx)*b,c,(lengthz/lengthx)*d);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(footpathX/2 - pathX/2 + footpathX,0,pathX/2);
    glScalef(footpathX,1,pathX);
    glTranslatef(-cube_unit/2,-cube_unit,-cube_unit/2);
    c = 0;
    d = footpathX/(footpathX + pathX + footpathX);
    a = footpathX/(footpathX + pathX + footpathX) + c;
    b = pathX/(footpathX + pathX + footpathX) + d;
    cube(1.0,1.0,1.0,a,(lengthz/lengthx)*b,c,(lengthz/lengthx)*d);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(footpathX/2 + pathX/2 + footpathX + footpathX,0,pathX/2);
    glScalef(footpathX,1,pathX);
    glTranslatef(-cube_unit/2,-cube_unit,-cube_unit/2);
    c = (footpathX + pathX)/(footpathX + pathX + footpathX);
    d = footpathX/(footpathX + pathX + footpathX);
    a = footpathX/(footpathX + pathX + footpathX) + c;
    b = pathX/(footpathX + pathX + footpathX) + d;
    cube(1.0,1.0,1.0,a,(lengthz/lengthx)*b,c,(lengthz/lengthx)*d);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0, - pathX/2 + footpathX + footpathX);
    glRotatef(90,0,1,0);
    glTranslatef(footpathX/2,0,pathX/2);
    glScalef(footpathX,1,pathX);
    glTranslatef(-cube_unit/2,-cube_unit,-cube_unit/2);
    c = 0;
    d = footpathX/(footpathX + pathX + footpathX);
    a = footpathX/(footpathX + pathX + footpathX) + c;
    b = pathX/(footpathX + pathX + footpathX) + d;
    cube(1.0,1.0,1.0,a,(lengthz/lengthx)*b,c,(lengthz/lengthx)*d);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0, pathX/2 + footpathX + footpathX + footpathX);
    glRotatef(90,0,1,0);
    glTranslatef(footpathX/2,0,pathX/2);
    glScalef(footpathX,1,pathX);
    glTranslatef(-cube_unit/2,-cube_unit,-cube_unit/2);
    c = (footpathX + pathX)/(footpathX + pathX + footpathX);
    d = footpathX/(footpathX + pathX + footpathX);
    a = footpathX/(footpathX + pathX + footpathX) + c;
    b = pathX/(footpathX + pathX + footpathX) + d;
    cube(1.0,1.0,1.0,a,(lengthz/lengthx)*b,c,(lengthz/lengthx)*d);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    ///Footpaths
    glPushMatrix();
    glTranslatef(pathX + footpathX/2,0,-pathX/2 + footpathX + footpathX/2);
    JunctionFootpath(lengthx);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(pathX + footpathX/2,0,pathX + footpathX/2);
    JunctionFootpath(lengthx);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-footpathX/2,0,pathX + footpathX/2);
    JunctionFootpath(lengthx);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-footpathX/2,0,-footpathX/2);
    JunctionFootpath(lengthx);
    glPopMatrix();
}

void Field(GLfloat lengthx, GLfloat lengthy, GLfloat lengthz)
{
    float a,b,c,d;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex[13]);
    glPushMatrix();
    glTranslatef(lengthx/2,0,lengthz/2);
    glScalef(lengthx,lengthy,lengthz);
    glTranslatef(-cube_unit/2,-cube_unit,-cube_unit/2);
    c = 0;
    d = 0;
    a = lengthx/lengthx + c;
    b = lengthz/lengthz + d;
    cube(1.0,1.0,1.0,(lengthx/5)*a,(lengthz/5)*b,(lengthx/5)*c,(lengthz/5)*d);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}


void Ground(GLfloat lengthx, GLfloat lengthy, GLfloat lengthz)
{
    glPushMatrix();
    Field(lengthx,lengthy,lengthz);
    glPopMatrix();

    glPushMatrix();
    glTranslated(lengthx,0,0);
    RoadZ(lengthx, lengthz, true);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(lengthx + footpathX + pathX + footpathX,0,0);
    Field(lengthx,lengthy,lengthz);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,lengthz);
    RoadX(lengthx,lengthz,true);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(lengthx + footpathX,0,lengthz + footpathX);
    Junction(lengthx,lengthx);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(lengthx + roadX, 0, lengthz);
    RoadX(lengthx,lengthz,false);
    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(lengthx + roadX + (lengthx/numberOfLamps) - lampRadious + lampWidth/2, 0, lengthz + footpathX*4/5);
//    DualLamppostRowX(lengthx);
//    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,lengthz + footpathX + pathX + footpathX);
    Field(lengthx,lengthy,lengthz);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(lengthx,0,lengthz + roadX);
    RoadZ(lengthx,lengthz, false);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(lengthx + footpathX + pathX + footpathX, 0, lengthz + footpathX + pathX + footpathX);
    Field(lengthx,lengthy,lengthz);
    glPopMatrix();
}

