#ifndef LAND_H
#define LAND_H

void LamppostX();

void LamppostZ();

void LamppostRowZ(float lengthx, float lengthz);

void LamppostRowX(float lengthx,float lengthz);

void LamppostRowZinverse(float lengthx,float lengthz);

void LamppostRowXinverse(float lengthx,float lengthz);

void DualLamppostRowZ(float lengthx,float lengthz);

void DualLamppostRowX(float lengthx,float lengthz);

void Footpath(float lengthx, float lengthz);

void Path(float lengthx, float lengthz);

void RoadZ(float lengthx, float lengthz, bool infront = true);

void RoadX(float lengthx, float lengthz, bool infront=true);

void JunctionFootpath(float lengthx);

void Junction(float lengthx, float lengthz);

void Field(GLfloat lengthx, GLfloat lengthy, GLfloat lengthz);

void Ground(GLfloat lengthx, GLfloat lengthy, GLfloat lengthz);

#endif // LAND_H
