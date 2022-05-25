#ifndef MOVEMENT_H
#define MOVEMENT_H

float getAng();

float getAngle();

void Angle();

void AngleReverse();

void rotateLookAtPointXZ(bool x, bool y, bool z, float unit=1);

void rotateEyeXZ(bool x, bool y, bool z, float unit=1);

void walkStraightXZ(bool infront = true);

void passiveMouseMovement(int x, int y);

extern float oldEyex;
extern float oldEyey;
extern float oldEyez;

extern float oldLookAtx;
extern float oldLookAty;
extern float oldLookAtz;

void TopView();

void MiddleView();

void OldView();

#endif // MOVEMENT_H
