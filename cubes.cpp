#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
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

static GLfloat cube_points[8][3] =
{
    {0,0,0},
    {0,0,cube_unit},
    {0,cube_unit,0},
    {0,cube_unit,cube_unit},

    {cube_unit,0,0},
    {cube_unit,0,cube_unit},
    {cube_unit,cube_unit,0},
    {cube_unit,cube_unit,cube_unit}
};

static GLubyte cube_surfaces[6][4] =
{
    {3,1,5,7},  //front
    {6,4,0,2},  //back
    {2,3,7,6},  //top
    {1,0,4,5},  //bottom
    {7,5,4,6},  //right
    {2,0,1,3}   //left
//    {0,2,6,4},
//    {1,3,7,5},
//    {0,4,5,1},
//    {2,6,7,3},
//    {0,1,3,2},
//    {4,5,7,6}
};

void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1,
                        GLfloat x2, GLfloat y2, GLfloat z2,
                        GLfloat x3, GLfloat y3, GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}

void cube(float red, float green, float blue, float a, float b, float c, float d, float alpha)// a:b<1 b:a>1 a>b a=1 b=b/a*a
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
//    glColor3f(red,green,blue);
    glBegin(GL_QUADS);
    for(GLint i=0; i<6; i++)
    {

        getNormal3p(cube_points[cube_surfaces[i][0]][0], cube_points[cube_surfaces[i][0]][1], cube_points[cube_surfaces[i][0]][2],
                    cube_points[cube_surfaces[i][1]][0], cube_points[cube_surfaces[i][1]][1], cube_points[cube_surfaces[i][1]][2],
                    cube_points[cube_surfaces[i][2]][0], cube_points[cube_surfaces[i][2]][1], cube_points[cube_surfaces[i][2]][2]);
        //glColor3f(colors[i][0],colors[i][1],colors[i][2]);
        glTexCoord2f(c,b);
        glVertex3fv(&cube_points[cube_surfaces[i][0]][0]);
        glTexCoord2f(c,d);
        glVertex3fv(&cube_points[cube_surfaces[i][1]][0]);
        glTexCoord2f(a,d);
        glVertex3fv(&cube_points[cube_surfaces[i][2]][0]);
        glTexCoord2f(a,b);
        glVertex3fv(&cube_points[cube_surfaces[i][3]][0]);
    }
    glEnd();
}

void Cube(float red, float green, float blue, float a, float b, float c, float d, char face, float alpha)// a:b<1 b:a>1 a>b a=1 b=b/a*a
{
//    a = mul*a;
//    b=mul*b;
//    c=mul*c;
//    d=mul*d;
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
//    glColor3f(red,green,blue);
    glBegin(GL_QUADS);
    for(GLint i=0; i<6; i++)
    {

        getNormal3p(cube_points[cube_surfaces[i][0]][0], cube_points[cube_surfaces[i][0]][1], cube_points[cube_surfaces[i][0]][2],
                    cube_points[cube_surfaces[i][1]][0], cube_points[cube_surfaces[i][1]][1], cube_points[cube_surfaces[i][1]][2],
                    cube_points[cube_surfaces[i][2]][0], cube_points[cube_surfaces[i][2]][1], cube_points[cube_surfaces[i][2]][2]);
        //glColor3f(colors[i][0],colors[i][1],colors[i][2]);
        if(face == 'f')
        {
            glTexCoord2f(c,b);
            glVertex3fv(&cube_points[cube_surfaces[i][0]][0]);
            glTexCoord2f(c,d);
            glVertex3fv(&cube_points[cube_surfaces[i][1]][0]);
            glTexCoord2f(a,d);
            glVertex3fv(&cube_points[cube_surfaces[i][2]][0]);
            glTexCoord2f(a,b);
            glVertex3fv(&cube_points[cube_surfaces[i][3]][0]);
        }
        else if(face == 't')
        {
            glTexCoord2f(c,b);
            glVertex3fv(&cube_points[cube_surfaces[i][0]][0]);
            glTexCoord2f(c,d);
            glVertex3fv(&cube_points[cube_surfaces[i][1]][0]);
            glTexCoord2f(a,d);
            glVertex3fv(&cube_points[cube_surfaces[i][2]][0]);
            glTexCoord2f(a,b);
            glVertex3fv(&cube_points[cube_surfaces[i][3]][0]);
        }
//        glTexCoord2f(c,b);
//        glVertex3fv(&cube_points[cube_surfaces[i][0]][0]);
//        glTexCoord2f(c,d);
//        glVertex3fv(&cube_points[cube_surfaces[i][1]][0]);
//        glTexCoord2f(a,d);
//        glVertex3fv(&cube_points[cube_surfaces[i][2]][0]);
//        glTexCoord2f(a,b);
//        glVertex3fv(&cube_points[cube_surfaces[i][3]][0]);
    }
    glEnd();
}

void increseCubeUnit()
{
    cube_unit++;
    cube_points[1][2] = cube_points[2][1] = cube_points[3][1] =
    cube_points[3][2] = cube_points[4][0] = cube_points[5][0] =
    cube_points[5][2] = cube_points[6][0] = cube_points[6][1] =
    cube_points[7][0] = cube_points[7][1] = cube_points[7][2] = cube_unit;
}
