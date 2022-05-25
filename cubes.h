#ifndef CUBES_H
#define CUBES_H

using namespace std;



void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1,
                        GLfloat x2, GLfloat y2, GLfloat z2,
                        GLfloat x3, GLfloat y3, GLfloat z3);

void cube(float red, float green, float blue, float a=1, float b=1, float c=0, float d=0, float alpha=1);

void Cube(float red, float green, float blue, float a=1, float b=1, float c=0, float d=0, char face='f', float alpha=1.0);

void increseCubeUnit();

#endif // CUBES_H
