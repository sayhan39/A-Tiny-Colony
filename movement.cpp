#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <bits/stdc++.h>

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

extern float eyex;
extern float eyey;
extern float eyez;
extern float lookAtx;
extern float lookAty;
extern float lookAtz;

extern bool keyStates[];

float ang = 0;

float getAng()
{
    return ang;
}

float angle = 0;

float getAngle()
{
    return angle;
}

void Angle()
{
    float lx,lz,ex,ez;

    float converter = 180/M_PI;

//    if(lookAtx == eyex && lookAtz < eyez)
//        cout<<"Angle: "<<90<<endl;
//    else
//        cout<<"Angle: "<<(atan((lookAtz - eyez)/(lookAtx - eyex)))*converter<<endl;
    if(lookAtx > eyex && lookAtz > eyez)
    {
//        cout<<1<<endl;
        ang = (atan((lookAtz - eyez)/(lookAtx - eyex)))*converter;
    }
    else if(lookAtx < eyex && lookAtz > eyez)
    {
//        cout<<2<<endl;
        ang = 180 + (atan((lookAtz - eyez)/(lookAtx - eyex)))*converter;
    }
    else if(lookAtx < eyex && lookAtz < eyez)
    {
//        cout<<3<<endl;
        ang = 180 + (atan((lookAtz - eyez)/(lookAtx - eyex)))*converter;
    }
    else if(lookAtx > eyex && lookAtz < eyez)
    {
        ang = 360 + (atan((lookAtz - eyez)/(lookAtx - eyex)))*converter;
    }
    else if(lookAtx == eyex && lookAtz < eyez)
    {
        ang = 270;
    }
    else if(lookAtx > eyex && lookAtz == eyez)
    {
        ang = 0;
    }
    else if(lookAtx == eyex && lookAtz > eyez)
    {
        ang = 90;
    }
    else if(lookAtx < eyex && lookAtz == eyez)
    {
        ang = 180;
    }
//    cout<<"Angle: "<<ang<<endl;
//    if(lookAtx > eyex && lookAtz < eyez)
//    {
//
//    }
}

void AngleReverse()
{
    float converter = 180/M_PI;

    if(eyex > lookAtx && eyez > lookAtz)
    {
        angle = (atan((eyez - lookAtz)/(eyex - lookAtx)))*converter;
    }
    else if(eyex < lookAtx && eyez > lookAtz)
    {
        angle = 180 + (atan((eyez - lookAtz)/(eyex - lookAtx)))*converter;
    }
    else if(eyex < lookAtx && eyez < lookAtz)
    {
        angle = 180 + (atan((eyez - lookAtz)/(eyex - lookAtx)))*converter;
    }
    else if(eyex > lookAtx && eyez < lookAtz)
    {
        angle = 360 + (atan((eyez - lookAtz)/(eyex - lookAtx)))*converter;
    }
    else if(eyex > lookAtx && eyez == lookAtz)
    {
        angle = 0;
    }
    else if(eyex == lookAtx && eyez > lookAtz)
    {
        angle = 90;
    }
    else if(eyex < lookAtx && eyez == lookAtz)
    {
        angle = 180;
    }
    else if(eyex == lookAtx && eyez < lookAtz)
    {
        angle = 270;
    }
//    cout<<"Reverse Angle: "<<angle<<endl;
}

void rotateLookAtPointXZ(bool x, bool y, bool z, float unit)
{

//    cout<<"rotateLookAtPointXZ"<<endl;
//    cout<<"lookAt position: "<<lookAtx<<", "<<lookAty<<", "<<lookAtz<<endl;

//    cout<<"atan value: "<<atan(lookAtz/lookAtx)<<endl;
//    cout<<"before"<<endl<<"eyex : "<<eyex<<" eyez : "<<eyez<<endl;
//    cout<<"lookAtx : "<<lookAtx<<" lookAtz : "<<lookAtz<<endl<<"angle: "<<ang<<endl<<"after"<<endl;

    float radious = sqrt(pow((eyex-lookAtx),2)+pow((eyez-lookAtz),2));
//    cout<<"radious: "<<radious<<endl;

//    setAngle();

//    float unit = 1.5;

    Angle();
//    cout<<"Angle Before: "<<ang<<"'"<<endl;

//        cout<<"incresing angle"<<endl;

//        cout<<"angle: "<<ang<<endl;

//        cout<<"decresing angle"<<endl;
    ang+=unit;
    angle+=unit;
    /*ang+=unit;
    angle+=unit;*/

    if(ang>=360)
        ang=0;
    if(ang<0)
        ang=359;

    if(angle>=360)
        angle=0;
    if(angle<0)
        angle=359;

//    cout<<"angle: "<<ang<<endl;

//    lookAtx = eyex - radious*cos(M_PI*ang/180);
//    lookAtz = eyez - radious*sin(M_PI*ang/180);

    if(lookAtx >= eyex && lookAtz > eyez)
    {
//        cout<<"right-back"<<endl;
//        cout<<"radious*cos(M_PI*(ang)/180): "<<radious*cos(M_PI*(ang)/180)<<endl;
//        cout<<"eyex: "<<eyex<<endl;
        lookAtx = eyex + radious*cos(M_PI*(ang)/180);
//        lookAtx = /**eyex - **/radious*cos(M_PI*(ang)/180);
        lookAtz = eyez + radious*sin(M_PI*(ang)/180);
//        cout<<"Real angle: "<<ang<<endl;
//        cout<<"lx: "<<lookAtx<<"    lz: "<<lookAtz<<endl;
//        cout<<"ex: "<<eyex<<"    ez: "<<eyez<<endl;
    }

    else if(lookAtx > eyex && lookAtz <= eyez)
    {
//        cout<<"right-front"<<endl;
        lookAtx = eyex + radious*cos(M_PI*(360 - ang)/180);
        lookAtz = eyez - radious*sin(M_PI*(360 - ang)/180);
//        cout<<"lx: "<<lookAtx<<"    lz: "<<lookAtz<<endl;
//        cout<<"ex: "<<eyex<<"    ez: "<<eyez<<endl;
    }
    else if(lookAtx < eyex && lookAtz >= eyez)
    {
//        cout<<"left-back"<<endl;
        //ang += 180;
        lookAtx = eyex - radious*cos(M_PI*(180 - ang)/180);
        lookAtz = eyez + radious*sin(M_PI*(180 - ang)/180);
//        cout<<"lx: "<<lookAtx<<"    lz: "<<lookAtz<<endl;
//        cout<<"ex: "<<eyex<<"    ez: "<<eyez<<endl;
    }
    else if(lookAtx <= eyex && lookAtz < eyez)
    {
//        cout<<"left-front"<<endl;
        //ang += 180;
        lookAtx = eyex + radious*sin(M_PI*(ang - 270)/180);
        lookAtz = eyez - radious*cos(M_PI*(ang - 270)/180);
//        cout<<"lx: "<<lookAtx<<"    lz: "<<lookAtz<<endl;
//        cout<<"ex: "<<eyex<<"    ez: "<<eyez<<endl;
    }
//    cout<<"eyex : "<<eyex<<" eyez : "<<eyez<<endl;
//    cout<<"lookAtx : "<<lookAtx<<" lookAtz : "<<lookAtz<<endl<<endl;

//    Angle();
//    cout<<"Angle after: "<<ang<<"'"<<endl;
}


void rotateEyeXZ(bool x, bool y, bool z, float unit)
{

//    cout<<"atan value: "<<atan(lookAtz/lookAtx)<<endl;
//    cout<<"before"<<endl<<"eyex : "<<eyex<<" eyez : "<<eyez<<endl;
//    cout<<"lookAtx : "<<lookAtx<<" lookAtz : "<<lookAtz<<endl<<"angle: "<<ang<<endl<<"after"<<endl;

    float radious = sqrt(pow((eyex-lookAtx),2)+pow((eyez-lookAtz),2));
//    cout<<"radious: "<<radious<<endl;

    AngleReverse();
//    cout<<"Reverse Angle Before: "<<angle<<endl;

    if(keyStates['1'])
    {
        angle++;
    }
    else if(keyStates['3'])
    {
        angle--;
    }

//    angle += unit;

    if(angle>=360)
        angle=0;
    if(angle<0)
        angle=359;

//    cout<<"angle: "<<ang<<endl;

//    lookAtx = eyex - radious*cos(M_PI*ang/180);
//    lookAtz = eyez - radious*sin(M_PI*ang/180);

    if(eyex >= lookAtx && eyez > lookAtz)
    {
//        cout<<"right-back"<<endl;
        eyex = lookAtx + radious*cos(M_PI*angle/180);
        eyez = lookAtz + radious*sin(M_PI*angle/180);
    }

    else if(eyex > lookAtx && eyez <= lookAtz)
    {
//        cout<<"right-front"<<endl;
        eyex = lookAtx + radious*cos(M_PI*(360 - angle)/180);
        eyez = lookAtz - radious*sin(M_PI*(360 - angle)/180);
    }
    else if(eyex < lookAtx && eyez >= lookAtz)
    {
//        cout<<"left-back"<<endl;
        //ang += 180;
        eyex = lookAtx - radious*cos(M_PI*(180 - angle)/180);
        eyez = lookAtz + radious*sin(M_PI*(180 - angle)/180);
    }
    else if(eyex <= lookAtx && eyez < lookAtz)
    {
//        cout<<"left-front"<<endl;
        //ang += 180;
        eyex = lookAtx + radious*sin(M_PI*(angle - 270)/180);
        eyez = lookAtz - radious*cos(M_PI*(angle - 270)/180);
    }
    AngleReverse();
//    cout<<"eyex : "<<eyex<<" eyez : "<<eyez<<endl;
//    cout<<"lookAtx : "<<lookAtx<<" lookAtz : "<<lookAtz<<endl<<endl;
//    cout<<"Reverse Angle after: "<<angle<<endl;
}


void walkStraightXZ(bool infront /*= true*/)
{
    if(eyex == lookAtx)
    {
        if((eyez>lookAtz && infront) || (eyez<lookAtz && !infront))
        {
            eyez--;
            lookAtz--;
        }
        else if((eyez<lookAtz && infront) || (eyez>lookAtz && !infront))
        {
            eyez++;
            lookAtz++;
        }
    }
    else if(eyez == lookAtz)
    {
        if((eyex>lookAtx && infront) || (eyex<lookAtx && !infront))
        {
            eyex--;
            lookAtx--;
        }
        else if((eyex<lookAtx && infront) || (eyex>lookAtx && !infront))
        {
            eyex++;
            lookAtx++;
        }
    }
    else if(eyex != lookAtx && eyez != lookAtz)
    {
        float cx = (eyex*lookAtz-lookAtx*eyez)/(eyex-lookAtx);
        float cz = (eyez*lookAtx-eyex*lookAtz)/(eyez-lookAtz);
//        cout<<"c: "<<cx<<endl;
        float mx = (eyez-lookAtz)/(eyex-lookAtx);
        float mz = (eyex-lookAtx)/(eyez-lookAtz);
//        cout<<"m: "<<mx<<endl;

        float dellX = sqrt(pow((eyex-lookAtx),2));
        float dellZ = sqrt(pow((eyez-lookAtz),2));

        if(dellX>dellZ)
        {
            if((infront && eyex < lookAtx) || (!infront && eyex > lookAtx))
            {
                eyex++;
                lookAtx++;
            }
            else if((infront && eyex > lookAtx) || (!infront && eyex < lookAtx))
            {
                eyex--;
                lookAtx--;
            }
            eyez = mx*eyex+cx;
            lookAtz = mx*lookAtx+cx;
        }
        else if(dellZ>dellX)
        {
            if((infront && eyez < lookAtz) || (!infront && eyez > lookAtz))
            {
                eyez++;
                lookAtz++;
            }
            else if((infront && eyez > lookAtz) || (!infront && eyez < lookAtz))
            {
                eyez--;
                lookAtz--;
            }
            eyex = mz*eyez+cz;
            lookAtx = mz*lookAtz+cz;
        }
    }
//    cout<<"eyex: "<<eyex<<" eyez: "<<eyez<<endl;
//    cout<<"lookAtx: "<<lookAtx<<" lookAtz: "<<lookAtz<<endl;
}

int pastMousex=0, pastMousey=0;
bool mouse=false;

void passiveMouseMovement(int x, int y)
{
    if(!mouse)
    {
        pastMousex = x;
//        cout<<"pastMousex: "<<pastMousex<<endl;
        pastMousey = y;
        mouse=true;
    }
    else
        mouse=false;
    if(x > pastMousex)
    {
//        cout<<"passiveMouseMovement"<<endl;
        if(mouseMovement)
            keyStates['6'] = true;
//        rotateLookAtPointXZ(true, true, true, 1.5);
    }

    if(x < pastMousex)
    {
//        cout<<"passiveMouseMovement"<<endl;
        if(mouseMovement)
            keyStates['4'] = true;
//        rotateLookAtPointXZ(true, true, true, -1.5);
    }
}

float oldEyex=eyex,oldEyey=eyey,oldEyez=eyez,oldLookAtx=lookAtx,oldLookAty=lookAty,oldLookAtz=lookAtz;
void TopView()
{
    oldEyex=eyex;
    oldEyey=eyey;
    oldEyez=eyez;
    oldLookAtx=lookAtx;
    oldLookAty=lookAty;
    oldLookAtz=lookAtz;
    eyex = 0;
    eyey = 50;
    eyez = 300;
    lookAtx = 0;
    lookAty = 25;
    lookAtz = 50;
}

void MiddleView()
{
    eyex = 0;
    eyey = 5;
    eyez = 20;

    lookAtx = 0;
    lookAty = 5;
    lookAtz = 0;
}

void OldView()
{
    eyex=oldEyex;
    eyey=oldEyey;
    eyez=oldEyez;

    lookAtx=oldLookAtx;
    lookAty=oldLookAty;
    lookAtz=oldLookAtz;
}
