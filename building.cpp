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

void House()
{
    glPushMatrix();
    Floor(false,true,true,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,cube_unit + roomY,0);
    Floor(false,true,true,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, cube_unit + roomY + cube_unit + roomY,0);
    Floor2(false,true,false,1);
    glPopMatrix();

}

void Office()
{
    glPushMatrix();
    OfficeFloor(false,true,true,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,cube_unit + roomY,0);
    OfficeFloor2(false,true,false,1);
    glPopMatrix();
}
