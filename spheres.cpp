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


void sphere(GLfloat ared, GLfloat agreen, GLfloat ablue, float radious)
{
    GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
    //GLfloat mat_ambient[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_ambient[] = {ared, agreen, ablue, 1.0};
    //GLfloat mat_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_diffuse[] = {ared, agreen, ablue, 1.0};
    GLfloat mat_specular[] = {1.0,1.0,1.0,1.0};
    GLfloat mat_emission[] = {ared, agreen, ablue, 1.0};
    GLfloat mat_shininess[] = {30};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

    glutSolidSphere(radious,radious*10,radious*10);
}
