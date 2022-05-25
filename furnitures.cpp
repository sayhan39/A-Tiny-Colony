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

extern vector<unsigned int>tex;

void DrawerKnob()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[10]);
    // left side
    glPushMatrix();
    glTranslatef(0.1/2,0.1/2,0.1/2);
    glScalef(0.1,0.1,0.1);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    // right side
    glPushMatrix();
    glTranslatef(0.1/2+cube_unit+0.1,0.1/2,0.1/2);
    glScalef(0.1,0.1,0.1);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    // front side
    glPushMatrix();
    glTranslatef((0.1+0.1+cube_unit)/2,0.1/2,0.1/2+0.1);
    glScalef(0.1+0.1+cube_unit,0.1,0.1);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void TableDrawer(float plateX, float plateY, float plateZ, float sideX, float sideY, float sideZ, int texture)
{

    // drawer plate
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[texture]);
    glPushMatrix();
    glTranslatef(plateX/2,plateY/2,plateZ/2);
    glScalef(plateX,plateY,plateZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(0.5,0.5,0.5);
    glPopMatrix();

    // left side
    glPushMatrix();
    glTranslatef(sideX/2,sideY/2+plateY,sideZ/2);
    glScalef(sideX,sideY,sideZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(0.5,0.5,0.5);
    glPopMatrix();

    // right side
    glPushMatrix();
    glTranslatef(sideX/2+plateX-sideX,sideY/2+plateY,sideZ/2);
    glScalef(sideX,sideY,sideZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(0.5,0.5,0.5);
    glPopMatrix();

    // back side
    glPushMatrix();
    glTranslatef((plateX-sideX-sideX)/2+sideX,sideY/2+plateY,sideX/2);
    glScalef(plateX-sideX-sideX,sideY,sideX);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(0.5,0.5,0.5);
    glPopMatrix();

    // back side
    glPushMatrix();
    glTranslatef((plateX-sideX-sideX)/2+sideX,sideY/2+plateY,sideX/2+plateZ-sideX);
    glScalef(plateX-sideX-sideX,sideY,sideX);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(0.5,0.5,0.5);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // drawer knob
    glPushMatrix();
    glTranslatef(plateX/2-1.2/2,plateY+sideY/2,sideZ);
    DrawerKnob();
    glPopMatrix();
}

void Table(bool drawer/*=false*/)
{
    float legX = 0.5*cube_unit;
    float legY = 6*cube_unit;
    float legZ = 0.5*cube_unit;

    float stretcherX = legX/2;
    float stretcherY = 0.2*cube_unit;
    float stretcherZ = tableZ-legZ-legZ;

    // Units for drawer.
    float plateX = tableX-6*cube_unit;
    float plateY = 0.1*cube_unit;
    float plateZ = tableZ-3*cube_unit;

    float sideX = 0.2*cube_unit;
    float sideY = 0.8*cube_unit;
    float sideZ = plateZ;

    float apronX = tableX-legX-legX;
    float apronY = cube_unit;
    float apronZ = legZ/2;

    //top
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[24]);
    glPushMatrix();
    glTranslatef(tableX/2,tableY/2+legY,tableZ/2);
    glScalef(tableX,tableY,tableZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[23]);
    //rear left leg
    glPushMatrix();
    glTranslatef(legX/2,legY/2,legZ/2);
    glScalef(legX,legY,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    //rear right leg
    glPushMatrix();
    glTranslatef(legX/2+tableX-legX,legY/2,legZ/2);
    glScalef(legX,legY,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    //front left leg
    glPushMatrix();
    glTranslatef(legX/2,legY/2,legZ/2+tableZ-legZ);
    glScalef(legX,legY,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    // front right leg
    glPushMatrix();
    glTranslatef(legX/2+tableX-legX,legY/2,legZ/2+tableZ-legZ);
    glScalef(legX,legY,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    //left stretcher
    glPushMatrix();
    glTranslatef(stretcherX/2,stretcherY/2+legY/4,stretcherZ/2+legZ);
    glScalef(stretcherX,stretcherY,stretcherZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    //right stretcher
    glPushMatrix();
    glTranslatef(stretcherX/2+tableX-legX/2,stretcherY/2+legY/4,stretcherZ/2+legZ);
    glScalef(stretcherX,stretcherY,stretcherZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    //cross stretcher
    glPushMatrix();
    glTranslatef((tableX-legX)/2+legX/2,stretcherY/2+legY/4,stretcherX/2+tableZ/2);
    glScalef(tableX-legX,stretcherY,stretcherX);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    if(drawer)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, tex[23]);
        glPushMatrix();
        glTranslatef((apronX-plateX-cube_unit)/2+legX,apronY/2+legY-apronY,apronZ/2+tableZ-apronZ);
        glScalef(apronX-plateX-cube_unit,apronY,apronZ);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        cube(1.0,1.0,1.0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(cube_unit/2+tableX-legX-cube_unit,apronY/2+legY-apronY,apronZ/2+tableZ-apronZ);
        glScalef(cube_unit,apronY,apronZ);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        cube(1.0,1.0,1.0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(plateX/2+tableX-legX-cube_unit-plateX,(cube_unit-plateY-sideY)/2+legY-sideY-plateY-plateY,apronZ/2+tableZ-apronZ);
        glScalef(plateX,cube_unit-plateY-sideY,apronZ);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        cube(1.0,1.0,1.0);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);

        glPushMatrix();
        glTranslatef(tableX-plateX-legX-cube_unit,legY-plateY-sideY,tableZ-plateZ);
        TableDrawer(plateX,plateY,plateZ,sideX,sideY,sideZ);
        glPopMatrix();
    }
    else
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, tex[23]);
        glPushMatrix();
        glTranslatef(apronX/2+tableX-legX-apronX,apronY/2+legY-apronY,apronZ/2+tableZ-apronZ);
        glScalef(apronX,apronY,apronZ);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        cube(0.3,0.3,0.4);
        glPopMatrix();
    }

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[23]);
    glPushMatrix();
    glTranslatef(apronX/2+tableX-legX-apronX,apronY/2+legY-apronY,apronZ/2);
    glScalef(apronX,apronY,apronZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(apronZ/2,apronY/2+legY-apronY,(tableZ-legZ-legZ)/2+legZ);
    glScalef(apronZ,apronY,tableZ-legZ-legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(apronZ/2+tableX-apronZ,apronY/2+legY-apronY,(tableZ-legZ-legZ)/2+legZ);
    glScalef(apronZ,apronY,tableZ-legZ-legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(tableX/2,legY + tableY,tableZ/2);
    glRotatef(90,0,0,1);
    FlowerVase();
    glPopMatrix();
}

void TableRotate(float angle)
{
    glTranslatef(tableX/2,0,tableZ/2);
    glRotatef(angle,0,1,0);
    glTranslatef(-tableX/2,0,-tableZ/2);
}

void Chair()
{
    float a,b,c,d;

    float legX = 0.5*cube_unit;
    float legY = 4*cube_unit;
    float legZ = 0.5*cube_unit;

    float splindleX = legX/2;
    float splindleY = chairY;
    float splindleZ = chairZ-legZ-legZ;

    // Seat
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[22]);
    glPushMatrix();
    glTranslatef(chairX/2,chairY/2+legY,chairZ/2);
    glScalef(chairX,chairY,chairZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    c = 0;
    d = 0;
    a = chairX/chairX + c;
    b = chairZ/chairZ + d;
    cube(1.0,1.0,1.0,a,b,c,d);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[23]);
    // rear left leg
    glPushMatrix();
    glTranslatef(legX/2,legY/2,legZ/2);
    glScalef(legX,legY,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    // front left leg
    glPushMatrix();
    glTranslatef(legX/2,legY/2,legZ/2+chairZ-legZ);
    glScalef(legX,legY,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    // front right leg
    glPushMatrix();
    glTranslatef(legX/2+chairX-legX,legY/2,legZ/2+chairZ-legZ);
    glScalef(legX,legY,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    // rear right leg
    glPushMatrix();
    glTranslatef(legX/2+chairX-legX,legY/2,legZ/2);
    glScalef(legX,legY,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    // left back
    glPushMatrix();
    glTranslatef(legX/2,legY/2+legY+chairY,legZ/2);
    glScalef(legX,legY,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    //right back
    glPushMatrix();
    glTranslatef(legX/2+chairX-legX,legY/2+legY+chairY,legZ/2);
    glScalef(legX,legY,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    //left splindle
    glPushMatrix();
    glTranslatef(splindleX/2,splindleY/2+legY/4,splindleZ/2+legZ);
    glScalef(splindleX,splindleY,splindleZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    // right splindle
    glPushMatrix();
    glTranslatef(splindleX/2+chairX-legX/2,splindleY/2+legY/4,splindleZ/2+legZ);
    glScalef(splindleX,splindleY,splindleZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    // front cross splindle
    glPushMatrix();
    glTranslatef(splindleZ/2+legX,splindleY/2+legY/4,splindleX/2+chairZ-legZ/2);
    glRotatef(90,0,1,0);
    glScalef(splindleX,splindleY,splindleZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    // bottom cross rail
    glPushMatrix();
    glTranslatef(splindleZ/2+legX,splindleY/2+legY+chairY-splindleY+legY/3,splindleX/2);
    glRotatef(90,0,1,0);
    glScalef(splindleX,splindleY,splindleZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    // middle cross rail
    glPushMatrix();
    glTranslatef(splindleZ/2+legX,splindleY/2+legY+chairY-splindleY+legY/3*2,splindleX/2);
    glRotatef(90,0,1,0);
    glScalef(splindleX,splindleY,splindleZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    //top cross rail
    glPushMatrix();
    glTranslatef(splindleZ/2+legX,splindleY/2+legY+chairY-splindleY+legY,splindleX/2);
    glRotatef(90,0,1,0);
    glScalef(splindleX,splindleY,splindleZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void ChairRotate(float angle)
{
    glTranslatef(chairX/2,0,chairZ/2);
    glRotatef(angle,0,1,0);
    glTranslatef(-chairX/2,0,-chairZ/2);
}

void TableChair()
{
    glPushMatrix();
    Table(true);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(tableX/2 - chairX/2, 0, tableZ);
    ChairRotate(180);
    Chair();
    glPopMatrix();
}

void TableChairRotate(float angle)
{
    if((int(angle)/90)%2 == 1)
        glTranslatef(tablechairZ/2,0,tablechairX/2);
    else
        glTranslatef(tablechairX/2,0,tablechairZ/2);
    glRotatef(angle,0,1,0);
    glTranslatef(-tablechairX/2,0,-tablechairZ/2);
}

void Tool()
{
    float legx = 0.3*cube_unit;
    float legy = 4*cube_unit;
    float legz = legx;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex[26]);
    glPushMatrix();
    glTranslatef(cube_unit/2+cube_unit/5,legy-0.2*cube_unit,cube_unit/2+cube_unit/5);
    glRotatef(90,0,0,1);
    toolTopCurve();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, tex[33]);
    glPushMatrix();
    glRotatef(5,1,0,-1);
    glTranslatef(legx/2,legy/2,legz/2);
    glScalef(legx,legy,legz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glRotatef(5,1,0,1);
    glTranslatef(legx/2+cube_unit+cube_unit/4,legy/2,legz/2);
    glScalef(legx,legy,legz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glRotatef(5,-1,0,-1);
    glTranslatef(legx/2,legy/2,legz/2+cube_unit+cube_unit/4);
    glScalef(legx,legy,legz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glRotatef(5,-1,0,1);
    glTranslatef(legx/2+cube_unit+cube_unit/4,legy/2,legz/2+cube_unit+cube_unit/4);
    glScalef(legx,legy,legz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void DiningTable()
{
    float legX = cube_unit;
    float legY = 6*cube_unit;
    float legZ = cube_unit;

    float legBottomX = legX;
    float legBottomY = 0.5*cube_unit;
    float legBottomZ = 2*legBottomX;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[32]);
    glPushMatrix();
    glTranslatef(diningTableX/2,diningTableY/2 + legY,diningTableZ/2);
    glScalef(diningTableX, diningTableY, diningTableZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(legX/2 + diningTableX/4 - legX/4,legY/2,legZ/2 + diningTableZ/2 - legZ/2);
//    glScalef(legX,legY,legZ);
//    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
//    cube(1.0,0.0,0.0);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(legX/2 + 3*diningTableX/4 - legX/4,legY/2,legZ/2 + diningTableZ/2 - legZ/2);
//    glScalef(legX,legY,legZ);
//    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
//    cube(1.0,0.0,0.0);
//    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, tex[10]);
    for(int i=0; i<4; i++)
    {
        glPushMatrix();
        if(i==0)
            glTranslatef(legBottomX/2 + diningTableX/4 - legX/4,legBottomY/2,legBottomZ/2 + diningTableZ/2 + legZ/2);
        else if(i==1)
            glTranslatef(legBottomX/2 + diningTableX/4 - legX/4,legBottomY/2,legBottomZ/2 + diningTableZ/2 - legBottomZ - legZ/2);
        else if(i==2)
            glTranslatef(legBottomX/2 + 3*diningTableX/4 - legX/4,legBottomY/2,legBottomZ/2 + diningTableZ/2 + legZ/2);
        else if(i==3)
            glTranslatef(legBottomX/2 + 3*diningTableX/4 - legX/4,legBottomY/2,legBottomZ/2 + diningTableZ/2 - legBottomZ - legZ/2);
        glScalef(legBottomX,legBottomY,legBottomZ);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        cube(1.0,1.0,1.0);
        glPopMatrix();
    }

    for(int i=0; i<4; i++)
    {
        glPushMatrix();
        if(i==0)
            glTranslatef(legBottomZ/2 + diningTableX/4 - legX/4 - legBottomZ,legBottomY/2,legBottomX/2 + diningTableZ/2 - legBottomX/2);
        else if(i==1)
            glTranslatef(legBottomZ/2 + diningTableX/4 - legX/4 + legX,legBottomY/2,legBottomX/2 + diningTableZ/2 - legBottomX/2);
        else if(i==2)
            glTranslatef(legBottomZ/2 + 3*diningTableX/4 - legX/4 - legBottomZ,legBottomY/2,legBottomX/2 + diningTableZ/2 - legBottomX/2);
        else if(i==3)
            glTranslatef(legBottomZ/2 + 3*diningTableX/4 - legX/4 + legX,legBottomY/2,legBottomX/2 + diningTableZ/2 - legBottomX/2);
        glRotatef(90,0,1,0);
        glScalef(legBottomX,legBottomY,legBottomZ);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        cube(1.0,1.0,1.0);
        glPopMatrix();
    }

    glBindTexture(GL_TEXTURE_2D,tex[17]);
    glPushMatrix();
    glTranslatef(cube_unit + diningTableX/4 - cube_unit/2,0,cube_unit + diningTableZ/2 - cube_unit);
    glRotatef(90,0,0,1);
    legCurve(1,1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cube_unit + 3*diningTableX/4 - cube_unit/2,0,cube_unit + diningTableZ/2 - cube_unit);
    glRotatef(90,0,0,1);
    legCurve(1,1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D,tex[10]);
    glPushMatrix();
    glTranslatef(diningTableX/2,legY+diningTableY,diningTableZ/2);
    glRotatef(90,0,0,1);
    FlowerVase(1.0,1.0,1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void DiningTableAndTools()
{
    glPushMatrix();
    DiningTable();
    glPopMatrix();

    for(int i=0; i<6; i++)
    {
        glPushMatrix();
        if(i<3)
            glTranslatef(((i+1)*diningTableX)/4,0,0);
        else if(i>2)
            glTranslatef(((i-3+1)*diningTableX)/4,0,diningTableZ);
        Tool();
        glPopMatrix();
    }
}

void OfficeChair()
{
    float a,b,c,d;

    float legY = 3*cube_unit;

    float handlerLength = cube_unit;
    float handlerWidth = 0.3*cube_unit;
    float handlerHeight = 0.5*cube_unit;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[26]);
    glPushMatrix();
    glTranslatef(1.2*cube_unit,chairY+legY,4*cube_unit);
    glRotatef(90,0,1,0);
    glRotatef(90,0,0,1);
    glScalef(1.5,1,1);
    chairBackCurve();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // Seat
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, tex[26]);
//    glPushMatrix();
//    glTranslatef(chairX/2,chairY/2+legY,chairZ/2);
//    glScalef(chairX,chairY,chairZ);
//    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
//    c = 0;
//    d = 0;
//    a = chairX/chairX + c;
//    b = chairZ/chairZ + d;
//    cube(1.0,1.0,1.0,a,b,c,d);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(2*cube_unit,0,chairZ/2);
    glScalef(0.3,2/4.0,0.3);
    glRotatef(90,0,0,1);
    legCurve();
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[26]);
    glPushMatrix();
    glTranslatef(0,legY,1*cube_unit);
    glScalef(1.5,0.3,2);
    pillowCurve(1.0,1.0,1.0,1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(handlerLength/2+cube_unit/2+cube_unit/8+cube_unit/8,handlerHeight/2,handlerWidth/2+cube_unit+cube_unit/2+cube_unit/3);
    glScalef(handlerLength,handlerHeight,handlerWidth);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(handlerLength/2+cube_unit+cube_unit+cube_unit/8,handlerHeight/2,handlerWidth/2+cube_unit+cube_unit/2+cube_unit/3);
    glScalef(handlerLength,handlerHeight,handlerWidth);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(handlerWidth/2+cube_unit+cube_unit-handlerWidth/2,handlerHeight/2,handlerLength/2+cube_unit+cube_unit+cube_unit/4);
    glScalef(handlerWidth,handlerHeight,handlerLength);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(handlerWidth/2+cube_unit+cube_unit-handlerWidth/2,handlerHeight/2,handlerLength/2+cube_unit/2+cube_unit/4);
    glScalef(handlerWidth,handlerHeight,handlerLength);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cube_unit/2,legY+chairY+cube_unit,cube_unit/4);
    glRotatef(90,0,-1,0);
    glScalef(0.7,1,1);
    chairHandleCurve();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(chairX,legY+chairY+cube_unit,cube_unit/4);
    glRotatef(90,0,-1,0);
    glScalef(0.7,1,1);
    chairHandleCurve();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cube_unit/8,1.1*cube_unit/2+legY+chairY,cube_unit/4+chairZ/2);
    glScalef(cube_unit/4,1.1*cube_unit,cube_unit/2);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,0.0,0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cube_unit/8+chairX-cube_unit/4,1.1*cube_unit/2+legY+chairY,cube_unit/4+chairZ/2);
    glScalef(cube_unit/4,1.1*cube_unit,cube_unit/2);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,0.0,0.0);
    glPopMatrix();

}

void Desk()
{
    float legx = cube_unit/2;
    float legz = cube_unit/2;
    float legy = 7*cube_unit;

    float shortLegx = cube_unit/2;
    float shortLegy = 1.6*cube_unit;
    float shortLegz = cube_unit/2;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex[28]);
    glPushMatrix();
    glTranslatef(-legx/2,legy+cube_unit/2,0);
    glRotatef(90,1,0,0);
    glScalef(2,1,1);
    deskTopCurve();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(legx/2,(legy+0.05*cube_unit)/2,legz/2+cube_unit/8);
    glScalef(legx,legy+0.05*cube_unit,legz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(legx/2,(legy+0.05*cube_unit)/2,legz/2+4*cube_unit-legz+cube_unit/8);
    glScalef(legx,legy+0.05*cube_unit,legz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(7.5*cube_unit,0,cube_unit/2);
    glScalef(0.8,0.8,0.8);
    ShortCabinet(2,2);
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex[28]);
    glPushMatrix();
    glTranslatef(shortLegx/2+7.5*cube_unit,shortLegy/2+5.4*cube_unit,shortLegz/2+4*cube_unit-shortLegz);
    glScalef(shortLegx,shortLegy,shortLegz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(shortLegx/2+11.7*cube_unit,shortLegy/2+5.4*cube_unit,shortLegz/2+4*cube_unit-shortLegz);
    glScalef(shortLegx,shortLegy,shortLegz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(shortLegx/2+7.5*cube_unit,shortLegy/2+5.4*cube_unit,shortLegz/2+cube_unit/2);
    glScalef(shortLegx,shortLegy,shortLegz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(shortLegx/2+11.7*cube_unit,shortLegy/2+5.4*cube_unit,shortLegz/2+cube_unit/2);
    glScalef(shortLegx,shortLegy,shortLegz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void DeskAndChair(float angle)
{
    if(angle>0)
        DeskAndChairRotate(angle);
    glPushMatrix();
    Desk();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(chairX + cube_unit*1.5,0,chairZ+cube_unit+cube_unit);
    glRotatef(180,0,1,0);
    OfficeChair();
    glPopMatrix();
}

void DeskAndChairRotate(float angle)
{
    if((int(angle/90))%2==0)
        glTranslatef(5.5*cube_unit,0,3*cube_unit);
    else
        glTranslatef(3*cube_unit,0,5.5*cube_unit);
    glRotatef(angle,0,1,0);
    glTranslatef(-5.5*cube_unit,0,-3*cube_unit);
}

void EmployeeTable(bool drawer/*=false*/)
{
    float legX = 0.5*cube_unit;
    float legY = 6*cube_unit;
    float legZ = 0.5*cube_unit;

    float stretcherX = legX/2;
    float stretcherY = 0.2*cube_unit;
    float stretcherZ = EmployeeTableX-legZ-legZ;

    // Units for drawer.
    float plateX = EmployeeTableX-4*cube_unit;
    float plateY = 0.1*cube_unit;
    float plateZ = EmployeeTableZ-3*cube_unit;

    float sideX = 0.2*cube_unit;
    float sideY = 0.8*cube_unit;
    float sideZ = plateZ;

    float apronX = EmployeeTableX-legX-legX;
    float apronY = legY;
    float frontApronY = cube_unit;
    float apronZ = legZ/2;

    //top
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[28]);
    glPushMatrix();
    glTranslatef(EmployeeTableX/2,EmployeeTableY/2+legY,EmployeeTableZ/2);
    glScalef(EmployeeTableX,EmployeeTableY,EmployeeTableZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[23]);
    //rear left leg
    glPushMatrix();
    glTranslatef(legX/2,legY/2,legZ/2);
    glScalef(legX,legY,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    //rear right leg
    glPushMatrix();
    glTranslatef(legX/2+EmployeeTableX-legX,legY/2,legZ/2);
    glScalef(legX,legY,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    //front left leg
    glPushMatrix();
    glTranslatef(legX/2,legY/2,legZ/2+EmployeeTableZ-legZ);
    glScalef(legX,legY,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    // front right leg
    glPushMatrix();
    glTranslatef(legX/2+EmployeeTableX-legX,legY/2,legZ/2+EmployeeTableZ-legZ);
    glScalef(legX,legY,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    if(drawer)
    {
        glPushMatrix();
        glTranslatef(legX,legY-plateY-sideY,EmployeeTableZ-plateZ);
        TableDrawer(plateX,plateY,plateZ,sideX,sideY,sideZ,27);
        glPopMatrix();
    }

    glPushMatrix();
    glScalef(1,0.47,1);
    glTranslatef(EmployeeTableX-filingCabinetUnitx-legX,0,EmployeeTableZ-filingCabinetUnitz+cube_unit/4);
    ShortCabinet(4,1);
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[23]);
    glPushMatrix();
    glTranslatef(apronX/2+EmployeeTableX-legX-apronX,apronY/2+legY-apronY,apronZ/2);
    glScalef(apronX,apronY,apronZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(apronZ/2,apronY/2+legY-apronY,(EmployeeTableZ-legZ-legZ)/2+legZ);
    glScalef(apronZ,apronY,EmployeeTableZ-legZ-legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(apronZ/2+EmployeeTableX-apronZ,apronY/2+legY-apronY,(EmployeeTableZ-legZ-legZ)/2+legZ);
    glScalef(apronZ,apronY,EmployeeTableZ-legZ-legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void EmployeeTableChair(float angle)
{
    if(angle>0)
    {
        if(((int(angle/90))%2)==0)
            glTranslatef(EmployeeTableChairX/2,0,EmployeeTableChairZ/2+cube_unit*1.75);
        else
            glTranslatef(EmployeeTableChairZ/2+cube_unit*1.75,0,EmployeeTableChairX/2);
        glRotatef(angle,0,1,0);
        glTranslatef(-EmployeeTableChairX/2,0,-EmployeeTableChairZ/2);
    }

    glPushMatrix();
    EmployeeTable(true);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(chairX + cube_unit+cube_unit/2,0,chairZ+EmployeeTableZ-cube_unit);
    glRotatef(180,0,1,0);
    OfficeChair();
    glPopMatrix();
}

void HeadTable()
{
    float lengthy = 6*cube_unit;
    float lengthz = 4*cube_unit;
    float wallx = cube_unit/4;

    float shelfCovery = 0.2*cube_unit;
    float shelfBottomy = shelfCovery;
    float shelfWall = 0.2*cube_unit;
    float shelfDividerz = 0.2*cube_unit;
    float dividery = 0.2*cube_unit;
    float drawerz = 0.2*cube_unit;

    float shelfx = 7*cube_unit-shelfWall-shelfWall;
    float shelfy = lengthy-cube_unit-shelfCovery-shelfBottomy;
    float shelfz = 8*cube_unit;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[17]);
    glPushMatrix();
    glTranslatef(0,lengthy,drawerz);
    glScalef(4,1,1);
    glRotatef(90,1,0,0);
    glTranslatef(0,0,-cube_unit/2);
    deskTopCurve(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cube_unit,shelfy+shelfBottomy+shelfCovery,cube_unit);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cube_unit,shelfy+shelfBottomy+shelfCovery,cube_unit+cube_unit+cube_unit);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, tex[19]);
    // Left side wall
    glPushMatrix();
    glTranslatef(wallx/2+25*cube_unit,lengthy/2,lengthz/2+cube_unit/4+cube_unit/8+drawerz);
    glScalef(wallx,lengthy,lengthz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, tex[30]);
    // Shelf Top
    glPushMatrix();
    glTranslatef(shelfx/2,shelfCovery/2+shelfy+shelfCovery,shelfz/2+drawerz);
    glScalef(shelfx,shelfCovery,shelfz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    // Shelf Bottom
    glPushMatrix();
    glTranslatef(shelfx/2,shelfBottomy/2,shelfz/2+drawerz);
    glScalef(shelfx,shelfBottomy,shelfz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, tex[28]);
    // Shelf Wall (left)
    glPushMatrix();
    glTranslatef(shelfWall/2,shelfy/2+shelfBottomy,shelfz/2+drawerz);
    glScalef(shelfWall,shelfy,shelfz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    // Shelf Wall (right)
    glPushMatrix();
    glTranslatef(shelfWall/2+shelfx-shelfWall,shelfy/2+shelfBottomy,shelfz/2+drawerz);
    glScalef(shelfWall,shelfy,shelfz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, tex[30]);
    // Shelf Divider (inside)
    glPushMatrix();
    glTranslatef((shelfx-shelfWall-shelfWall)/2+shelfWall,shelfy/2+shelfBottomy,shelfDividerz/2+shelfz/2-shelfDividerz/2+drawerz);
    glScalef(shelfx-shelfWall-shelfWall,shelfy,shelfDividerz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D,tex[27]);
    // Book Shelf Divider (middle)
    glPushMatrix();
    glTranslatef((shelfx-shelfWall-shelfWall)/2+shelfWall,dividery/2+shelfBottomy+shelfy/2-dividery/2,(shelfz/2-shelfDividerz/2)/2+shelfz/2+shelfDividerz/2+drawerz);
    glScalef(shelfx-shelfWall-shelfWall,dividery,shelfz/2-shelfDividerz/2);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    // Shelf Drawer Bottom (middle)
    glPushMatrix();
    glTranslatef((shelfx-shelfWall-shelfWall)/2+shelfWall,dividery/2+shelfBottomy,(shelfz/2-shelfDividerz/2)/2+drawerz);
    glScalef(shelfx-shelfWall-shelfWall,dividery,shelfz/2-shelfDividerz/2);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    // Shelf Wall (left)
    glPushMatrix();
    glTranslatef(shelfWall/2+shelfWall,(shelfy-dividery)/2+shelfBottomy+dividery,(shelfz/2-shelfDividerz/2)/2+drawerz);
    glScalef(shelfWall,shelfy-dividery,shelfz/2-shelfDividerz/2);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,0.5,1.0);
    glPopMatrix();

    // Shelf Wall (right)
    glPushMatrix();
    glTranslatef(shelfWall/2+shelfx-shelfWall-shelfWall,(shelfy-dividery)/2+shelfBottomy+dividery,(shelfz/2-shelfDividerz/2)/2+drawerz);
    glScalef(shelfWall,shelfy-dividery,shelfz/2-shelfDividerz/2);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,0.5,1.0);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D,tex[32]);
    // Shelf Drawer
    glPushMatrix();
    glTranslatef(shelfx/2,shelfy/2+shelfBottomy,drawerz/2);
    glScalef(shelfx,shelfy,drawerz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(shelfx/2+cube_unit/2,shelfy/2+shelfBottomy+shelfCovery,0);
    glRotatef(180,0,1,0);
    DrawerKnob();
    glPopMatrix();
}

void HeadTableChair()
{
    glPushMatrix();
    HeadTable();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(chairX+cube_unit*11,0,HeadTableZ+cube_unit+cube_unit);
    glScalef(1.3,1,1);
    glRotatef(180,0,1,0);
    OfficeChair();
    glPopMatrix();
}

void FilingCabinet(int row/*=2*/, int column/*=1*/, float angle)
{
    float a,b,c,d;

    float drawerHeight = 3*cube_unit;
    float drawerWidth = 3*cube_unit;
    float drawerLength = 4*cube_unit;

    float topHeight = cube_unit/2;
    float topWidth = drawerWidth;
    float topLength = drawerLength + cube_unit/4;

    float bottomHeight = cube_unit/4;
    float bottomWidth = drawerWidth;
    float bottomLength = drawerLength + cube_unit/4;

    float wallWidth = cube_unit/4;
    float wallHeight = bottomHeight + (row*drawerHeight) + topHeight;
    float wallLength = drawerLength + cube_unit/4;

    bottomWidth -= wallWidth + wallWidth;
    topWidth -= wallWidth + wallWidth;

    FilingCabinetRotate(row,column,angle);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[20]);
    glPushMatrix();
    glTranslatef((column*drawerWidth)/2, wallHeight/2, cube_unit/4/2);
    glScalef(column*drawerWidth, wallHeight, cube_unit/4);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    c = 0;
    d = 0;
    a = 1;
    b = 1;
    cube(1.0,1.0,1.0,4*a,4*b,4*c,4*d);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,cube_unit/4);
    for(int i=0; i<=column; i++)
    {
        if(i<column)
        {
            glPushMatrix();
            glTranslatef(wallWidth/2 + (i*drawerWidth), wallHeight/2, wallLength/2);
            glScalef(wallWidth, wallHeight, wallLength);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            cube(1.0,1.0,1.0);
            glPopMatrix();

            glPushMatrix();
            glTranslated(bottomWidth/2 + wallWidth + (i*(drawerWidth)), bottomHeight/2, bottomLength/2);
            glScalef(bottomWidth, bottomHeight, bottomLength);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            cube(1.0,1.0,1.0);
            glPopMatrix();

            glPushMatrix();
            glTranslated(topWidth/2 + wallWidth + (i*(drawerWidth)), topHeight/2 + wallHeight - topHeight, topLength/2);
            glScalef(topWidth, topHeight, topLength);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            cube(1.0,1.0,1.0);
            glPopMatrix();
        }

        if(i>0)
        {
            glPushMatrix();
            glTranslatef(wallWidth/2 + (i*drawerWidth) - wallWidth, wallHeight/2, wallLength/2);
            glScalef(wallWidth, wallHeight, wallLength);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            cube(1.0,1.0,1.0);
            glPopMatrix();
        }
    }
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(0,0,FileCabinetdrawerOpen);
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            if(i==0 && j==0)
            {
                glPushMatrix();
                glTranslatef(0,0,FileCabinetsingleDrawerOpen);
            }
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, tex[19]);
            glPushMatrix();
            glTranslatef(drawerWidth/2 + (j*drawerWidth), drawerHeight/2 + (i*drawerHeight) + bottomHeight, cube_unit/4/2 + drawerLength + cube_unit/4);
            glScalef(drawerWidth, drawerHeight, cube_unit/4);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            c = 0;
            d = 0;
            a = 1;
            b = 1;
            cube(1.0,1.0,1.0,a,b,c,d);
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glTranslatef(cube_unit/4/2 + wallWidth + (j*drawerWidth), (drawerHeight - cube_unit/4)/2 + (i*drawerHeight) + bottomHeight, drawerLength/2 + cube_unit/4);
            glScalef(cube_unit/4, drawerHeight-cube_unit/4, drawerLength);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            cube(1.0,0.0,0.0);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(cube_unit/4/2 + wallWidth + drawerWidth - wallWidth - wallWidth - wallWidth + (j*drawerWidth), (drawerHeight - cube_unit/4)/2 + (i*drawerHeight) + bottomHeight, drawerLength/2 + cube_unit/4);
            glScalef(cube_unit/4, drawerHeight-cube_unit/4, drawerLength);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            cube(1.0,0.0,0.0);
            glPopMatrix();

            glPushMatrix();
            glTranslatef((drawerWidth - cube_unit/4 - cube_unit/4)/2 + wallWidth + (j*drawerWidth), cube_unit/4/2 + bottomHeight + (i*drawerHeight), drawerLength/2);
            glScalef(drawerWidth - cube_unit/4 - cube_unit/4, cube_unit/4, drawerLength);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            cube(1.0,0.0,0.0);
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glTranslatef(((j+1)*drawerWidth) - drawerWidth/2 - (0.1*cube_unit + cube_unit/2), bottomHeight + ((i+1)*drawerHeight) - drawerHeight/2, 4.5);
            DrawerKnob();
            glPopMatrix();

            if(i==0 && j==0)
            {
                glPopMatrix();
            }
        }
    }
    glPopMatrix();

    glPopMatrix();
}

void FilingCabinetRotate(int row, int column, float angle)
{
    float x = filingCabinetUnitx*column;
    float y = filingCabinetUnity*row;
    float z = filingCabinetUnitz;

    if((int(angle/90))%2 == 0)
    {
        glTranslatef(x/2,0,z/2);
    }
    else
        glTranslatef(z/2,0,x/2);
    glRotatef(angle,0,1,0);
    glTranslatef(-x/2,0,-z/2);
}

void ShortCabinet(int row/*=2*/, int column/*=1*/)
{
    float a,b,c,d;

    float drawerHeight = 3*cube_unit;
    float drawerWidth = 3*cube_unit;
    float drawerLength = 4*cube_unit;

    float topHeight = cube_unit/2;
    float topWidth = drawerWidth;
    float topLength = drawerLength + cube_unit/4;

    float bottomHeight = cube_unit/4;
    float bottomWidth = drawerWidth;
    float bottomLength = drawerLength + cube_unit/4;

    float wallWidth = cube_unit/4;
    float wallHeight = bottomHeight + (row*drawerHeight) + topHeight;
    float wallLength = drawerLength + cube_unit/4;

    bottomWidth -= wallWidth + wallWidth;
    topWidth -= wallWidth + wallWidth;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[28]);
    glPushMatrix();
    glTranslatef((column*drawerWidth)/2, wallHeight/2, cube_unit/4/2);
    glScalef(column*drawerWidth, wallHeight, cube_unit/4);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    c = 0;
    d = 0;
    a = 1;
    b = 1;
    cube(1.0,1.0,1.0,4*a,4*b,4*c,4*d);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,cube_unit/4);
    for(int i=0; i<=column; i++)
    {
        if(i<column)
        {
            glPushMatrix();
            glTranslatef(wallWidth/2 + (i*drawerWidth), wallHeight/2, wallLength/2);
            glScalef(wallWidth, wallHeight, wallLength);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            cube(1.0,1.0,1.0);
            glPopMatrix();

            glPushMatrix();
            glTranslated(bottomWidth/2 + wallWidth + (i*(drawerWidth)), bottomHeight/2, bottomLength/2);
            glScalef(bottomWidth, bottomHeight, bottomLength);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            cube(1.0,1.0,1.0);
            glPopMatrix();

            glPushMatrix();
            glTranslated(topWidth/2 + wallWidth + (i*(drawerWidth)), topHeight/2 + wallHeight - topHeight, topLength/2);
            glScalef(topWidth, topHeight, topLength);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            cube(1.0,1.0,1.0);
            glPopMatrix();
        }

        if(i>0)
        {
            glPushMatrix();
            glTranslatef(wallWidth/2 + (i*drawerWidth) - wallWidth, wallHeight/2, wallLength/2);
            glScalef(wallWidth, wallHeight, wallLength);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            cube(1.0,1.0,1.0);
            glPopMatrix();
        }
    }
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(0,0,FileCabinetdrawerOpen);
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            if(i==0 && j==0)
            {
                glPushMatrix();
                glTranslatef(0,0,FileCabinetsingleDrawerOpen);
            }
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, tex[29]);
            glPushMatrix();
            glTranslatef(drawerWidth/2 + (j*drawerWidth), drawerHeight/2 + (i*drawerHeight) + bottomHeight, cube_unit/4/2 + drawerLength + cube_unit/4);
            glScalef(drawerWidth, drawerHeight, cube_unit/4);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            c = 0;
            d = 0;
            a = 1;
            b = 1;
            cube(1.0,1.0,1.0,a,b,c,d);
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glTranslatef(cube_unit/4/2 + wallWidth + (j*drawerWidth), (drawerHeight - cube_unit/4)/2 + (i*drawerHeight) + bottomHeight, drawerLength/2 + cube_unit/4);
            glScalef(cube_unit/4, drawerHeight-cube_unit/4, drawerLength);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            cube(1.0,0.0,0.0);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(cube_unit/4/2 + wallWidth + drawerWidth - wallWidth - wallWidth - wallWidth + (j*drawerWidth), (drawerHeight - cube_unit/4)/2 + (i*drawerHeight) + bottomHeight, drawerLength/2 + cube_unit/4);
            glScalef(cube_unit/4, drawerHeight-cube_unit/4, drawerLength);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            cube(1.0,0.0,0.0);
            glPopMatrix();

            glPushMatrix();
            glTranslatef((drawerWidth - cube_unit/4 - cube_unit/4)/2 + wallWidth + (j*drawerWidth), cube_unit/4/2 + bottomHeight + (i*drawerHeight), drawerLength/2);
            glScalef(drawerWidth - cube_unit/4 - cube_unit/4, cube_unit/4, drawerLength);
            glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
            cube(1.0,0.0,0.0);
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);

            glPushMatrix();
            glTranslatef(((j+1)*drawerWidth) - drawerWidth/2 - (0.1*cube_unit + cube_unit/2), bottomHeight + ((i+1)*drawerHeight) - drawerHeight/2, 4.5);
            DrawerKnob();
            glPopMatrix();

            if(i==0 && j==0)
            {
                glPopMatrix();
            }
        }
    }
    glPopMatrix();

    glPopMatrix();
}

void ParkBench()
{
    float a,b,c,d;

    float legx = cube_unit/4;
    float legy = 3*cube_unit;
    float legz = cube_unit/4;

    float benchx = 10*cube_unit;

    float piecez = cube_unit/2;
    float piecex = benchx-legx - legx;
    float piecey = cube_unit/4;
    float numberOfPieces = planksInBench;

    float gap = gapInPieces;

    float connectorx = legx;
    float connectory = piecey;
    float connectorz = numberOfPieces*piecez + (numberOfPieces - 1)*gap - legz - legz;

    float benchz = legz + connectorz + legz;

    float backx = legx;
    float backy = legy;
    float backz = legz;

    if(1)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, tex[21]);
        glPushMatrix();
        glTranslatef(legx/2, legy/2, legz/2);
        glScalef(legx,legy,legz);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        c = 0;
        d = 0;
        a = legx/benchx + c;
        b = legy/legy + d;
        cube(1.0,1.0,1.0,a,b,c,d);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(legx/2 + benchx - legx, legy/2, legz/2);
        glScalef(legx,legy,legz);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        c = 0;
        d = 0;
        a = legx/benchx + c;
        b = legy/legy + d;
        cube(1.0,1.0,1.0,a,b,c,d);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(legx/2, legy/2, legz/2 + numberOfPieces*(gap + piecez) - legz - legz);
        glScalef(legx,legy,legz);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        c = 0;
        d = 0;
        a = legx/benchx + c;
        b = legy/legy + d;
        cube(1.0,1.0,1.0,a,b,c,d);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(legx/2 + benchx - legx, legy/2, legz/2 + numberOfPieces*(gap + piecez) - legz - legz);
        glScalef(legx,legy,legz);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        c = 0;
        d = 0;
        a = legx/benchx + c;
        b = legy/legy + d;
        cube(1.0,1.0,1.0,a,b,c,d);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, tex[20]);
        glPushMatrix();
        glTranslatef(connectorx/2, connectory/2 + legy - connectory, connectorz/2 + legz);
        glScaled(connectorx, connectory, connectorz);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        cube(1.0,1.0,1.0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(connectorx/2 + benchx - connectorx, connectory/2 + legy - connectory, connectorz/2 + legz);
        glScaled(connectorx, connectory, connectorz);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        cube(1.0,1.0,1.0);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[20]);
    for(int i=0; i<numberOfPieces; i++)
    {
        glPushMatrix();
        glTranslatef(piecex/2 + legx, piecey/2 + legy - piecey, piecez/2 + (i*(gap + piecez)));
        glScalef(piecex,piecey,piecez);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        cube(1.0,1.0,1.0);
        glPopMatrix();
    }
    glDisable(GL_TEXTURE_2D);

    if(1)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, tex[21]);
        glPushMatrix();
        glTranslatef(backx/2, backy/2 + legy, backz/2);
        glScalef(backx, backy, backz);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        c = 0;
        d = 0;
        a = legx/benchx + c;
        b = legy/legy + d;
        cube(1.0,1.0,1.0,a,b,c,d);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(backx/2 + benchx - backx, backy/2 + legy, backz/2);
        glScalef(backx, backy, backz);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        c = 0;
        d = 0;
        a = legx/benchx + c;
        b = legy/legy + d;
        cube(1.0,1.0,1.0,a,b,c,d);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[20]);
    for(int i=0; i<numberOfPieces; i++)
    {
        glPushMatrix();
        glTranslatef(piecex/2 + legx, piecez/2 + legy + (i*(gap+piecez)) + gap, piecey/2);
        glScalef(piecex, piecez, piecey);
        glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
        cube(1.0,1.0,1.0);
        glPopMatrix();
    }
    glDisable(GL_TEXTURE_2D);
}

void ParkBenchPair()
{
    glPushMatrix();
    glTranslatef(parkBenchx/2, 0, parkBenchz/2);
    glRotatef(180,0,1,0);
    glTranslatef(-parkBenchx/2, 0, -parkBenchz/2);
    ParkBench();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,parkBenchz + cube_unit/2);
    ParkBench();
    glPopMatrix();
}

void Cabinet(bool drawer/*=false*/)
{
    float legX = 0.5*cube_unit;
    float legY = 5*cube_unit;
    float legZ = 0.5*cube_unit;

    float tableX=cabinetx;
    float tableY=cabinety;
    float tableZ=cabinetz;

    float stretcherX = legX/2;
    float stretcherY = 0.2*cube_unit;
    float stretcherZ = tableZ-legZ-legZ;

    // Units for drawer.
    float plateX = tableX-6*cube_unit;
    float plateY = 0.1*cube_unit;
    float plateZ = tableZ-3*cube_unit;

    float sideX = 0.2*cube_unit;
    float sideY = 0.8*cube_unit;
    float sideZ = plateZ;

    float gap = cube_unit*0.5;
    float apronX = tableX-legX-legX;
    float apronY = legY-gap;
    float apronZ = legZ/2;

    float bottomX = tableX-legX-legX;
    float bottomY = tableY;
    float bottomZ = tableZ-legZ;

    //top
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex[24]);
    glPushMatrix();
    glTranslatef(tableX/2,tableY/2+legY,tableZ/2);
    glScalef(tableX,tableY,tableZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0,1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex[23]);
    //rear left leg
    glPushMatrix();
    glTranslatef(legX/2,legY/2,legZ/2);
    glScalef(legX,legY,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(0.4,0.2,0.2);
    glPopMatrix();

    //rear right leg
    glPushMatrix();
    glTranslatef(legX/2+tableX-legX,legY/2,legZ/2);
    glScalef(legX,legY,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(0.4,0.2,0.2);
    glPopMatrix();

    //front left leg
    glPushMatrix();
    glTranslatef(legX/2,legY/2,legZ/2+tableZ-legZ);
    glScalef(legX,legY,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(0.4,0.2,0.2);
    glPopMatrix();

    // front right leg
    glPushMatrix();
    glTranslatef(legX/2+tableX-legX,legY/2,legZ/2+tableZ-legZ);
    glScalef(legX,legY,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(0.4,0.2,0.2);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // rear apron
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[25]);
    glPushMatrix();
    glTranslatef(apronX/2+legX,apronY/2+gap,apronZ/2+legZ/2);
    glScalef(apronX,apronY,apronZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[24]);
    // left apron
    glPushMatrix();
    glTranslatef(apronZ/2+legX/2,apronY/2+gap,(tableZ-legZ-legZ)/2+legZ);
    glScalef(apronZ,apronY,tableZ-legZ-legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(0.5,0.5,0.5);
    glPopMatrix();

    // right apron
    glPushMatrix();
    glTranslatef(apronZ/2+tableX-apronZ-legX/2,apronY/2+gap,(tableZ-legZ-legZ)/2+legZ);
    glScalef(apronZ,apronY,tableZ-legZ-legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(0.5,0.5,0.5);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // bottom
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex[32]);
    glPushMatrix();
    glTranslatef((tableX-legX-legX)/2+legX,tableY/2+gap,(tableZ-legZ)/2+legZ);
    glScalef(tableX-legX-legX,tableY,tableZ-legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    // splitter
    glPushMatrix();
    glTranslatef(apronZ/2+tableX/5*3,(legY-gap-tableY)/2+gap+tableY,(tableZ-legZ)/2+legZ);
    glScalef(apronZ,legY-gap-tableY,tableZ-legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    // middle drawer stand
    glPushMatrix();
    glTranslatef((tableX/5*3-legX)/2+legX,apronZ/2+gap+tableY+(legY-gap-tableY)/3,legZ/2+tableZ-legZ);
    glScalef(tableX/5*3-legX,apronZ,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    // top drawer stand
    glPushMatrix();
    glTranslatef((tableX/5*3-legX)/2+legX,apronZ/2+gap+tableY+(legY-gap-tableY)/3*2,legZ/2+tableZ-legZ);
    glScalef(tableX/5*3-legX,apronZ,legZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // cabinet door
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[24]);
    glPushMatrix();
    glTranslatef((tableX/5*2-legX-apronZ)/2+tableX-legX-(tableX/5*2-legX-apronZ),(legY-gap-tableY)/2+gap+tableY,apronZ/2+tableZ-apronZ);
    glScalef(tableX/5*2-legX-apronZ,legY-gap-tableY,apronZ);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(0.5,0.5,0.5);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // cabinet door knob
    glPushMatrix();
    glTranslatef(0.1+legX+(tableX/5*3-legX)+apronZ+0.2,(legY-gap-tableY)/2+cube_unit/2,tableZ);
    glRotatef(90,0,0,1);
    DrawerKnob();
    glPopMatrix();

    // bottom drawer
    glPushMatrix();
    glTranslatef(legX,gap+tableY,legZ);
    TableDrawer(tableX/5*3-legX,0.1*cube_unit,tableZ-legZ,apronZ,(legY-gap-tableY)/3-apronZ/2,tableZ-legZ);
    glPopMatrix();

    // middle drawer
    glPushMatrix();
    glTranslatef(legX,gap+tableY+(legY-gap-tableY)/3+apronZ,legZ);
    TableDrawer(tableX/5*3-legX,0.1*cube_unit,tableZ-legZ,apronZ,(legY-gap-tableY)/3-apronZ-apronZ/2,tableZ-legZ);
    glPopMatrix();

    // top drawer
    glPushMatrix();
    glTranslatef(legX,(legY-gap-tableY)-apronZ/4,legZ);
    TableDrawer(tableX/5*3-legX,0.1*cube_unit,tableZ-legZ,apronZ,(legY-gap-tableY)/3-apronZ-apronZ/2,tableZ-legZ);
    glPopMatrix();
}

void CabinetInverse(bool drawer/*=false*/)
{
    glPushMatrix();
    glTranslatef(cabinetz/2,0,cabinetx/2);
    glRotatef(90,0,1,0);
    glTranslatef(-cabinetx/2,0,-cabinetz/2);
    Cabinet(drawer);
    glPopMatrix();
}

void Pillow()
{
    float a,b,c,d;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex[26]);
    glPushMatrix();
    glTranslatef(0,cube_unit/4,cube_unit/2);
    glScalef(0.7,0.5,0.5);
    glRotatef(90,1,0,0);
    glScalef(1,1,0.5);
    pillowCurve(1.0,1.0,1.0,1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void PillowPair(float gap)
{
    glPushMatrix();
    glTranslatef(gap,0,0);
    Pillow();
    glPopMatrix();

    glPushMatrix();
    Pillow();
    glPopMatrix();
}

void Bed(float bedWall, float pillowx, float pillowy, float pillowz)
{
    float translationX = 5*cube_unit-bedWall;
    float translationZ = -2*cube_unit;
    float drawerHeight = 0.6*cube_unit;


    float lengthx = bedX;
    float lengthz = bedZ;
    float lengthy = bedWall + bedWall + drawerHeight + drawerHeight + bedWall + pillowy;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex[27]);
    glPushMatrix();
    glTranslatef(lengthx/2,bedWall/2,lengthz/2 + bedWall);
    glScalef(lengthx,bedWall,lengthz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();
    lengthy += bedWall;

    glPushMatrix();
    glTranslatef(lengthx/2,bedWall/2+bedWall+drawerHeight,lengthz/2 + bedWall);
    glScalef(lengthx,bedWall,lengthz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();
    lengthy += bedWall;

    glBindTexture(GL_TEXTURE_2D,tex[24]);
    glPushMatrix();
    glTranslatef(lengthx/2,drawerHeight/2+bedWall,bedWall/2 + bedWall);
    glScalef(lengthx,drawerHeight,bedWall);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();
    lengthy += drawerHeight;

    glPushMatrix();
    glTranslatef(lengthx/2,drawerHeight/2+bedWall,lengthz-bedWall/2 + bedWall);
    glScalef(lengthx,drawerHeight,bedWall);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(lengthx/2,drawerHeight/2+bedWall,lengthz/2-bedWall/2 + bedWall);
    glScalef(lengthx,drawerHeight,bedWall);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D,tex[32]);
    glPushMatrix();
    glTranslatef(lengthx/2,drawerHeight/2+bedWall,(lengthz/2-2*bedWall)/2+bedWall + bedWall);
    glScalef(lengthx,drawerHeight,lengthz/2-2*bedWall);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(lengthx/2,drawerHeight/2+bedWall,(lengthz/2-1*bedWall)/2+bedWall+bedWall+(lengthz/2-2*bedWall) + bedWall);
    glScalef(lengthx,drawerHeight,lengthz/2-1*bedWall);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(0.0,0.5,0.0);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D,tex[34]);
    glPushMatrix();
    glTranslatef(lengthx/2,drawerHeight/2+bedWall+drawerHeight+bedWall,lengthz/2 + bedWall);
    glScalef(lengthx,drawerHeight,lengthz);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(0.0,0.5,1.0);
    glPopMatrix();
    lengthy += drawerHeight;

    glBindTexture(GL_TEXTURE_2D,tex[35]);
    glPushMatrix();
    glTranslatef(lengthx/2,bedWall/2+bedWall+drawerHeight+bedWall+drawerHeight,lengthz/4+lengthz/2 + bedWall);
    glScalef(lengthx,bedWall,lengthz/2);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,0.0,0.0);
    glPopMatrix();
    lengthy += bedWall;
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(lengthx/8-lengthx/16,bedWall+drawerHeight+bedWall+drawerHeight,bedWall);
    PillowPair(lengthx/2);
    glPopMatrix();
    lengthy += pillowy;


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex[32]);
    glPushMatrix();
    glTranslatef(lengthx/2,lengthy/2,bedWall/2);
    glScalef(lengthx,lengthy,bedWall);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,0.0,0.3);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}

void CeilingFan()
{
    glPushMatrix();
    glTranslatef(0,cube_unit,0);
    glScalef(0.5*cube_unit,1*cube_unit,0.5*cube_unit);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glRotatef(fanRotation,0,1,0);
    glTranslatef(2.5+cube_unit/2,0.1,0);
    glScalef(5,0.2,1);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(0.0,0.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glRotatef(fanRotation,0,1,0);
    glTranslatef(-2.5-cube_unit/2,0.1,0);
    glScalef(5,0.2,1);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(0.0,0.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glRotatef(fanRotation,0,1,0);
    glTranslatef(0,0.1,2.5+cube_unit/2);
    glScalef(1,0.2,5);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(0.0,0.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glRotatef(fanRotation,0,1,0);
    glTranslatef(0,0.1,-2.5-cube_unit/2);
    glScalef(1,0.2,5);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(0.0,0.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.25,0);
    glRotatef(fanRotation,0,1,0);
    glScalef(1,0.5,1);
    glTranslatef(-cube_unit/2,-cube_unit/2,-cube_unit/2);
    cube(1.0,1.0,0.0);
    glPopMatrix();
}

void axes()
{
    glPushMatrix();
    glTranslatef(2.5,0,0);
    glScalef(5,0.1,0.1);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(1.0,0.0,0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2.5,0);
    glScalef(0.1,5,0.1);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.0,1.0,0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,2.5);
    glScalef(0.1,0.1,5);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.0,0.0,1.0);
    glPopMatrix();
}

void manualCurve()
{
    int i, j;
    float x, y, z, r;				//current coordinates
    float x1, y1, z1, r1;			//next coordinates
    float theta;

    // my code starts
    if(totalPoints<=0)
        return;
    // my code ends
    const float startx = 0, endx = newPoints[totalPoints-1][0]/* endx = newPoints[totalPoints - 1][0]*/;
    //number of angular slices
    const float dx = (endx - startx) / nt;	//x step size
    const float dtheta = 2*M_PI / ntheta;		//angular step size

    float t=0;
    float dt=1.0/nt;
    float xyz[3];
    manualBezierCurve( t,  xyz);
    x = xyz[0];
    r = xyz[1];
    //rotate about z-axis
    float p1x,p1y,p1z,p2x,p2y,p2z;
    // my code start
//    glPointSize(3.0);
//    glBegin(GL_POINTS);
    glVertex3f(xyz[0],xyz[1],xyz[2]);
    // my code ends
    for ( i = 0; i < nt; ++i )  			//step through x
    {
        theta = 0;
        t+=dt;
        manualBezierCurve( t,  xyz);
        x1 = xyz[0];
        r1 = xyz[1];
        // my code starts
        y1 = r1*cos(theta);
//        glVertex3f(xyz[0],xyz[1],xyz[2]);

        //draw the surface composed of quadrilaterals by sweeping theta
        glBegin( GL_QUAD_STRIP );
        for ( j = 0; j <= ntheta; ++j )
        {
            theta += dtheta;
            double cosa = cos( theta );
            double sina = sin ( theta );
            y = r * cosa;
            y1 = r1 * cosa;	//current and next y
            z = r * sina;
            z1 = r1 * sina;	//current and next z

            //edge from point at x to point at next x
            glVertex3f (x, y, z);

            if(j>0)
            {
                setNormal(p1x,p1y,p1z,p2x,p2y,p2z,x, y, z);
            }
            else
            {
                p1x=x;
                p1y=y;
                p1z=z;
                p2x=x1;
                p2y=y1;
                p2z=z1;

            }
            glVertex3f (x1, y1, z1);

            //forms quad with next pair of points with incremented theta value
        }
        glEnd();
        x = x1;
        r = r1;
    } //for i
//    glEnd();

}

extern float vasePoints[][3];


void FlowerVase(float red, float green, float blue, float alpha)
{
    GLfloat no_mat[] = {0.0,0.0,0.0,1.0};
    GLfloat mat_ambient[] = {red,green,blue,alpha};
    GLfloat mat_diffuse[] = {red,green,blue,alpha};
    GLfloat mat_specular[] = {1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[] = {60};

    glMaterialfv(GL_FRONT, GL_AMBIENT,mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

    int i, j;
    float x, y, z, r;				//current coordinates
    float x1, y1, z1, r1;			//next coordinates
    float theta;

    // my code starts
//    if(totalPoints<=0)
//        return;
    // my code ends
    const float startx = 0, endx = vasePoints[totalVasePoints][0];/// endx = newPoints[totalPoints - 1][0];
    //number of angular slices
    const float dx = (endx - startx) / nt;	//x step size
    const float dtheta = 2*M_PI / ntheta;		//angular step size

    float t=0;
    float dt=1.0/nt;
    float xyz[3];
    newBezierCurve( t,  xyz);
    x = xyz[0];
    r = xyz[1];
    //rotate about z-axis
    float p1x,p1y,p1z,p2x,p2y,p2z;
    // my code start
//    glPointSize(3.0);
//    glBegin(GL_POINTS);
    glVertex3f(xyz[0],xyz[1],xyz[2]);
    // my code ends
    for ( i = 0; i < nt; ++i )  			//step through x
    {
        theta = 0;
        t+=dt;
        newBezierCurve( t,  xyz);
        x1 = xyz[0];
        r1 = xyz[1];
        // my code starts
        y1 = r1*cos(theta);
//        glVertex3f(xyz[0],xyz[1],xyz[2]);

        //draw the surface composed of quadrilaterals by sweeping theta
        glBegin( GL_QUAD_STRIP );
        for ( j = 0; j <= ntheta; ++j )
        {
            theta += dtheta;
            double cosa = cos( theta );
            double sina = sin ( theta );
            y = r * cosa;
            y1 = r1 * cosa;	//current and next y
            z = r * sina;
            z1 = r1 * sina;	//current and next z

            //edge from point at x to point at next x
            glVertex3f (x, y, z);

            if(j>0)
            {
                setNormal(p1x,p1y,p1z,p2x,p2y,p2z,x, y, z);
            }
            else
            {
                p1x=x;
                p1y=y;
                p1z=z;
                p2x=x1;
                p2y=y1;
                p2z=z1;

            }
            glVertex3f (x1, y1, z1);

            //forms quad with next pair of points with incremented theta value
        }
        glEnd();
        x = x1;
        r = r1;
    } //for i
//    glEnd();

}


