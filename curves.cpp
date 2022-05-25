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

extern GLfloat *controlpoints[];
//extern GLfloat *vasePoints[];

void scsToWcs(float sx,float sy, float wcsv[3] )
{

    GLfloat winX, winY, winZ; //variables to hold screen x,y,z coordinates
    GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates

    //glGetDoublev( GL_MODELVIEW_MATRIX, modelview ); //get the modelview info
    glGetDoublev( GL_PROJECTION_MATRIX, projection ); //get the projection matrix info
    glGetIntegerv( GL_VIEWPORT, viewport ); //get the viewport info

    winX = sx;
    winY = (float)viewport[3] - (float)sy;
    winZ = 0;

    //get the world coordinates from the screen coordinates
    gluUnProject( winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);
    wcsv[0]=worldX;
    wcsv[1]=worldY;
    wcsv[2]=worldZ;
}


long long nCr(int n, int r)
{
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

void BezierCurve ( double t,  float xy[2])
{
    double y=0;
    double x=0;
    t=t>1.0?1.0:t;
    cout<<"L :"<<L<<endl;
    for(int i=0; i<=L; i++)
    {
        int ncr=nCr(L,i);
        double oneMinusTpow=pow(1-t,double(L-i));
        double tPow=pow(t,double(i));
        double coef=oneMinusTpow*tPow*ncr;
        x+=coef*controlpoints[i][0];
        y+=coef*controlpoints[i][1];

    }
    xy[0] = float(x);
    xy[1] = float(y);

    //return y;
}

void manualBezierCurve ( double t, float xyz[3])
{
    double z=0;
    double y=0;
    double x=0;
    t=t>1.0?1.0:t;
    int k= totalPoints>20?totalPoints:20;
    for(int i=0;i<=totalPoints-1; i++)
    {
//        cout<<"L: "<<totalPoints-1<<endl;
        int ncr = nCr(totalPoints-1, i);
        double oneMinusTpow=pow(1-t,double(totalPoints-1-i));
        double tPow=pow(t,double(i));
        double coef=oneMinusTpow*tPow*ncr;
        x+=coef*newPoints[i][0];
        y+=coef*newPoints[i][1];
        z+=coef*newPoints[i][2];
    }
    xyz[0] = float(x);
    xyz[1] = float(y);
    xyz[2] = float(z);
}

extern GLfloat vasePoints[][3];

void newBezierCurve ( double t,  float xyz[3])
{
    double z=0;
    double y=0;
    double x=0;
    t=t>1.0?1.0:t;
    for(int i=0; i<=totalVasePoints; i++)
    {
        int ncr=nCr(totalVasePoints,i);
        double oneMinusTpow=pow(1-t,double(totalVasePoints-i));
        double tPow=pow(t,double(i));
        double coef=oneMinusTpow*tPow*ncr;
        x+=coef*vasePoints[i][0];
        y+=coef*vasePoints[i][1];
        z+=coef*vasePoints[i][2];
    }
    xyz[0] = float(x);
    xyz[1] = float(y);
    xyz[2] = float(z);

    //return y;
}

extern GLfloat legPoints[][3];

void legBezierCurve ( double t,  float xyz[3])
{
    double z=0;
    double y=0;
    double x=0;
    t=t>1.0?1.0:t;
    for(int i=0; i<=totalLegPoints; i++)
    {
        int ncr=nCr(totalLegPoints,i);
        double oneMinusTpow=pow(1-t,double(totalLegPoints-i));
        double tPow=pow(t,double(i));
        double coef=oneMinusTpow*tPow*ncr;
        x+=coef*legPoints[i][0];
        y+=coef*legPoints[i][1];
        z+=coef*legPoints[i][2];
    }
    xyz[0] = float(x);
    xyz[1] = float(y);
    xyz[2] = float(z);

    //return y;
}

extern GLfloat toolTopPoints[][3];

void toolTopBezierCurve ( double t,  float xyz[3])
{
    double z=0;
    double y=0;
    double x=0;
    t=t>1.0?1.0:t;
    for(int i=0; i<=totalToolTopPoints; i++)
    {
        int ncr=nCr(totalToolTopPoints,i);
        double oneMinusTpow=pow(1-t,double(totalToolTopPoints-i));
        double tPow=pow(t,double(i));
        double coef=oneMinusTpow*tPow*ncr;
        x+=coef*toolTopPoints[i][0];
        y+=coef*toolTopPoints[i][1];
        z+=coef*toolTopPoints[i][2];
    }
    xyz[0] = float(x);
    xyz[1] = float(y);
    xyz[2] = float(z);

    //return y;
}

extern GLfloat chairBackPoints1[][3];
void chairbackBezierCurve ( double t,  float xyz[3])
{
    double z=0;
    double y=0;
    double x=0;
    t=t>1.0?1.0:t;
    for(int i=0; i<=totalChairBackPoints1; i++)
    {
        int ncr=nCr(totalChairBackPoints1,i);
        double oneMinusTpow=pow(1-t,double(totalChairBackPoints1-i));
        double tPow=pow(t,double(i));
        double coef=oneMinusTpow*tPow*ncr;
        x+=coef*chairBackPoints1[i][0];
        y+=coef*chairBackPoints1[i][1];
        z+=coef*chairBackPoints1[i][2];
    }
    xyz[0] = float(x);
    xyz[1] = float(y);
    xyz[2] = float(z);

    //return y;
}

extern GLfloat chairHandlePoints[][3];
void chairHandleBezierCurve ( double t,  float xyz[3])
{
    double z=0;
    double y=0;
    double x=0;
    t=t>1.0?1.0:t;
    for(int i=0; i<=totalChairHandlePoints; i++)
    {
        int ncr=nCr(totalChairHandlePoints,i);
        double oneMinusTpow=pow(1-t,double(totalChairHandlePoints-i));
        double tPow=pow(t,double(i));
        double coef=oneMinusTpow*tPow*ncr;
        x+=coef*chairHandlePoints[i][0];
        y+=coef*chairHandlePoints[i][1];
        z+=coef*chairHandlePoints[i][2];
    }
    xyz[0] = float(x);
    xyz[1] = float(y);
    xyz[2] = float(z);

    //return y;
}

extern GLfloat deskTopPoints[][3];
void deskTopBezierCurve ( double t,  float xyz[3])
{
    double z=0;
    double y=0;
    double x=0;
    t=t>1.0?1.0:t;
    for(int i=0; i<=totalDeskTopPoints; i++)
    {
        int ncr=nCr(totalDeskTopPoints,i);
        double oneMinusTpow=pow(1-t,double(totalDeskTopPoints-i));
        double tPow=pow(t,double(i));
        double coef=oneMinusTpow*tPow*ncr;
        x+=coef*deskTopPoints[i][0];
        y+=coef*deskTopPoints[i][1];
        z+=coef*deskTopPoints[i][2];
    }
    xyz[0] = float(x);
    xyz[1] = float(y);
    xyz[2] = float(z);

    //return y;
}

extern GLfloat pillowPoints[][3];
void pillowBezierCurve ( double t,  float xyz[3])
{
    double z=0;
    double y=0;
    double x=0;
    t=t>1.0?1.0:t;
    for(int i=0; i<=totalPillowPoints; i++)
    {
        int ncr=nCr(totalPillowPoints,i);
        double oneMinusTpow=pow(1-t,double(totalPillowPoints-i));
        double tPow=pow(t,double(i));
        double coef=oneMinusTpow*tPow*ncr;
        x+=coef*pillowPoints[i][0];
        y+=coef*pillowPoints[i][1];
        z+=coef*pillowPoints[i][2];
    }
    xyz[0] = float(x);
    xyz[1] = float(y);
    xyz[2] = float(z);

    //return y;
}

extern GLfloat bulbPoints[][3];
void bulbBezierCurve ( double t,  float xyz[3])
{
    double z=0;
    double y=0;
    double x=0;
    t=t>1.0?1.0:t;
    for(int i=0; i<=totalBulbPoints; i++)
    {
        int ncr=nCr(totalBulbPoints,i);
        double oneMinusTpow=pow(1-t,double(totalBulbPoints-i));
        double tPow=pow(t,double(i));
        double coef=oneMinusTpow*tPow*ncr;
        x+=coef*bulbPoints[i][0];
        y+=coef*bulbPoints[i][1];
        z+=coef*bulbPoints[i][2];
    }
    xyz[0] = float(x);
    xyz[1] = float(y);
    xyz[2] = float(z);

    //return y;
}

void legCurve(float red, float green, float blue, float alpha)
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
    const float startx = 0, endx = legPoints[totalLegPoints][0]/* endx = newPoints[totalPoints - 1][0]*/;
    //number of angular slices
    const float dx = (endx - startx) / nt;	//x step size
    const float dtheta = 2*M_PI / ntheta;		//angular step size

    float t=0;
    float dt=1.0/nt;
    float xyz[3];
    legBezierCurve( t,  xyz);
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
        legBezierCurve( t,  xyz);
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
//            glVertex3f(x,0,z);

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
    glEnd();

}

void toolTopCurve(float red, float green, float blue, float alpha)
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
    const float startx = 0, endx = toolTopPoints[totalToolTopPoints][0]/* endx = newPoints[totalPoints - 1][0]*/;
    //number of angular slices
    const float dx = (endx - startx) / nt;	//x step size
    const float dtheta = 2*M_PI / ntheta;		//angular step size

    float t=0;
    float dt=1.0/nt;
    float xyz[3];
    toolTopBezierCurve( t,  xyz);
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
        toolTopBezierCurve( t,  xyz);
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
//            glVertex3f(x,0,z);

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

void chairBackCurve(float red, float green, float blue, float alpha)
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

    const float startx = 0, endx = chairBackPoints1[totalChairBackPoints1-1][0]/* endx = newPoints[totalPoints - 1][0]*/;

    //number of angular slices
    const float dx = (endx - startx) / nt;	//x step size
    const float dtheta = 2*M_PI / ntheta;		//angular step size

    float t=0;
    float dt=1.0/nt;
    float xyz[3];
    chairbackBezierCurve( t,  xyz);
    x = xyz[0];
    r = xyz[1];
    //rotate about z-axis
    float p1x,p1y,p1z,p2x,p2y,p2z;

    glVertex3f(xyz[0],xyz[1],xyz[2]);
    for ( i = 0; i < nt; ++i )  			//step through x
    {
        theta = 0;
        t+=dt;
        chairbackBezierCurve( t,  xyz);
        x1 = xyz[0];
        r1 = xyz[1];
        y1 = r1*cos(theta);

        //draw the surface composed of quadrilaterals by sweeping theta
        if(i==0 || i==nt-1)
            glLineWidth(3);
        else
            glLineWidth(1);

        glBegin( GL_LINE_STRIP );
        double cosa = cos( dtheta );
        double sina = sin ( dtheta );
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

        for(float b=0; b<4; b+=0.1)
        {
            glVertex3f (x, y, z+b);
            glVertex3f (x1, y1, z1+b);
        }

//        for(int b=3; b>=0; b--)
//        {
//            glVertex3f(x, y-0.2, z+b);
//            glVertex3f(x1, y1-0.2, z1+b);
//        }

        glLineWidth(3);
        glVertex3f (x, y, z);
        glVertex3f (x1, y1, z1);

        //forms quad with next pair of points with incremented theta value

        glEnd();
        x = x1;
        r = r1;
    } //for i

}

void chairHandleCurve(float red, float green, float blue, float alpha)
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
    const float startx = 0, endx = chairHandlePoints[totalChairHandlePoints-1][0]/* endx = newPoints[totalPoints - 1][0]*/;
    //number of angular slices
    const float dx = (endx - startx) / nt;	//x step size
    const float dtheta = 2*M_PI / ntheta;		//angular step size

    float t=0;
    float dt=1.0/nt;
    float xyz[3];
    chairHandleBezierCurve( t,  xyz);
    x = xyz[0];
    r = xyz[1];
    //rotate about z-axis
    float p1x,p1y,p1z,p2x,p2y,p2z;
    // my code start
//    glPointSize(3.0);
//    glBegin(GL_POINTS);
    float height = 0.5;
    float width = 0.5;
    bool yes=true;
    int oldx,oldy,oldz,oldx1,oldy1,oldz1;
    glVertex3f(xyz[0],xyz[1],xyz[2]);
    // my code ends
    for ( i = 0; i < nt; ++i )  			//step through x
    {
        theta = 0;
        t+=dt;
        chairHandleBezierCurve( t,  xyz);
        x1 = xyz[0];
        r1 = xyz[1];
        // my code starts
        y1 = r1*cos(theta);
//        glVertex3f(xyz[0],xyz[1],xyz[2]);

        //draw the surface composed of quadrilaterals by sweeping theta
        glBegin( GL_QUAD_STRIP );
        for ( j = 0; j <= 0; ++j )
        {
            theta += dtheta;
            double cosa = cos( theta );
            double sina = sin ( theta );
            y = r * cosa;
            y1 = r1 * cosa;	//current and next y
            z = r * sina;
            z1 = r1 * sina;	//current and next z

            if(yes)
            {
                oldx=x;
                oldy=y;
                oldz=z;
                yes=!yes;
            }

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

            for(float b=0; b<width; b+=0.1)
            {
                glVertex3f(x,y,z+b);
                glVertex3f(x1,y1,z1+b);
            }

            glVertex3f(x,y+height,z+width);
            glVertex3f(x1,y1+height,z1+width);

            for(float b=width; b>0; b-=0.1)
            {
                glVertex3f(x,y+height,z+b);
                glVertex3f(x1,y1+height,z1+b);
            }

            glVertex3f(x,y,z);
            glVertex3f(x1,y1,z1);


            //forms quad with next pair of points with incremented theta value
        }
        glEnd();

        x = x1;
        r = r1;
    } //for i
//    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(x1,y1,z1);
    glVertex3f(x1,y1,z1+width);
    glVertex3f(x1,y1+height,z1+width);
    glVertex3f(x1,y1+height,z1);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(oldx1,oldy1,oldz1);
    glVertex3f(oldx1,oldy1,oldz1+width);
    glVertex3f(oldx1,oldy1-height,oldz1+width);
    glVertex3f(oldx1,oldy1-height,oldz1);
    glEnd();

}

void deskTopCurve(float red, float green, float blue, float alpha)
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
    const float startx = 0, endx = deskTopPoints[totalDeskTopPoints-1][0]/* endx = newPoints[totalPoints - 1][0]*/;
    //number of angular slices
    const float dx = (endx - startx) / nt;	//x step size
    const float dtheta = 2*M_PI / ntheta;		//angular step size

    float t=0;
    float dt=1.0/nt;
    float xyz[3];
    deskTopBezierCurve( t,  xyz);
    x = xyz[0];
    r = xyz[1];
    //rotate about z-axis
    float p1x,p1y,p1z,p2x,p2y,p2z;
    // my code start
//    glPointSize(3.0);
//    glBegin(GL_POINTS);
    float height = 4;
    float width = 0.5;
    bool yes=true;
    int oldx,oldy,oldz,oldx1,oldy1,oldz1;
    glVertex3f(xyz[0],xyz[1],xyz[2]);
    // my code ends
    for ( i = 0; i < nt; ++i )  			//step through x
    {
        theta = 0;
        t+=dt;
        deskTopBezierCurve( t,  xyz);
        x1 = xyz[0];
        r1 = xyz[1];
        // my code starts
        y1 = r1*cos(theta);
//        glVertex3f(xyz[0],xyz[1],xyz[2]);

        //draw the surface composed of quadrilaterals by sweeping theta
        glBegin( GL_QUAD_STRIP );
        for ( j = 0; j <= 0; ++j )
        {
            theta += dtheta;
            double cosa = cos( theta );
            double sina = sin ( theta );
            y = r * cosa;
            y1 = r1 * cosa;	//current and next y
            z = r * sina;
            z1 = r1 * sina;	//current and next z

            if(yes)
            {
                oldx=x;
                oldy=y;
                oldz=z;
                yes=!yes;
            }

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

            for(float b=0; b<width; b+=0.1)
            {
                glVertex3f(x,y,z+b);
                glVertex3f(x1,y1,z1+b);
            }

            glVertex3f(x,y+height,z+width);
            glVertex3f(x1,y1+height,z1+width);

            for(float b=width; b>0; b-=0.1)
            {
                glVertex3f(x,y+height,z+b);
                glVertex3f(x1,y1+height,z1+b);
            }

            glVertex3f(x,y,z);
            glVertex3f(x1,y1,z1);


            //forms quad with next pair of points with incremented theta value
        }
        glEnd();

        x = x1;
        r = r1;
    } //for i
//    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(x1,y1,z1);
    glVertex3f(x1,y1,z1+width);
    glVertex3f(x1,y1+height,z1+width);
    glVertex3f(x1,y1+height,z1);
    glEnd();

//    glBegin(GL_QUADS);
//    glVertex3f(oldx1,oldy1,oldz1);
//    glVertex3f(oldx1,oldy1,oldz1+width);
//    glVertex3f(oldx1,oldy1-height,oldz1+width);
//    glVertex3f(oldx1,oldy1-height,oldz1);
//    glEnd();

}

void pillowCurve(float red, float green, float blue, float alpha)
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
    const float startx = 0, endx = pillowPoints[totalPillowPoints-1][0]/* endx = newPoints[totalPoints - 1][0]*/;
    //number of angular slices
    const float dx = (endx - startx) / nt;	//x step size
    const float dtheta = 2*M_PI / ntheta;		//angular step size

    float t=0;
    float dt=1.0/nt;
    float xyz[3];
    pillowBezierCurve( t,  xyz);
    x = xyz[0];
    r = xyz[1];
    //rotate about z-axis
    float p1x,p1y,p1z,p2x,p2y,p2z;
    // my code start
//    glPointSize(3.0);
//    glBegin(GL_POINTS);
    float height = 2;
    float width = 1;
    bool yes=true;
    int oldx,oldy,oldz,oldx1,oldy1,oldz1;
    glVertex3f(xyz[0],xyz[1],xyz[2]);
    // my code ends
    for ( i = 0; i < nt; ++i )  			//step through x
    {
        theta = 0;
        t+=dt;
        pillowBezierCurve( t,  xyz);
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

            if(yes)
            {
                oldx=x;
                oldy=y;
                oldz=z;
                yes=!yes;
            }

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

            for(float b=0; b<width; b+=0.1)
            {
                glVertex3f(x,y,z+b);
                glVertex3f(x1,y1,z1+b);
            }

            glVertex3f(x,y+height,z+width);
            glVertex3f(x1,y1+height,z1+width);

            for(float b=width; b>0; b-=0.1)
            {
                glVertex3f(x,y+height,z+b);
                glVertex3f(x1,y1+height,z1+b);
            }

            glVertex3f(x,y,z);
            glVertex3f(x1,y1,z1);


            //forms quad with next pair of points with incremented theta value
        }
        glEnd();

        x = x1;
        r = r1;
    } //for i
//    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(x1,y1,z1);
    glVertex3f(x1,y1,z1+width);
    glVertex3f(x1,y1+height,z1+width);
    glVertex3f(x1,y1+height,z1);
    glEnd();

//    glBegin(GL_QUADS);
//    glVertex3f(oldx1,oldy1,oldz1);
//    glVertex3f(oldx1,oldy1,oldz1+width);
//    glVertex3f(oldx1,oldy1-height,oldz1+width);
//    glVertex3f(oldx1,oldy1-height,oldz1);
//    glEnd();

}

void bulbCurve(float red, float green, float blue, float alpha)
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
    const float startx = 0, endx = bulbPoints[totalBulbPoints-1][0]/* endx = newPoints[totalPoints - 1][0]*/;
    //number of angular slices
    const float dx = (endx - startx) / nt;	//x step size
    const float dtheta = 2*M_PI / ntheta;		//angular step size

    float t=0;
    float dt=1.0/nt;
    float xyz[3];
    bulbBezierCurve( t,  xyz);
    x = xyz[0];
    r = xyz[1];
    //rotate about z-axis
    float p1x,p1y,p1z,p2x,p2y,p2z;
    // my code start
//    glPointSize(3.0);
//    glBegin(GL_POINTS);
    float height = 2;
    float width = 1;
    bool yes=true;
    int oldx,oldy,oldz,oldx1,oldy1,oldz1;
    glVertex3f(xyz[0],xyz[1],xyz[2]);
    // my code ends
    for ( i = 0; i < nt; ++i )  			//step through x
    {
        theta = 0;
        t+=dt;
        bulbBezierCurve( t,  xyz);
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

            if(yes)
            {
                oldx=x;
                oldy=y;
                oldz=z;
                yes=!yes;
            }

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

//            for(float b=0; b<width; b+=0.1)
//            {
//                glVertex3f(x,y,z+b);
//                glVertex3f(x1,y1,z1+b);
//            }
//
//            glVertex3f(x,y+height,z+width);
//            glVertex3f(x1,y1+height,z1+width);
//
//            for(float b=width; b>0; b-=0.1)
//            {
//                glVertex3f(x,y+height,z+b);
//                glVertex3f(x1,y1+height,z1+b);
//            }
//
//            glVertex3f(x,y,z);
//            glVertex3f(x1,y1,z1);


            //forms quad with next pair of points with incremented theta value
        }
        glEnd();

        x = x1;
        r = r1;
    } //for i
//    glEnd();
//    glBegin(GL_QUADS);
//    glVertex3f(x1,y1,z1);
//    glVertex3f(x1,y1,z1+width);
//    glVertex3f(x1,y1+height,z1+width);
//    glVertex3f(x1,y1+height,z1);
//    glEnd();

//    glBegin(GL_QUADS);
//    glVertex3f(oldx1,oldy1,oldz1);
//    glVertex3f(oldx1,oldy1,oldz1+width);
//    glVertex3f(oldx1,oldy1-height,oldz1+width);
//    glVertex3f(oldx1,oldy1-height,oldz1);
//    glEnd();

}

void setNormal(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
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

    glNormal3f(-Nx,-Ny,-Nz);
}
