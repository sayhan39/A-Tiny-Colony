#ifndef CURVES_H
#define CURVES_H

void scsToWcs(float sx,float sy, float wcsv[3] );

long long nCr(int n, int r);

void BezierCurve ( double t,  float xy[2]);

void manualBezierCurve ( double t, float xyz[3]);

void newBezierCurve ( double t,  float xyz[3]);

void legBezierCurve ( double t,  float xyz[3]);

void legCurve(float red=1.0, float green=1.0, float blue=1.0, float alpha=1.0);

void toolTopBezierCurve ( double t,  float xyz[3]);

void toolTopCurve(float red=1.0, float green=1.0, float blue=1.0, float alpha=1.0);

void chairbackBezierCurve(double t, float xyz[3]);

void chairBackCurve(float red=1.0, float green=1.0, float blue=1.0, float alpha=1.0);

void chairHandleBezierCurve ( double t,  float xyz[3]);

void chairHandleCurve(float red=1.0, float green=1.0, float blue=1.0, float alpha=1.0);

void deskTopBezierCurve ( double t,  float xyz[3]);

void deskTopCurve(float red=1.0, float green=1.0, float blue=1.0, float alpha=1.0);

void pillowBezierCurve(double t, float xyz[3]);

void pillowCurve(float red=1.0, float green=1.0, float blue=1.0, float alpha=1.0);

void bulbCurve(float red=1.0, float green=1.0, float blue=1.0, float alpha=1.0);

void setNormal(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3);

#endif // CURVES_H
