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

float windowRotate = 0;

float getWindowRotate()
{
    return windowRotate;
}

void setWindowRotate(float a)
{
    windowRotate = a;
}

void WindowPanelXY(float lengthx, float lengthy, bool infront/* = true*/)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex[8]);
    glPushMatrix();
    glTranslatef(lengthx-lengthx/4,0,0);
    glTranslatef(lengthx/4,0,0);
    if(infront)
        glRotatef(windowRotate,0,1,0);
    else if(!infront)
        glRotatef(windowRotate,0,-1,0);
    glTranslatef(-lengthx/4,lengthy/2,cube_unit/2/2/2/2);
    glScalef(lengthx/2,lengthy,cube_unit/2/2/2);
    glTranslatef(-cube_unit/2, -cube_unit/2, -cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    if(infront)
        glRotatef(windowRotate,0,-1,0);
    else if(!infront)
        glRotatef(windowRotate,0,1,0);
    glTranslatef(lengthx/2/2,lengthy/2,cube_unit/2/2/2/2);
    glScalef(lengthx/2,lengthy,cube_unit/2/2/2);
    glTranslatef(-cube_unit/2, -cube_unit/2, -cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void WindowXY(float lengthy, float lengthx,bool infront/*=true*/)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex[12]);
    glPushMatrix();
    if(!infront)
        glTranslatef(0,0,cube_unit/2);
    glPushMatrix();
    for(int i=0; i<lengthy; i++)
    {
//        if(i%2==1)
//            continue;
        glPushMatrix();
        glTranslatef(0,i,0);
        glTranslatef(lengthx/2,cube_unit/2/2/2,cube_unit/2/2/2);
        glScalef(lengthx,0.5*0.5*0.5*cube_unit,0.5*0.5*cube_unit);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        cube(1.0,1.0,1.0);
        glPopMatrix();
    }
    glPopMatrix();

    for(int j=0; j<lengthy; j++)
    {
        glPushMatrix();
        for(int i=0; i<=lengthx; i++)
        {
            if((i+j)%2==0)
                continue;
            glPushMatrix();
            if(i<lengthx)
                glTranslatef(0.5*0.5*0.5*cube_unit + (i)*cube_unit,cube_unit/2+0.125*cube_unit + j*cube_unit,0.5*0.5*0.5*cube_unit);
            else if(i>=lengthx)
                glTranslatef(0.5*0.5*0.5*cube_unit + i*cube_unit - cube_unit*0.5*0.5,cube_unit/2+0.125*cube_unit,0.5*0.5*0.5*cube_unit);
            glScalef(0.5*0.5*cube_unit,cube_unit*7/8,0.5*0.5*cube_unit);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            cube(1.0,1.0,1.0);
            glPopMatrix();
        }
        glPopMatrix();
    }
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    if(infront)
        glTranslatef(0,0,cube_unit/2);
    WindowPanelXY(lengthx,lengthy,infront);
    glPopMatrix();
}

void WindowYZ(float lengthx, float lengthy,bool right/*=true*/)
{
    glDisable(GL_TEXTURE_2D);
    glPushMatrix();
    if(right)
        glTranslatef((cube_unit/2+cube_unit/2/2/2)/2+cube_unit/2/2+cube_unit/2/2/2,0,lengthx/2);
    else
        glTranslatef((cube_unit/2+cube_unit/2/2/2)/2,0,lengthx/2);
    glRotatef(90,0,1,0);
    glTranslatef(-lengthx/2,0,-(cube_unit/2+cube_unit/2/2/2)/2);
    WindowXY(lengthx,lengthy,right);
    glPopMatrix();
}

float doorRotate = 0;

void doorXY(float lengthY,float lengthX, bool mirror/*=false*/, bool inverse/*=false*/)
{
    float a,b,c,d;
    float lengthZ = cube_unit/2;

    float stileX = 0.2*cube_unit;
    float headerX = lengthX-stileX-stileX;

    float headerY = 0.2*cube_unit;
    float stileY = lengthY;

    float stileZ = lengthZ;
    float headerZ = lengthZ;


    glPushMatrix();
    glTranslatef(stileX/2,stileY/2,stileZ/2);
    glScalef(stileX,stileY,stileZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(stileX/2+lengthX-stileX,stileY/2,stileZ/2);
    glScalef(stileX,stileY,stileZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(headerX/2+stileX,headerY/2+lengthY-headerY,headerZ/2);
    glScalef(headerX,headerY,headerZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex[9]);
    glPushMatrix();
    if(inverse && !mirror)
        glTranslatef(stileX,0,0);
    else if(inverse && mirror)
        glTranslatef(stileX,0,lengthZ);
    else if(!inverse && mirror)
        glTranslatef(lengthX-stileX,0,0);
    else if(!inverse && !mirror)
        glTranslatef(lengthX-stileX,0,lengthZ);

    if(!inverse && mirror)
        glRotatef(doorRotate,0,-1,0);
    else if(inverse && mirror)
        glRotatef(doorRotate,0,-1,0);
    else
        glRotatef(doorRotate,0,1,0);

    if(inverse && !mirror)
        glTranslatef((lengthX-stileX-stileX)/2,(lengthY-headerY)/2,lengthZ/2);
    else if(!inverse && mirror)
        glTranslatef(-(lengthX-stileX-stileX)/2,(lengthY-headerY)/2,lengthZ/2);
    else if(inverse && mirror)
        glTranslatef((lengthX-stileX-stileX)/2,(lengthY-headerY)/2,-lengthZ/2);
    else if(!inverse && mirror)
        glTranslatef(-(lengthX-stileX-stileX)/2,(lengthY-headerY)/2,lengthZ/2);
    else
        glTranslatef(-(lengthX-stileX-stileX)/2,(lengthY-headerY)/2,-lengthZ/2);
    glScalef(lengthX-stileX-stileX,lengthY-headerY,cube_unit/2);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    c = 0;
    d = 0;
    a = (lengthX-stileX-stileX)/lengthX + c;
    b = (lengthY-headerY)/lengthY + d;
    cube(1.0,1.0,1.0,a,b,c,d);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void doorYZ(float lengthY,float lengthX, bool mirror/*=false*/, bool inverse/*=false*/)
{
    float lengthZ = cube_unit/2;
    glPushMatrix();
    glTranslatef(lengthZ/2,0,lengthX/2);
    glRotatef(90,0,1,0);
    glTranslatef(-lengthX/2,0,-lengthZ/2);
    doorXY(lengthY,lengthX,mirror,inverse);
    glPopMatrix();
}

void Wall(float lengthx, float lengthy, float lengthz, bool walls,
                 bool *sides,float *window, float *door, float *stair,
                 float alpha,int railing)
{
    float a,b,c,d;
    float mult = 1;
    char face;
    if(sides[0])
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,tex[4]);
        face = 't';
        glPushMatrix();
        glTranslatef(lengthx/2*cube_unit,lengthy+cube_unit,(lengthz)/2*cube_unit);
        glScalef(lengthx,1,lengthz);
        glTranslatef(-1*cube_unit/2,0,-1*cube_unit/2);
        c = 0;
        d = 0;
        a = lengthx/lengthx + c;
        b = cube_unit/(lengthy+cube_unit+cube_unit) + d;
        Cube(1.0,1.0,1.0,a*2,b*20,c*2,d*20,face);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }

    if(sides[1])
    {
        if(railing==1)
        {
            for(int i=0; i<lengthx; i+=2)
            {
                glPushMatrix();
                glTranslatef(0.1+cube_unit+(i*cube_unit),1+1,0.1+1);
                glScalef(0.2,2,0.2);
                glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
                cube(1.0,1.0,1.0);
                glPopMatrix();
            }
            for(int i=0; i<lengthz; i+=2)
            {
                glPushMatrix();
                glTranslatef(0.1,1+1,0.1+cube_unit+(i*cube_unit));
                glScalef(0.2,2,0.2);
                glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
                cube(1.0,1.0,1.0);
                glPopMatrix();
            }

            glPushMatrix();
            glTranslatef(-lengthx/2+cube_unit,0.1+1+1+0.75,1-0.1);
            glScalef(lengthx,0.2,0.2);
            glTranslatef(0.5,0.5,0.5);
            cube(1,1,1);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(1.5*cube_unit,-0.25,0);
            glRotatef(270,0,1,0);
            glTranslatef(-lengthx/2+cube_unit-0.1,0.1+1+1+1,0.1+1);
            glScalef(lengthx,0.2,0.2);
            glTranslatef(0.5,0.5,0.5);
            cube(1,1,1);
            glPopMatrix();
        }
        if(railing==2)
        {
            for(int i=0; i<lengthx; i+=2)
            {
                glPushMatrix();
                glTranslatef(0.1+cube_unit+(i*cube_unit),1+1,0.1+1);
                glScalef(0.2,2,0.2);
                glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
                cube(1.0,1.0,1.0);
                glPopMatrix();
            }

            glPushMatrix();
            glTranslatef(-lengthx/2+cube_unit,0.1+1+1+0.75,-0.1+1);
            glScalef(lengthx,0.2,0.2);
            glTranslatef(0.5,0.5,0.5);
            cube(1,1,1);
            glPopMatrix();
        }
        if(railing==3)
        {
            for(int i=0; i<lengthx; i+=2)
            {
                glPushMatrix();
                glTranslatef(0.1+cube_unit+(i*cube_unit),1+1,0.1+1);
                glScalef(0.2,2,0.2);
                glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
                cube(1.0,1.0,1.0);
                glPopMatrix();
            }
            for(int i=0; i<lengthz; i+=2)
            {
                glPushMatrix();
                glTranslatef(lengthx-0.2,1+1,0.1+cube_unit+(i*cube_unit));
                glScalef(0.2,2,0.2);
                glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
                cube(1.0,1.0,1.0);
                glPopMatrix();
            }

            glPushMatrix();
            glTranslatef(-lengthx/2,0.1+1+1+0.75,0.1+1-0.2);
            glScalef(lengthx,0.2,0.2);
            glTranslatef(0.5,0.5,0.5);
            cube(1,1,1);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-0.5*cube_unit+lengthx+0.4,-0.20,0);
            glRotatef(270,0,1,0);
            glTranslatef(-lengthx/2+cube_unit,0.1+1+1+1,-0.1);
            glScalef(lengthx,0.2,0.2);
            glTranslatef(0.5,0.5,0.5);
            cube(1,1,1);
            glPopMatrix();
        }
        if(railing==4)
        {
            for(int i=0; i<lengthx; i+=2)
            {
                glPushMatrix();
                glTranslatef(0.1+(i*cube_unit),1+1,0.1+lengthz);
                glScalef(0.2,2,0.2);
                glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
                cube(1.0,1.0,1.0);
                glPopMatrix();
            }
            for(int i=0; i<lengthz; i+=2)
            {
                glPushMatrix();
                glTranslatef(0.1,1+1,0.1+(i*cube_unit));
                glScalef(0.2,2,0.2);
                glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
                cube(1.0,1.0,1.0);
                glPopMatrix();
            }

            glPushMatrix();
            glTranslatef(-lengthx/2,0.1+1+1+0.75,-0.1+lengthz);
            glScalef(lengthx,0.2,0.2);
            glTranslatef(0.5,0.5,0.5);
            cube(1,1,1);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(1.5*cube_unit,-0.25,-1);
            glRotatef(270,0,1,0);
            glTranslatef(-lengthx/2+cube_unit,0.1+1+1+1,0.1+1);
            glScalef(lengthx,0.2,0.2);
            glTranslatef(0.5,0.5,0.5);
            cube(1,1,1);
            glPopMatrix();
        }
        if(railing==5)
        {

            for(int i=0; i<lengthx; i+=2)
            {
                glPushMatrix();
                glTranslatef(0.1+cube_unit+(i*cube_unit),1+1,0.1+lengthz);
                glScalef(0.2,2,0.2);
                glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
                cube(1.0,1.0,1.0);
                glPopMatrix();
            }

            glPushMatrix();
            glTranslatef(-lengthx/2+cube_unit,0.1+1+1+0.75,-0.1+lengthz);
            glScalef(lengthx,0.2,0.2);
            glTranslatef(0.5,0.5,0.5);
            cube(1,1,1);
            glPopMatrix();
        }
        if(railing==6)
        {
            for(int i=0; i<lengthx; i+=2)
            {
                glPushMatrix();
                glTranslatef(0.1+cube_unit+(i*cube_unit),1+1,0.1+lengthz);
                glScalef(0.2,2,0.2);
                glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
                cube(1.0,1.0,1.0);
                glPopMatrix();
            }
            for(int i=0; i<lengthz; i+=2)
            {
                glPushMatrix();
                glTranslatef(lengthx-0.2,1+1,0.1+cube_unit+(i*cube_unit));
                glScalef(0.2,2,0.2);
                glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
                cube(1.0,1.0,1.0);
                glPopMatrix();
            }

            glPushMatrix();
            glTranslatef(-lengthx/2,0.1+1+1+0.75,0.1+lengthz-0.2);
            glScalef(lengthx,0.2,0.2);
            glTranslatef(0.5,0.5,0.5);
            cube(1,1,1);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-0.5*cube_unit+lengthx+0.4,-0.20,0);
            glRotatef(270,0,1,0);
            glTranslatef(-lengthx/2+cube_unit,0.1+1+1+1,-0.1);
            glScalef(lengthx,0.2,0.2);
            glTranslatef(0.5,0.5,0.5);
            cube(1,1,1);
            glPopMatrix();
        }
        if(stair[1])
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, tex[5]);
            face = 't';
            glPushMatrix();

            glTranslatef((roomX - stairHeight)/2/2, cube_unit/2, roomZ/2);
            glScalef((roomX - stairHeight)/2, 1, roomZ);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            c = 0;
            d = 0;
            a = ((roomX - stairHeight)/2)/roomX + c;
            b = cube_unit/(lengthy+cube_unit+cube_unit) + d;
            Cube(1.0,1.0,1.0,4*a,20*b,4*c,20*d,face);
            glPopMatrix();

            glPushMatrix();
            glTranslatef((roomX - stairHeight)/2/2 + roomX - (roomX - stairHeight)/2, cube_unit/2, (roomZ - stairWidth - stairWidth)/2 + stairWidth + stairWidth);
            glScalef((roomX - stairHeight)/2, 1, (roomZ - stairWidth - stairWidth));
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            c = ((roomX - stairHeight)/2 + stairHeight)/roomX;
            d = 0;
            a = stairHeight/roomX + c;
            b = cube_unit/(lengthy+cube_unit+cube_unit) + d;
            cube(1.0,1.0,1.0,4*a,20*b,4*c,20*d);
            glPopMatrix();

            glPushMatrix();
            glTranslated(stairHeight/2 + (roomX - stairHeight)/2, cube_unit/2, (roomZ - stairWidth - stairWidth)/2 + stairWidth + stairWidth);
            glScalef(stairHeight, 1, (roomZ - stairWidth - stairWidth));
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            c = ((roomX - stairHeight)/2)/roomX;
            d = 0;
            a = stairHeight/roomX + c;
            b = cube_unit/(lengthy+cube_unit+cube_unit) + d;
            cube(1.0,1.0,1.0,4*a,20*b,4*c,20*d);
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glTranslatef(roomX/2 - stairHeight/2, -roomY, 0);
            Stair(stairWidth, stairHeight);
            glPopMatrix();
        }
        else
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,tex[5]);
            glPushMatrix();
            glTranslatef(lengthx/2*cube_unit,0,(lengthz)/2*cube_unit);
            glScalef(lengthx,1,lengthz);
            glTranslatef(-1*cube_unit/2,0,-1*cube_unit/2);
            c = 0;
            d = 0;
            a = lengthx/lengthx + c;
            b = cube_unit/(lengthy+cube_unit+cube_unit) + d;
            cube(1.0,1.0,1.0,a*4,b*20,c*4,d*20);
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);
        }
    }


    if(!walls)
    {
        return;
    }

    if(sides[2])
    {
        float mult = 1;
        if(window[2])
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,tex[6]);
            glPushMatrix();
            glTranslatef(cube_unit*(lengthx-window[7])/4,lengthy/2*cube_unit+cube_unit,lengthz-cube_unit);
            glScalef((lengthx-window[7])/2,lengthy,1);
            glTranslatef(-1*cube_unit/2,-cube_unit/2,0.0*cube_unit/2);
            c = 0;
            d = 0;
            a = ((lengthx-window[7])/2)/lengthx + c;
            b = lengthy/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(lengthx-(lengthx-window[7])/4,lengthy/2*cube_unit+cube_unit,lengthz-cube_unit);
            glScalef((lengthx-window[7])/2,lengthy,1);
            glTranslatef(-1*cube_unit/2,-cube_unit/2,0.0*cube_unit/2);
            c = ((lengthx-window[7])/2 + window[7])/lengthx;
            d = 0;
            a = ((lengthx-window[7])/2)/lengthx + c;
            b = lengthy/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();
//            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glTranslatef(lengthx/2,(lengthy-window[6])/4+1*cube_unit,lengthz-cube_unit);
            glScalef(window[7],(lengthy-window[6])/2,1);
            glTranslatef(-1*cube_unit/2,-cube_unit/2,0.0*cube_unit/2);
            c = ((lengthx-window[7])/2)/lengthx;
            d = 0;
            a = (window[7])/lengthx + c;
            b = ((lengthy-window[6])/2)/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(lengthx/2,3*(lengthy-window[6])/4+window[6]+1,lengthz-cube_unit);
            glScalef(window[7],(lengthy-window[6])/2,1);
            glTranslatef(-1*cube_unit/2,-cube_unit/2,0.0*cube_unit/2);
            c = ((lengthx-window[7])/2)/lengthx;
            d = ((lengthy-window[6])/2 + window[6])/lengthy;
            a = window[7]/lengthx + c;
            b = ((lengthy-window[6])/2)/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glTranslatef((lengthx-window[7])/2,(lengthy-window[6])/2+cube_unit-0.05,lengthz-cube_unit);
            WindowXY(window[6], window[7], true);
            glPopMatrix();
        }
        else if(door[2])
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,tex[6]);
            glPushMatrix();
            glTranslatef((lengthx+door[7]+cube_unit)/2,lengthy/2+cube_unit,lengthz-cube_unit);
            glScalef(lengthx-door[7]-cube_unit,lengthy,1);
            glTranslatef(-1*cube_unit/2,-cube_unit/2,0.0*cube_unit/2);
            c = (cube_unit+door[7])/lengthx;
            d = 0;
            a = (lengthx-door[7]-cube_unit)/lengthx + c;
            b = (lengthy)/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(cube_unit/2,cube_unit+lengthy/2,lengthz-cube_unit);
            glScalef(1,lengthy,1);
            glTranslatef(-1*cube_unit/2,-cube_unit/2,0.0*cube_unit/2);
            c = 0;
            d = 0;
            a = 1/lengthx + c;
            b = (lengthy)/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glPushMatrix();
            glTranslatef((door[7])/2+cube_unit,(lengthy+door[6])/2+cube_unit,lengthz-cube_unit);
            glScalef(door[7],lengthy-door[6],1);
            glTranslatef(-1*cube_unit/2,-cube_unit/2,0.0*cube_unit/2);
            c = cube_unit/lengthx;
            d = door[6]/lengthy;
            a = door[7]/lengthx + c;
            b = (lengthy-door[6])/lengthy + d;
//            cout<<"A: "<<a<<" B: "<<b<<endl;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glTranslatef(cube_unit,cube_unit,lengthz+cube_unit/2-cube_unit);
            doorXY(door[6],door[7],false,true);
            glPopMatrix();
        }
        else
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,tex[6]);
            glPushMatrix();
            glTranslatef(cube_unit*lengthx/2,lengthy/2*cube_unit+cube_unit,lengthz-cube_unit);
            glScalef(lengthx,lengthy,1);
            glTranslatef(-1*cube_unit/2,-cube_unit/2,0.0*cube_unit/2);
            c = 0;
            d = 0;
            a = lengthx/lengthx + c;
            b = lengthy/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glDisable(GL_TEXTURE_2D);
        }
    }

    if(sides[3])
    {
        if(window[3])
        {
//            cout<<"window: "<<window<<endl;
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,tex[6]);
            glPushMatrix();
            glTranslatef(cube_unit*(lengthx-window[7])/4,lengthy/2*cube_unit+cube_unit,0);
            glScalef((lengthx-window[7])/2,lengthy,1);
            glTranslatef(-1*cube_unit/2,-cube_unit/2,0.0*cube_unit/2);
            c = 0;
            d = 0;
            a = ((lengthx-window[7])/2)/lengthx + c;
            b = lengthy/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(lengthx-(lengthx-window[7])/4,lengthy/2*cube_unit+cube_unit,0);
            glScalef((lengthx-window[7])/2,lengthy,1);
            glTranslatef(-1*cube_unit/2,-cube_unit/2,0.0*cube_unit/2);
            c = ((lengthx-window[7])/2 + window[7])/lengthx;
            d = 0;
            a = ((lengthx-window[7])/2)/lengthx + c;
            b = lengthy/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(lengthx/2,(lengthy-window[6])/4+1*cube_unit,0);
            glScalef(window[7],(lengthy-window[6])/2,1);
            glTranslatef(-1*cube_unit/2,-cube_unit/2,0.0*cube_unit/2);
            c = ((lengthx-window[7])/2)/lengthx;
            d = 0;
            a = (window[7])/lengthx + c;
            b = ((lengthy-window[6])/2)/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(lengthx/2,3*(lengthy-window[6])/4+window[6]+1,0);
            glScalef(window[7],(lengthy-window[6])/2,1);
            glTranslatef(-1*cube_unit/2,-cube_unit/2,0.0*cube_unit/2);
            c = ((lengthx-window[7])/2)/lengthx;
            d = ((lengthy-window[6])/2 + window[6])/lengthy;
            a = window[7]/lengthx + c;
            b = ((lengthy-window[6])/2)/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glTranslatef((lengthx-window[7])/2,(lengthy-window[6])/2+cube_unit-0.05,0);
            WindowXY(window[6], window[7], false);
            glPopMatrix();
        }
        else if(door[3])
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,tex[6]);
            glPushMatrix();
            glTranslatef((lengthx-door[7]-cube_unit)/2,lengthy/2+cube_unit,cube_unit/2);
            glScalef(lengthx-door[7]-cube_unit,lengthy,cube_unit);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            c = (cube_unit+door[7])/lengthx;
            d = 0;
            a = (lengthx-door[7]-cube_unit)/lengthx + c;
            b = (lengthy)/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(lengthx-cube_unit/2,lengthy/2+cube_unit,cube_unit/2);
            glScalef(cube_unit,lengthy,cube_unit);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            c = 0;
            d = 0;
            a = 1/lengthx + c;
            b = (lengthy)/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(lengthx-door[7]/2-cube_unit,(lengthy+door[6])/2+cube_unit,cube_unit/2);
            glScalef(door[7],lengthy-door[6],cube_unit);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            c = cube_unit/lengthx;
            d = door[6]/lengthy;
            a = door[7]/lengthx + c;
            b = (lengthy-door[6])/lengthy + d;
//            cout<<"A: "<<a<<" B: "<<b<<endl;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glTranslatef(lengthx-door[7]-cube_unit,cube_unit,0);
            doorXY(door[6],door[7],false,false);
            glPopMatrix();
        }
        else
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,tex[6]);
            glPushMatrix();
            glTranslatef(cube_unit*lengthx/2,lengthy/2*cube_unit+cube_unit,0);
            glScalef(lengthx,lengthy,1);
            glTranslatef(-1*cube_unit/2,-cube_unit/2,0.0*cube_unit/2);
            c = 0;
            d = 0;
            a = lengthx/lengthx + c;
            b = lengthy/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);
        }
    }

    if(sides[4])
    {
        if(window[4])
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,tex[6]);
            glPushMatrix();
            glTranslatef(cube_unit/2+lengthx-cube_unit,lengthy/2+cube_unit,(lengthz-window[7])/2/2);
            glScalef(1,lengthy,(lengthz-window[7])/2);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
//            c = (lengthz-(lengthz-window[5])/2)/lengthz;
//            d = 0;
//            a = (lengthz)/lengthz + c;
//            b = lengthy/lengthy + d;
            c = ((lengthz-window[7]-(lengthz-window[7])/2))/lengthz;
            d = 0;
            a = ((lengthz-window[7])/2)/lengthz + c;
            b = lengthy/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(cube_unit/2+lengthx-cube_unit,lengthy/2+cube_unit,(lengthz-window[7])/2/2+lengthz-(lengthz-window[7])/2);
            glScalef(1,lengthy,(lengthz-window[7])/2);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
//            c = 0;
//            d = 0;
//            a = ((lengthz-window[5])/2)/lengthz + c;
//            b = lengthy/lengthy + d;
            c = 0;
            d = 0;
            a = ((lengthz-window[7])/2)/lengthz + c;
            b = lengthy/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(cube_unit/2+lengthx-cube_unit,(lengthy-window[6])/2/2+cube_unit,window[7]/2+(lengthz-window[7])/2);
            glScalef(1,(lengthy-window[6])/2,window[7]);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            c = ((lengthz-window[7])/2)/lengthz;
            d = 0;
            a = (window[7])/lengthz + c;
            b = ((lengthy-window[6])/2)/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(cube_unit/2+lengthx-cube_unit,(lengthy-window[6])/2/2+cube_unit+lengthy-(lengthy-window[6])/2,window[7]/2+(lengthz-window[7])/2);
            glScalef(1,(lengthy-window[6])/2,window[7]);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            c = ((lengthz-window[7])/2)/lengthz;
            d = ((lengthy-window[6])/2 + window[6])/lengthy;
            a = window[7]/lengthz + c;
            b = ((lengthy-window[6])/2)/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glTranslatef(lengthx-cube_unit,(lengthy-window[6])/2+cube_unit,(lengthz-window[7])/2);
            WindowYZ(window[7],window[6],true);
            glPopMatrix();
        }
        else if(door[4])
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,tex[6]);
            glPushMatrix();
            glTranslatef(lengthx-cube_unit/2,lengthy/2+cube_unit,(lengthz-door[7]-cube_unit)/2);
            glScalef(1,lengthy,lengthz-door[7]-cube_unit);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            c = (cube_unit+door[7])/lengthx;
            d = 0;
            a = (lengthx-door[7]-cube_unit)/lengthx + c;
            b = (lengthy)/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(cube_unit/2+lengthx-cube_unit,(lengthy-door[6])/2+cube_unit+lengthy-(lengthy-door[6]),door[7]/2+lengthz-door[7]-cube_unit);
            glScalef(cube_unit,lengthy-door[6],door[7]);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            c = cube_unit/lengthx;
            d = door[6]/lengthy;
            a = door[7]/lengthx + c;
            b = (lengthy-door[6])/lengthy + d;
//            cout<<"A: "<<a<<" B: "<<b<<endl;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(cube_unit/2+lengthx-cube_unit,lengthy/2+cube_unit,cube_unit/2+lengthz-cube_unit);
            glScalef(1,lengthy,1);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            c = 0;
            d = 0;
            a = cube_unit/lengthz + c;
            b = lengthy/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
//            glTranslatef(lengthx-cube_unit/2,cube_unit,lengthz-door[5]/2-cube_unit/2);
            glTranslatef(lengthx-cube_unit/2,cube_unit,lengthz-door[7]-cube_unit);
            doorYZ(door[6],door[7],false,true);
            glPopMatrix();
        }
        else
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,tex[6]);
            glPushMatrix();
            glTranslatef(lengthx-cube_unit/2,cube_unit,lengthz/2*cube_unit);
            glScalef(1,lengthy,lengthz);
            glTranslatef(-1*cube_unit/2,0.0*cube_unit/2,-1*cube_unit/2);
            c = 0;
            d = 0;
            a = lengthx/lengthx + c;
            b = lengthy/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);
        }

    }

    if(sides[5])
    {
        if(window[5])
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,tex[6]);
            glPushMatrix();
            glTranslatef(cube_unit/2,lengthy/2+cube_unit,((lengthz-window[7])/2)/2);
            glScalef(1,lengthy,(lengthz-window[7])/2);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            c = 0;
            d = 0;
            a = ((lengthz-window[6])/2)/lengthz + c;
            b = lengthy/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(cube_unit/2,lengthy/2+cube_unit,((lengthz-window[7])/2)/2 + lengthz - (lengthz-window[7])/2);
            glScalef(1,lengthy,(lengthz-window[7])/2);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            c = ((lengthz-window[7])/2 + window[7])/lengthz + c;
            d = 0;
            a = ((lengthz-window[7])/2)/lengthz + c;
            b = lengthy/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(cube_unit/2,((lengthy-window[6])/2)/2 + cube_unit,window[7]/2 + (lengthz-window[7])/2);
            glScalef(1,(lengthy-window[6])/2,window[7]);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            c = ((lengthz-window[7])/2)/lengthz;
            d = 0;
            a = window[7]/lengthz + c;
            b = ((lengthy-window[6])/2)/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(cube_unit/2,((lengthy-window[6])/2)/2 + cube_unit + (lengthy-window[6])/2 + window[6],window[7]/2 + (lengthz-window[7])/2);
            glScalef(1,(lengthy-window[6])/2,window[7]);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            c = ((lengthz-window[7])/2)/lengthz;
            d = ((lengthy-window[6])/2 + window[6])/lengthy;
            a = window[7]/lengthz + c;
            b = ((lengthy-window[6])/2)/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glTranslatef(0,cube_unit + (lengthy-window[6])/2,(lengthz-window[6])/2);
            WindowYZ(window[6],window[7],false);
            glPopMatrix();
        }
        else if(door[5])
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,tex[6]);
            glPushMatrix();
            glTranslatef(cube_unit/2,lengthy/2+cube_unit,(lengthz+door[7]-cube_unit)/2+cube_unit);
            glScalef(cube_unit,lengthy,lengthz-door[7]-cube_unit);
            glTranslatef(-1*cube_unit/2,-1*cube_unit/2,-1*cube_unit/2);
            c = (cube_unit+door[7])/lengthz;
            d = 0;
            a = (lengthx-door[7]-cube_unit)/lengthz + c;
            b = (lengthy)/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(cube_unit/2,(lengthy+door[6])/2+cube_unit,door[7]/2+cube_unit);
            glScalef(cube_unit,lengthy-door[6],door[7]);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            c = cube_unit/lengthz;
            d = door[6]/lengthy;
            a = door[7]/lengthz + c;
            b = (lengthy-door[6])/lengthy + d;
//            cout<<"A: "<<a<<" B: "<<b<<endl;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(cube_unit/2,lengthy/2+cube_unit,cube_unit/2);
            glScalef(1,lengthy,1);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            c = 0;
            d = 0;
            a = cube_unit/lengthz + c;
            b = lengthy/lengthy + d;
            cube(1.0,1.0,1.0,a*4,b*2,c*4,d*2,alpha);
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glTranslatef(0,cube_unit,cube_unit);
            doorYZ(door[6],door[7],false, false);
            glPopMatrix();
        }
        else
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,tex[6]);
            glPushMatrix();
            glTranslatef(cube_unit/2,cube_unit,lengthz/2*cube_unit);
            glScalef(1,lengthy,lengthz);
            glTranslatef(-1*cube_unit/2,0.0*cube_unit/2,-1*cube_unit/2);
            c = 0;
            d = 0;
            a = lengthx/lengthx + c;
            b = lengthy/lengthy + d;
            cube(1.0,1.0,1.0,4*a,2*b,4*c,2*d,alpha);
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);
        }
    }
}

void Stair(float width, float height)
{
    float standy = 3*cube_unit;
    float standx = 0.2*cube_unit;
    float standz = 0.2*cube_unit;

    float railingx = sqrt(pow(height,2) + pow(height,2));
    float railingz = 0.2*cube_unit;
    float railingy = 0.2*cube_unit;

//    width /= 2;
//    height /= 2;
    float a,b,c,d;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[5]);
    glPushMatrix();
    glTranslatef((roomX - stairHeight-cube_unit)/2/2 + roomX - (roomX - stairHeight), cube_unit/2 + stairHeight, (stairWidth + stairWidth)/2);
    glScalef((roomX - stairHeight-cube_unit)/2,1,stairWidth + stairWidth);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    c = ((roomX - stairHeight)/2 + stairHeight)/roomX;
    d = 0;
    a = ((roomX - stairHeight)/2)/roomX + c;
    b = cube_unit/(roomY + cube_unit + cube_unit) + d;
    cube(1.0,1.0,1.0,4*a,20*b,4*c,20*d);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[17]);
    for(int i=0; i<(roomX - stairHeight)/2; i++)
    {
        glPushMatrix();
        glTranslatef(standx/2 + stairHeight + cube_unit/2 + i, (standy - cube_unit)/2 + stairHeight + cube_unit, standz/2 + cube_unit/2);
        glScalef(standx,standy - cube_unit,standz);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        cube(1.0,1.0,1.0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(standx/2 + stairHeight + cube_unit/2 + i, (standy + cube_unit)/2 + stairHeight + cube_unit, standz/2 + stairWidth + stairWidth - cube_unit/2);
        glScalef(standx,standy + cube_unit,standz);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        cube(1.0,1.0,1.0);
        glPopMatrix();
    }

    for(int i=0; i<2; i++)
    {
        glPushMatrix();
        if(i>0)
            glTranslatef(0, cube_unit + cube_unit, stairWidth + stairWidth -cube_unit);
        glTranslatef((roomX - stairHeight)/2/2 + stairHeight, railingy/2 + stairHeight + standy, railingz/2 + cube_unit/2);
        glScalef((roomX - stairHeight)/2,railingy,railingz);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        cube(1.0,1.0,1.0);
        glPopMatrix();
    }
    glDisable(GL_TEXTURE_2D);

    for(float i=0; i<height; i++)
    {
        glPushMatrix();
        glTranslatef(cube_unit/2 + i, cube_unit/2 + i, width/2);
        glScalef(1,1,width);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        cube(1.0,1.0,1.0);
        glPopMatrix();

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, tex[17]);
        for(float j = 0; j<2; j++)
        {
            glPushMatrix();
            if(j==0)
                glTranslatef(standx/2 + i + cube_unit/2,standy/2 + i + cube_unit,standz/2 + cube_unit/2);
            else
                glTranslatef(standx/2 + i + cube_unit/2,standy/2 + i + cube_unit,standz/2 + width - cube_unit/2);
            glScalef(standx,standy,standz);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            cube(1.0,1.0,1.0);
            glPopMatrix();
        }
        glDisable(GL_TEXTURE_2D);
    }

    for(float i = 2*height; i>height; i--)
    {
        glPushMatrix();
        glTranslatef(cube_unit/2 + (2*height - i),cube_unit/2 + i,width/2 + width);
        glScalef(1,1,width);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        cube(1.0,1.0,1.0);
        glPopMatrix();

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, tex[17]);
        for(float j = 0; j<2; j++)
        {
            glPushMatrix();
            if(j==0)
                glTranslatef(standx/2 + (2*height - i) + cube_unit/2, standy/2 + i + cube_unit, standz/2 + width + cube_unit/2);
            else
                glTranslatef(standx/2 + (2*height - i) + cube_unit/2, standy/2 + i + cube_unit,standz/2 + width + width - cube_unit/2);
            glScalef(standx,standy,standz);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            cube(1.0,1.0,1.0);
            glPopMatrix();
        }
        glDisable(GL_TEXTURE_2D);
    }

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[17]);
    for(int i=0; i<4; i++)
    {
        glPushMatrix();
        if(i==0)
            glTranslatef(0, 0, cube_unit/2);
        else if(i==1)
            glTranslatef(0, 0, cube_unit/2 + width - cube_unit);
        else if(i==2)
            glTranslatef(0, 0, cube_unit/2 + width);
        else if(i==3)
            glTranslatef(0, 0, cube_unit/2 + width + width - cube_unit);

        glTranslatef(cube_unit/2, cube_unit + standy, 0);

        if(i<2)
            glRotatef(45,0,0,1);
        else
        {
            glTranslatef(0, 2*height, 0);
            glRotatef(45,0,0,-1);
        }

        glTranslatef((railingx - cube_unit)/2,railingy/2,railingz/2);
        glScalef((railingx - cube_unit),railingy,railingz);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        cube(1.0,1.0,1.0);
        glPopMatrix();
    }
    glDisable(GL_TEXTURE_2D);
}

void Room(float lengthx, float lengthy, float lengthz,bool walls,
                 bool top, bool bottom, bool infront, bool behind, bool right, bool left,
                 float *window, float *door, float *stair,
                 int bed/*=-1*/, int tablechair/*=-1*/,int cabinet/*=-1*/,int diningTable,int bulb,int fan,int railing)
{
    bool sides[] = {top,bottom,infront,behind,right,left};

    Wall(lengthx, lengthy, lengthz, walls, sides, window, door, stair,1,railing);

    if(bed == 3)
    {
//        cout<<"bed: "<<bed<<endl;
        glPushMatrix();
        glTranslatef(bedX/2 + cube_unit + cube_unit,cube_unit,bedZ/2 + cube_unit + doorWidth + doorWidth);
//        glTranslatef(0,0,4);
//        glTranslatef(bedZ/2 + cube_unit + roomX/4,cube_unit,bedX/2 + cube_unit);
        glRotatef(180,0,1,0);
        glTranslatef(-bedX/2,0,-bedZ/2);
        Bed(0.2,2,0.5,1.0);
        glPopMatrix();
    }

    if(tablechair == 1)
    {
        glPushMatrix();
        glTranslatef(roomX/2 - tablechairX/2,cube_unit,roomZ - tablechairZ - cube_unit);
        TableChairRotate(180);
        TableChair();
        glPopMatrix();
    }
    else if(tablechair == 2)
    {
        glPushMatrix();
        glTranslatef(roomX/2 - tablechairX/2, cube_unit, cube_unit);
        TableChair();
        glPopMatrix();
    }
    else if(tablechair == 3)
    {
        glPushMatrix();
        glTranslatef(lengthx - tablechairZ - cube_unit, cube_unit, lengthz/2 - tablechairX/2);
        TableChairRotate(270);
        TableChair();
        glPopMatrix();
    }
    else if(tablechair == 4)
    {
        glPushMatrix();

        TableChair();
        glPopMatrix();
    }

    if(cabinet!=-1)
    {
        glPushMatrix();
        glTranslatef(roomX/2,cube_unit,cube_unit);
        Cabinet(true);
        glPopMatrix();
    }

    if(diningTable==1)
    {
        glPushMatrix();
        glTranslatef(roomX/2-diningTableX/2,cube_unit,roomZ/3-diningTableZ/2);
        DiningTableAndTools();
        glPopMatrix();
    }

    if(bulb==4)
    {
        glPushMatrix();
        glTranslatef(cube_unit,3*lengthy/4+3*cube_unit,lengthz/2);
        glScalef(0.2,0.2,0.2);
        bulbCurve();
        glPopMatrix();
    }

    if(bulb==3)
    {
        glPushMatrix();
        glTranslatef(lengthx-cube_unit,3*lengthy/4+3*cube_unit,lengthz/2);
        glRotatef(180,0,1,0);
        glScalef(0.2,0.2,0.2);
        bulbCurve();
        glPopMatrix();
    }

    if(fan==1)
    {
        glPushMatrix();
        glTranslatef(lengthx/2+cube_unit,lengthy-cube_unit/2,lengthz/2+cube_unit);
        CeilingFan();
        glPopMatrix();
    }
}

void OfficeRoom(float lengthx, float lengthy, float lengthz,bool walls,
                 bool top, bool bottom, bool infront, bool behind, bool right, bool left,
                 float *window, float *door, float *stair,
                 int deskchair/*=-1*/,int filingcabinet/*=-1*/,int employees,int head,int bulb,int bench,int fan,int railing)
{
    bool sides[] = {top,bottom,infront,behind,right,left};

    Wall(lengthx, lengthy, lengthz, walls, sides, window, door, stair,1.0,railing);

    if(deskchair == 1)
    {
        glPushMatrix();
        glTranslatef(lengthx/2-3*cube_unit,cube_unit,lengthz-11*cube_unit-cube_unit-cube_unit/2);
        DeskAndChair(90);
        glPopMatrix();
    }

    else if(deskchair == 2)
    {
        glPushMatrix();
        glTranslatef(roomX/2 - tablechairX/2, cube_unit, cube_unit);
        DeskAndChair();
        glPopMatrix();
    }

    else if(deskchair == 3)
    {
        glPushMatrix();
        glTranslatef(lengthx - tablechairZ - cube_unit, cube_unit, lengthz/2 - tablechairX/2);
        TableChairRotate(270);
        DeskAndChair();
        glPopMatrix();
    }

    else if(deskchair == 4)
    {
        glPushMatrix();

        TableChair();
        glPopMatrix();
    }

    if(filingcabinet==2)
    {
        glPushMatrix();
        glTranslatef(cube_unit+cube_unit,cube_unit,cube_unit);
        FilingCabinet(3,4);
        glPopMatrix();
    }

    if(filingcabinet==3)
    {
        glPushMatrix();
        glTranslatef(lengthx-filingCabinetUnitz-cube_unit,cube_unit,lengthz-4*filingCabinetUnitx-cube_unit);
        FilingCabinet(4,4,270);
        glPopMatrix();
    }

    if(filingcabinet==1)
    {
        glPushMatrix();
        glTranslatef(lengthx-4*filingCabinetUnitx-cube_unit,cube_unit,lengthz-filingCabinetUnitz-cube_unit);
        FilingCabinet(4,4,180);
        glPopMatrix();
    }

    if(employees==1)
    {
        glPushMatrix();
        glTranslatef(cube_unit,cube_unit,cube_unit+cube_unit/2);
        EmployeeTableChair(270);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(cube_unit+EmployeeTableChairX,cube_unit,cube_unit+cube_unit/2);
        EmployeeTableChair(90);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(cube_unit,cube_unit,cube_unit+lengthz-EmployeeTableChairX-cube_unit-cube_unit);
        EmployeeTableChair(270);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(cube_unit+EmployeeTableChairX,cube_unit,cube_unit+lengthz-EmployeeTableChairX-cube_unit-cube_unit);
        EmployeeTableChair(90);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(lengthx-EmployeeTableChairX-cube_unit,cube_unit,cube_unit+cube_unit);
        EmployeeTableChair(0);
        glPopMatrix();
    }

    if(employees==2)
    {
        glPushMatrix();
        glTranslatef(lengthx-EmployeeTableChairX-cube_unit,cube_unit,cube_unit+cube_unit);
        EmployeeTableChair(0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(lengthx/3-EmployeeTableChairX-cube_unit,cube_unit,cube_unit+cube_unit);
        EmployeeTableChair(0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(lengthx-EmployeeTableChairX-3*cube_unit,cube_unit,2*lengthz/3-5*cube_unit);
        EmployeeTableChair(270);
        glPopMatrix();
    }

    if(employees==3)
    {

        glPushMatrix();
        glTranslatef(lengthx/3-EmployeeTableChairX-cube_unit,cube_unit,cube_unit+cube_unit);
        EmployeeTableChair(0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(lengthx-EmployeeTableChairX-3*cube_unit,cube_unit,cube_unit+cube_unit);
        EmployeeTableChair(270);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(lengthx/3-EmployeeTableChairX+2*cube_unit,cube_unit,lengthz-EmployeeTableChairZ-cube_unit*2);
        EmployeeTableChair(180);
        glPopMatrix();
    }

    if(head==1)
    {
        glPushMatrix();
        glTranslatef(cube_unit+lengthx/2-HeadTableX/2,cube_unit,2*lengthz/3);
        HeadTableChair();
        glPopMatrix();
    }

    if(bulb==4)
    {
        glPushMatrix();
        glTranslatef(cube_unit,3*lengthy/4+3*cube_unit,lengthz/2);
        glScalef(0.2,0.2,0.2);
        bulbCurve();
        glPopMatrix();
    }

    if(bulb==3)
    {
        glPushMatrix();
        glTranslatef(lengthx-cube_unit,3*lengthy/4+3*cube_unit,lengthz/2);
        glRotatef(180,0,1,0);
        glScalef(0.2,0.2,0.2);
        bulbCurve();
        glPopMatrix();
    }

    if(bulb==2)
    {
        glPushMatrix();
        glTranslatef(lengthx/2,3*lengthy/4+3*cube_unit,cube_unit);
        glRotatef(270,0,1,0);
        glScalef(0.2,0.2,0.2);
        bulbCurve();
        glPopMatrix();
    }

    if(bench==1)
    {
        glPushMatrix();
        glTranslatef(lengthx-cube_unit-parkBenchx,cube_unit,lengthz/2);
        ParkBenchPair();
        glPopMatrix();
    }

    if(fan==1)
    {
        glPushMatrix();
        glTranslatef(lengthx/2-cube_unit,lengthy-cube_unit/2,lengthz/2-cube_unit);
        CeilingFan();
        glPopMatrix();
    }

}

void Floor(bool top/*=true*/, bool bottom/*=true*/, bool walls/*=true*/, float stairBottom/*=0*/)
{

    //top,  bottom,        infront,   behind, right, left,      height,        width
    float window[]= {0,      0,             0,          0,      1,    1,    grillHeight,   grillWidth};
    float door[] = {0,      0,             1,          1,      0,    0,    doorHeight,     doorWidth};
    float stair[]= {0,  stairBottom,       0,          0,      0,    0,    stairHeight,   stairWidth};
    //top, bottom, infront, behind, right, left
    window[2] = 0;
    window[3] = 1;
    window[4] = 0;
    window[5] = 1;
    door[2] = 0;
    door[3] = 0;
    door[4] = 0;
    door[5] = 0;
    stair[1] = 0;
    glPushMatrix();
    Room(roomX,roomY,roomZ,walls,top,  bottom,    false,   true,   false, true,window,door,stair,3,3,1,0,4,1);
    glPopMatrix();

    window[2] = 0;
    window[3] = 1;
    window[4] = 0;
    window[5] = 0;
    door[2] = 0;
    door[3] = 0;
    door[4] = 1;
    door[5] = 1;
    stair[1] = 0;
    glPushMatrix();
    glTranslatef(roomX,0,0);
    Room(roomX,roomY,roomZ,walls,top,  bottom,    true,   true,   true, true,window,door,stair,-1,-1,-1,1,4,1);
    glPopMatrix();

    window[2] = 0;
    window[3] = 1;
    window[4] = 1;
    window[5] = 0;
    door[2] = 0;
    door[3] = 0;
    door[4] = 0;
    door[5] = 0;
    stair[1] = 0;
    glPushMatrix();
    glTranslatef(roomX+roomX,0,0);
    Room(roomX,roomY,roomZ,walls,top,  bottom,    false,   true,   true, false,window,door,stair,3,1,1,-1,3,1);
    glPopMatrix();

    window[2] = 1;
    window[3] = 0;
    window[4] = 0;
    window[5] = 1;
    door[2] = 0;
    door[3] = 1;
    door[4] = 1;
    door[5] = 0;
    stair[1] = 0;
    glPushMatrix();
    glTranslatef(0,0,roomZ);
    Room(roomX,roomY,roomZ,walls,top,  bottom,    true,   true,   true, true,window,door,stair,-1,1,1,-1,4,1);
    glPopMatrix();

    window[2] = 0;
    window[3] = 0;
    window[4] = 0;
    window[5] = 0;
    door[2] = 0;
    door[3] = 0;
    door[4] = 1;
    door[5] = 0;
    stair[1] = stairBottom;
    glPushMatrix();
    glTranslatef(roomX,0,roomZ);
    Room(roomX,roomY,roomZ,walls,top,  bottom,    false,   false,   true, false,window,door,stair,-1,-1,-1,-1,3,-1);
    glPopMatrix();


    window[2] = 1;
    window[3] = 0;
    window[4] = 1;
    window[5] = 0;
    door[2] = 0;
    door[3] = 1;
    door[4] = 0;
    door[5] = 0;
    stair[1] = 0;

    glPushMatrix();
    glTranslatef(roomX + roomX,0,roomZ);
    Room(roomX,roomY,roomZ,walls,top,  bottom,    true,   true,   true, false,window,door,stair,3,1,1,-1,3,1);
    glPopMatrix();
}

void Floor2(bool top/*=true*/, bool bottom/*=true*/, bool walls/*=true*/, float stairBottom/*=0*/)
{

    //top,  bottom,        infront,   behind, right, left,      height,        width
    float window[]= {0,      0,             0,          0,      1,    1,    grillHeight,   grillWidth};
    float door[] = {0,      0,             1,          1,      0,    0,    doorHeight,     doorWidth};
    float stair[]= {0,  stairBottom,       0,          0,      0,    0,    stairHeight,   stairWidth};
    //top, bottom, infront, behind, right, left
    window[2] = 0;
    window[3] = 1;
    window[4] = 0;
    window[5] = 1;
    door[2] = 0;
    door[3] = 0;
    door[4] = 0;
    door[5] = 0;
    stair[1] = 0;
    glPushMatrix();
    Room(roomX,roomY,roomZ,walls,top,  bottom,    false,   true,   false, true,window,door,stair,-1,-1,-1,-1,-1,-1,1);
    glPopMatrix();

    window[2] = 0;
    window[3] = 1;
    window[4] = 0;
    window[5] = 0;
    door[2] = 0;
    door[3] = 0;
    door[4] = 1;
    door[5] = 1;
    stair[1] = 0;
    glPushMatrix();
    glTranslatef(roomX,0,0);
    Room(roomX,roomY,roomZ,walls,top,  bottom,    true,   true,   true, true,window,door,stair,-1,-1,-1,-1,-1,-1,2);
    glPopMatrix();

    window[2] = 0;
    window[3] = 1;
    window[4] = 1;
    window[5] = 0;
    door[2] = 0;
    door[3] = 0;
    door[4] = 0;
    door[5] = 0;
    stair[1] = 0;
    glPushMatrix();
    glTranslatef(roomX+roomX,0,0);
    Room(roomX,roomY,roomZ,walls,top,  bottom,    false,   true,   true, false,window,door,stair,-1,-1,-1,-1,-1,-1,3);
    glPopMatrix();

    window[2] = 1;
    window[3] = 0;
    window[4] = 0;
    window[5] = 1;
    door[2] = 0;
    door[3] = 1;
    door[4] = 1;
    door[5] = 0;
    stair[1] = 0;
    glPushMatrix();
    glTranslatef(0,0,roomZ);
    Room(roomX,roomY,roomZ,walls,top,  bottom,    true,   true,   true, true,window,door,stair,-1,-1,-1,-1,-1,-1,4);
    glPopMatrix();

    window[2] = 0;
    window[3] = 0;
    window[4] = 0;
    window[5] = 0;
    door[2] = 0;
    door[3] = 0;
    door[4] = 1;
    door[5] = 0;
    stair[1] = stairBottom;
    glPushMatrix();
    glTranslatef(roomX,0,roomZ);
    Room(roomX,roomY,roomZ,walls,top,  bottom,    false,   false,   true, false,window,door,stair,-1,-1,-1,-1,-1,-1,5);
    glPopMatrix();


    window[2] = 1;
    window[3] = 0;
    window[4] = 1;
    window[5] = 0;
    door[2] = 0;
    door[3] = 1;
    door[4] = 0;
    door[5] = 0;
    stair[1] = 0;

    glPushMatrix();
    glTranslatef(roomX + roomX,0,roomZ);
    Room(roomX,roomY,roomZ,walls,top,  bottom,    true,   true,   true, false,window,door,stair,-1,-1,-1,-1,-1,-1,6);
    glPopMatrix();
}

void OfficeFloor(bool top/*=true*/, bool bottom/*=true*/, bool walls/*=true*/, float stairBottom/*=0*/)
{

    //top,  bottom,        infront,   behind, right, left,      height,        width
    float window[]= {0,      0,             0,          0,      1,    1,    grillHeight,   grillWidth};
    float door[] = {0,      0,             1,          1,      0,    0,    doorHeight,     doorWidth};
    float stair[]= {0,  stairBottom,       0,          0,      0,    0,    stairHeight,   stairWidth};
    //top, bottom, infront, behind, right, left
    window[2] = 0;
    window[3] = 1;
    window[4] = 0;
    window[5] = 1;
    door[2] = 1;
    door[3] = 0;
    door[4] = 0;
    door[5] = 0;
    stair[1] = 0;
    glPushMatrix();
    OfficeRoom(roomX,roomY,roomZ,walls,top,  bottom,    true,   true,   false, true,window,door,stair,1,1,-1,-1,4,-1,1);
    glPopMatrix();

    window[2] = 0;
    window[3] = 1;
    window[4] = 0;
    window[5] = 0;
    door[2] = 0;
    door[3] = 0;
    door[4] = 0;
    door[5] = 0;
    stair[1] = 0;
    glPushMatrix();
    glTranslatef(roomX,0,0);
    OfficeRoom(roomX,roomY,roomZ,walls,top,  bottom,    false,   true,   false, false,window,door,stair,-1,-1,1,-1,2,-1,1);
    glPopMatrix();

    window[2] = 0;
    window[3] = 1;
    window[4] = 1;
    window[5] = 0;
    door[2] = 0;
    door[3] = 0;
    door[4] = 0;
    door[5] = 0;
    stair[1] = 0;
    glPushMatrix();
    glTranslatef(roomX+roomX,0,0);
    OfficeRoom(roomX,roomY,roomZ,walls,top,  bottom,    false,   true,   true, false,window,door,stair,-1,-1,3,-1,3,-1,1);
    glPopMatrix();

    window[2] = 1;
    window[3] = 0;
    window[4] = 0;
    window[5] = 0;
    door[2] = 0;
    door[3] = 0;
    door[4] = 0;
    door[5] = 0;
    stair[1] = stairBottom;
    glPushMatrix();
    glTranslatef(0,0,roomZ);
    OfficeRoom(roomX,roomY,roomZ,walls,top,  bottom,    false,   false,   false, true,window,door,stair,-1,-1,-1,-1,-1,1,-1);
    glPopMatrix();

    window[2] = 1;
    window[3] = 0;
    window[4] = 0;
    window[5] = 0;
    door[2] = 0;
    door[3] = 1;
    door[4] = 1;
    door[5] = 0;
    stair[1] = 0;
    glPushMatrix();
    glTranslatef(roomX,0,roomZ);
    OfficeRoom(roomX,roomY,roomZ,walls,top,  bottom,    true,   true,   true, true,window,door,stair,-1,-1,-1,1,4,-1,1);
    glPopMatrix();


    window[2] = 1;
    window[3] = 0;
    window[4] = 1;
    window[5] = 0;
    door[2] = 0;
    door[3] = 1;
    door[4] = 0;
    door[5] = 0;
    stair[1] = 0;

    glPushMatrix();
    glTranslatef(roomX + roomX,0,roomZ);
    OfficeRoom(roomX,roomY,roomZ,walls,top,  bottom,    true,   true,   true, false,window,door,stair,-1,-1,-1,-1,3,-1,1);
    glPopMatrix();
}

void OfficeFloor2(bool top/*=true*/, bool bottom/*=true*/, bool walls/*=true*/, float stairBottom/*=0*/)
{

    //top,  bottom,        infront,   behind, right, left,      height,        width
    float window[]= {0,      0,             0,          0,      1,    1,    grillHeight,   grillWidth};
    float door[] = {0,      0,             1,          1,      0,    0,    doorHeight,     doorWidth};
    float stair[]= {0,  stairBottom,       0,          0,      0,    0,    stairHeight,   stairWidth};
    //top, bottom, infront, behind, right, left
    window[2] = 0;
    window[3] = 1;
    window[4] = 0;
    window[5] = 1;
    door[2] = 1;
    door[3] = 0;
    door[4] = 0;
    door[5] = 0;
    stair[1] = 0;
    glPushMatrix();
    OfficeRoom(roomX,roomY,roomZ,walls,top,  bottom,    true,   true,   false, true,window,door,stair,-1,-1,-1,-1,-4,-1,-1,1);
    glPopMatrix();

    window[2] = 0;
    window[3] = 1;
    window[4] = 0;
    window[5] = 0;
    door[2] = 0;
    door[3] = 0;
    door[4] = 0;
    door[5] = 0;
    stair[1] = 0;
    glPushMatrix();
    glTranslatef(roomX,0,0);
    OfficeRoom(roomX,roomY,roomZ,walls,top,  bottom,    false,   true,   false, false,window,door,stair,-1,-1,-1,-1,-4,-1,-1,2);
    glPopMatrix();

    window[2] = 0;
    window[3] = 1;
    window[4] = 1;
    window[5] = 0;
    door[2] = 0;
    door[3] = 0;
    door[4] = 0;
    door[5] = 0;
    stair[1] = 0;
    glPushMatrix();
    glTranslatef(roomX+roomX,0,0);
    OfficeRoom(roomX,roomY,roomZ,walls,top,  bottom,    false,   true,   true, false,window,door,stair,-1,-1,-1,-1,-4,-1,-1,3);
    glPopMatrix();

    window[2] = 1;
    window[3] = 0;
    window[4] = 0;
    window[5] = 1;
    door[2] = 0;
    door[3] = 0;
    door[4] = 0;
    door[5] = 0;
    stair[1] = stairBottom;
    glPushMatrix();
    glTranslatef(0,0,roomZ);
    OfficeRoom(roomX,roomY,roomZ,walls,top,  bottom,    false,   false,   false, false,window,door,stair,-1,-1,-1,-1,-4,-1,-1,4);
    glPopMatrix();

    window[2] = 1;
    window[3] = 0;
    window[4] = 0;
    window[5] = 0;
    door[2] = 0;
    door[3] = 1;
    door[4] = 1;
    door[5] = 0;
    stair[1] = 0;
    glPushMatrix();
    glTranslatef(roomX,0,roomZ);
    OfficeRoom(roomX,roomY,roomZ,walls,top,  bottom,    true,   true,   true, true,window,door,stair,-1,-1,-1,-1,-4,-1,-1,5);
    glPopMatrix();


    window[2] = 1;
    window[3] = 0;
    window[4] = 1;
    window[5] = 0;
    door[2] = 0;
    door[3] = 1;
    door[4] = 0;
    door[5] = 0;
    stair[1] = 0;

    glPushMatrix();
    glTranslatef(roomX + roomX,0,roomZ);
    OfficeRoom(roomX,roomY,roomZ,walls,top,  bottom,    true,   true,   true, false,window,door,stair,-1,-1,-1,-1,-4,-1,-1,6);
    glPopMatrix();
}


