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


extern float lightx;
extern float lighty;
extern float lightz;
extern float eyex;
extern float eyey;
extern float eyez;
extern bool keyStates[];

void lighting(bool e, GLenum lightNumber)
{
    GLfloat no_light[] = {0.0,0.0,0.0,1.0};
    GLfloat light_ambient[] = {0.2,0.2,0.2,1.0};
    GLfloat light_diffuse[] = {1.0,1.0,1.0,1.0};
    GLfloat light_specular[] = {0.5,0.5,0.5,1.0};
    GLfloat light_position[] = {eyex,eyey,eyez,1.0};

    if(keyStates['l'])
    {
        glEnable(lightNumber);
    }
    else
    {
        glDisable(lightNumber);
    }

    glLightfv(lightNumber, GL_AMBIENT, light_ambient);
    glLightfv(lightNumber, GL_DIFFUSE, light_diffuse);
    glLightfv(lightNumber, GL_SPECULAR, light_specular);
    glLightfv(lightNumber, GL_POSITION, light_position);
}

/*void Spotlighting(GLenum lightNumber)
{
    GLfloat no_light[] = {0.0,0.0,0.0,1.0};
    GLfloat light_ambient[] = {0.2,0.2,0.2,1.0};
    GLfloat light_diffuse[] = {1.0,1.0,1.0,1.0};
    GLfloat light_specular[] = {0.5,0.5,0.5,1.0};
    GLfloat light_position[] = {7.65,17,-63,1.0};

    if(spotLightSwitch)
        glEnable(lightNumber);
    else
        glDisable(lightNumber);

    const GLfloat spot_cutoff = 10.0;
    GLfloat l_spt[] = {7.65,0,-63,1.0};
    GLfloat spt_ct[] = {spot_cutoff};
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, l_spt);
    glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, spt_ct);

    glLightfv(lightNumber, GL_AMBIENT, light_ambient);
    if(ambientLightSwitch)
        glLightfv(lightNumber, GL_AMBIENT, no_light);

    glLightfv(lightNumber, GL_DIFFUSE, light_diffuse);
    if(diffuseLightSwitch)
        glLightfv(lightNumber, GL_DIFFUSE, no_light);

    glLightfv(lightNumber, GL_SPECULAR, light_specular);
    if(specularLightSwitch)
        glLightfv(lightNumber, GL_SPECULAR, no_light);

    glLightfv(lightNumber, GL_POSITION, light_position);
}*/

void RoomLight(GLenum lightNumber)
{
    GLfloat no_light[] = {0.0,0.0,0.0,1.0};
    GLfloat light_ambient[] = {0.2,0.2,0.2,1.0};
    GLfloat light_diffuse[] = {1.0,1.0,1.0,1.0};
    GLfloat light_specular[] = {0.5,0.5,0.5,1.0};
    GLfloat light_position[] = {eyex,eyey,eyez,1.0};

    if(roomLightSwitch)
        glEnable(lightNumber);
    else if(!roomLightSwitch)
        glDisable(lightNumber);

    if(eyex>-144 && eyex<-106 && eyey>2 && eyey<21 && eyez<-64 && eyez>-101)
    {
        light_position[0] = -143;
        light_position[1] = 18;
        light_position[2] = -83;
    }
    else if(eyex>-144 && eyex<-106 && eyey>2 && eyey<21 && eyez<-25 && eyez>-64)
    {
        light_position[0] = -143;
        light_position[1] = 18;
        light_position[2] = -43;
    }
    else if(eyex>-106 && eyex<-67 && eyey>2 && eyey<21 && eyez<-64 && eyez>-101)
    {
        light_position[0] = -103;
        light_position[1] = 18;
        light_position[2] = -83;
    }
    else if(eyex>-106 && eyex<-67 && eyey>2 && eyey<21 && eyez<-25 && eyez>-64)
    {
        light_position[0] = -103;
        light_position[1] = 18;
        light_position[2] = -43;
    }
    else if(eyex>-67 && eyex<-27 && eyey>2 && eyey<21 && eyez<-64 && eyez>-101)
    {
        light_position[0] = -27;
        light_position[1] = 18;
        light_position[2] = -83;
    }
    else if(eyex>-67 && eyex<-27 && eyey>2 && eyey<21 && eyez<-25 && eyez>-64)
    {
        light_position[0] = -27;
        light_position[1] = 18;
        light_position[2] = -43;
    }
    else
    {
        glDisable(lightNumber);
    }

//    if(keyStates['l'])
//    {
//        glEnable(lightNumber);
//    }
//    else
//    {
//        glDisable(lightNumber);
//    }

    glLightfv(lightNumber, GL_AMBIENT, light_ambient);
    if(ambientLightSwitch)
        glLightfv(lightNumber, GL_AMBIENT, no_light);

    glLightfv(lightNumber, GL_DIFFUSE, light_diffuse);
    if(diffuseLightSwitch)
        glLightfv(lightNumber, GL_DIFFUSE, no_light);

    glLightfv(lightNumber, GL_SPECULAR, light_specular);
    if(specularLightSwitch)
        glLightfv(lightNumber, GL_SPECULAR, no_light);

    glLightfv(lightNumber, GL_POSITION, light_position);
}

void OfficeLight(GLenum lightNumber)
{
    GLfloat no_light[] = {0.0,0.0,0.0,1.0};
    GLfloat light_ambient[] = {0.2,0.2,0.2,1.0};
    GLfloat light_diffuse[] = {1.0,1.0,1.0,1.0};
    GLfloat light_specular[] = {0.5,0.5,0.5,1.0};
    GLfloat light_position[] = {eyex,eyey,eyez,1.0};

    if(officeLightSwitch)
        glEnable(lightNumber);
    else if(!officeLightSwitch)
        glDisable(lightNumber);

    if(eyex>27 && eyex<67 && eyey>2 && eyey<21 && eyez<-74 && eyez>-111)
    {
        light_position[0] = 27;
        light_position[1] = 18;
        light_position[2] = -93;
    }
    else if(eyex>67 && eyex<106 && eyey>2 && eyey<21 && eyez<-35 && eyez>-71)
    {
        light_position[0] = 67;
        light_position[1] = 18;
        light_position[2] = -53;
    }
    else if(eyex>67 && eyex<106 && eyey>2 && eyey<21 && eyez<-71 && eyez>-111)
    {
        light_position[0] = 85;
        light_position[1] = 18;
        light_position[2] = -93;
    }
    else if(eyex>106 && eyex<144 && eyey>2 && eyey<21 && eyez<-35 && eyez>-74)
    {
        light_position[0] = 143;
        light_position[1] = 18;
        light_position[2] = -53;
    }
    else if(eyex>106 && eyex<144 && eyey>2 && eyey<21 && eyez<-74 && eyez>-111)
    {
        light_position[0] = 143;
        light_position[1] = 18;
        light_position[2] = -93;
    }
    else
    {
        glDisable(lightNumber);
    }

//    if(keyStates['l'])
//    {
//        glEnable(lightNumber);
//    }
//    else
//    {
//        glDisable(lightNumber);
//    }

    glLightfv(lightNumber, GL_AMBIENT, light_ambient);
    if(ambientLightSwitch)
        glLightfv(lightNumber, GL_AMBIENT, no_light);

    glLightfv(lightNumber, GL_DIFFUSE, light_diffuse);
    if(diffuseLightSwitch)
        glLightfv(lightNumber, GL_DIFFUSE, no_light);

    glLightfv(lightNumber, GL_SPECULAR, light_specular);
    if(specularLightSwitch)
        glLightfv(lightNumber, GL_SPECULAR, no_light);

    glLightfv(lightNumber, GL_POSITION, light_position);
}

void directionLight(GLenum lightNumber)
{
    GLfloat no_light[] = {0.0,0.0,0.0,1.0};
    GLfloat light_ambient[] = {0.8,0.8,0.8,1.0};
    GLfloat light_diffuse[] = {1.0,1.0,1.0,1.0};
    GLfloat light_specular[] = {0.5,0.5,0.5,1.0};
    GLfloat light_position[] = {lightx,lighty,lightz,1.0};

    glEnable(lightNumber);

    glLightfv(lightNumber, GL_AMBIENT, light_ambient);
    glLightfv(lightNumber, GL_DIFFUSE, light_diffuse);
    glLightfv(lightNumber, GL_SPECULAR, light_specular);
    glLightfv(lightNumber, GL_POSITION, light_position);
}
