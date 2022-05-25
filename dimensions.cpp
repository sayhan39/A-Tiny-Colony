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

float cube_unit = 1;

float lightx = -5*cube_unit;
float lighty = 5*cube_unit;
float lightz = 0*cube_unit;

float tableX=8*cube_unit;
float tableY=0.5*cube_unit;
float tableZ=6*cube_unit;

float EmployeeTableX=10*cube_unit;
float EmployeeTableY=0.5*cube_unit;
float EmployeeTableZ=6*cube_unit;

float HeadTableX = 25*cube_unit + cube_unit/4;
float HeadTableY = 6*cube_unit;
float HeadTableZ = 4*cube_unit;

float EmployeeTableChairX = EmployeeTableX;
float EmployeeTableChairY = EmployeeTableY;
float EmployeeTableChairZ = EmployeeTableZ+3.5*cube_unit;

float chairX=4*cube_unit;
float chairY=0.5*cube_unit;
float chairZ=4*cube_unit;

float tablechairX = tableX;
float tablechairY = tableY + chairY;
float tablechairZ = tableZ + chairZ;

float diningTableX = 4*tableX;
float diningTableY = tableY;
float diningTableZ = 2*tableZ;

float filingCabinetUnitx = 3*cube_unit;
float filingCabinetUnity = 3*cube_unit;
float filingCabinetUnitz = 4*cube_unit+cube_unit/2+cube_unit/2;

float FileCabinetdrawerOpen = 0.0;

float FileCabinetsingleDrawerOpen = 0.0;

float planksInBench = 4;

float gapInPieces = cube_unit/4;

float parkBenchx = 10*cube_unit;
float parkBenchz = planksInBench*cube_unit/2 + (planksInBench - 1)*gapInPieces;

float cabinetx = 6*cube_unit;
float cabinety = 0.5*cube_unit;
float cabinetz = 4*cube_unit;

float bedX = 6*cube_unit;
float bedZ = 10*cube_unit;

float lampY = 20;

float lampWidth = cube_unit/2;

float lampHandlex = 4*cube_unit;
float lampHandley = cube_unit/2;

float lampRadious = 2;

float numberOfLamps = 5;

float pathX = 20*cube_unit;

float footpathX = 5;

float roadX = footpathX + pathX + footpathX;

float roomX = 40;
float roomY = 20;
float roomZ = 40;

float stairWidth = 10*cube_unit;

float floorz = roomZ+roomZ;
float floorx = roomX+roomX+roomX;
float floory = roomY+cube_unit+cube_unit;

float officeFloorz = roomZ+roomZ;
float officeFloorx = roomX+roomX+roomX;
float officeFloory = roomY+cube_unit+cube_unit;

float stairHeight = roomY/2;

float groundx = 500*cube_unit;
float groundy = cube_unit;
float groundz = 500*cube_unit;

float doorHeight = 14*cube_unit;
float doorWidth = 7*cube_unit;

float grillHeight = 10*cube_unit;
float grillWidth = 10*cube_unit;

extern const int L = 20;

GLfloat controlpoints[L+1][3] =
{
    { 0.0, 0.0, 0.0}, { -0.3, 0.5, 0.0},
    { 0.1, 1.7, 0.0},{ 0.5, 1.5, 0.0},
    {1.0, 1.5, 0.0}, {1.4, 1.4, 0.0},
    {1.8, 0.4, 0.0},{2.2, 0.4, 0.0},
    {2.6, 1.5, 0.0}, {3.0, 1.4, 0.0},
    {3.4, 1.4, 0.0},{3.8, 1.4, 0.0},
    {4.2, 1.0, 0.0},{4.6, 1.0, 0.0},
    {5.0, 1.0, 0.0},{5.4, 1.0, 0.0},
    {5.8, 0.5, 0.0},{6.2, 0.5, 0.0},
    {6.6, 0.5, 0.0},{7.2, 0.2, 0.0},
    {6.8, 0.52, 0.0}
};

int totalVasePoints = 18;
GLfloat vasePoints[19][3] =
{
    {0.0250001,-4.22837e-008,13},{0.0500001,-0.65,13},
    {0.2,-0.8,13},{0.325,-0.9,13},
    {0.5,-0.975,13},{0.675,-1,13},
    {0.825,-1,13},{1.125,-1.05,13},
    {1.45,-1.05,13},{1.65,-1,13},
    {2.075,-1,13},{2.45,-0.9,13},
    {2.75,-0.75,13},{3.1,-0.7,13},
    {3.2,-0.7,13},{3.25,-0.775,13},
    {3.3,-0.8,13},{3.275,-0.85,13},
    {3.25,-0.85,13}
};


const int totalLegPoints = 6;
GLfloat legPoints[totalLegPoints+1][3]=
{
    {0,1,0},{1,1,0},
    {2,1,0},{3,1,0},
    {4,1,0},{5,1,0},
    {6,1,0}
};

const int totalToolTopPoints = 13;
GLfloat toolTopPoints[totalToolTopPoints+1][3]=
{
    {0.0250001,-4.22837e-008,13},{0.0250001,-0.275,13},
    {0.0750001,-0.65,13},{0.1,-0.95,13},
    {0.0750001,-1.5,13},{0.15,-1.7,13},
    {0.3,-1.775,13},{0.4,-1.725,13},
    {0.5,-1.55,13},{0.525,-1.2,13},
    {0.525,-0.775,13},{0.475,-0.425,13},
    {0.475,-0.2,13},{0.5,-3.65039e-008,13}
};

const int totalChairBackPoints1 = 12;
GLfloat chairBackPoints1[totalChairBackPoints1+1][3] =
{
    {-0.0749998,-4,13},{0.525,-3.775,13},
    {0.85,-3.6,13},{1.15,-3.45,13},
    {1.475,-3.55,13},{1.85,-3.7,13},
    {2.225,-3.73,13},{2.825,-3.77,13},
    {3.2,-3.81,13},{3.525,-3.86,13},
    {3.725,-3.91,13},{3.925,-3.96,13},
    {4.1,-4,13}
};

const int totalChairHandlePoints = 7;
GLfloat chairHandlePoints[totalChairHandlePoints+1][3] =
{
    {0.15,0.025,13},{0.9,-3.16367e-008,13},
    {1.35,-2.61611e-008,13},{2.15,0.075,13},
    {2.8,0.1,13},{3.9,0.2,13},
    {4.7,0.15,13},{4.95,1.76435e-008,13}
};

const int totalDeskTopPoints = 13;
GLfloat deskTopPoints[totalDeskTopPoints+1][3] =
{
    {0.125,0.1,13},{0.575,0.375,13},
    {1.225,0.475,13},{1.775,0.55,13},
    {2.3,0.475,13},{2.625,0.275,13},
    {2.875,0.125,13},{3.125,-4.56299e-009,13},
    {3.625,-0.025,13},{4.15,0.05,13},
    {4.65,0.2,13},{5.25,0.35,13},
    {5.8,0.425,13},{6.3,0.425,13}
};

const int totalPillowPoints = 16;
GLfloat pillowPoints[totalPillowPoints+1][3] =
{
    {0,0,13},{0.0250001,-0.025,13},
    {0.175,-0.3,13},
    {0.35,-0.475,13},{0.525,-0.625,13},
    {0.725,-0.7,13},{0.95,-0.725,13},
    {1.225,-0.775,13},{1.375,-0.775,13},
    {1.65,-0.7,13},{1.925,-0.575,13},
    {2.075,-0.5,13},{2.275,-0.4,13},
    {2.45,-0.25,13},{2.55,-0.15,13},
    {2.675,-1.00386e-008,13},{2.7,0,13}
};

const int totalBulbPoints = 9;
GLfloat bulbPoints[totalBulbPoints+1][3] =
{
    {-0.225,-1.725,13},{0.825,-1.725,13},
    {1.6,-2.1,13},{2,-2.85,13},
    {2.875,-3.45,13},{3.525,-3.7,13},
    {4.725,-3.65,13},{5.5,-3.375,13},
    {6.3,-2.45,13},{6.3,-0.075,13}
};

float wcsClkDn[3],wcsClkUp[3];
class point1
{
public:
    point1()
    {
        x=0;
        y=0;
    }
    int x;
    int y;
} clkpt[2];
int flag=0;
int clikd=0;
const int nt = 40;
const int ntheta = 20;
GLint viewport[4]; //var to hold the viewport info
GLdouble modelview[16]; //var to hold the modelview info
GLdouble projection[16]; //var to hold the projection matrix info

int totalPoints = 0;
vector<vector<GLfloat> >newPoints(totalPoints);
