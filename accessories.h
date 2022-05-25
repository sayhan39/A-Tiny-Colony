#ifndef ACCESSORIES_H
#define ACCESSORIES_H

extern float windowRotate;

extern float doorRotate;

void WindowPanelXY(float lengthx, float lengthy, bool infront = true);

//float getWindowRotate();

//void setWindowRotate(float a);

void WindowXY(float lengthy, float lengthx,bool infront=true);

void WindowYZ(float lengthx, float lengthy,bool right=true);

void doorXY(float lengthY,float lengthX, bool mirror=false, bool inverse=false);

void doorYZ(float lengthY,float lengthX, bool mirror=false, bool inverse=false);

//void setDoorRotate(float a);

//float getDoorRotate();

void Stair(float width, float height);

void Wall(float lengthx, float lengthy, float lengthz, bool walls,
                 bool *sides,float *window, float *door, float *stair,
                 float alpha=1.0,int railing=-1);

void Room(float lengthx, float lengthy, float lengthz,bool walls,
                 bool top, bool bottom, bool infront, bool behind, bool right, bool left,
                 float *window, float *door, float *stair,
                 int bed=-1, int tablechair=-1,int cabinet=-1,int diningTable=0,int bulb=-1,int fan=-1,int railing=-1);

void OfficeRoom(float lengthx, float lengthy, float lengthz,bool walls,
                 bool top, bool bottom, bool infront, bool behind, bool right, bool left,
                 float *window, float *door, float *stair,
                 int deskchair=-1,int filingcabinet=-1,int employees=-1,int head=-1,int bulb=-1,int bench=-1,int fan=-1,int railing=-1);

void Floor(bool top=true, bool bottom=true, bool walls=true, float stairBottom=0);

void Floor2(bool top=true, bool bottom=true, bool walls=true, float stairBottom=0);

void OfficeFloor(bool top=true, bool bottom=true, bool walls=true, float stairBottom=0);

void OfficeFloor2(bool top=true, bool bottom=true, bool walls=true, float stairBottom=0);

#endif // ACCESSORIES_H
