#ifndef UTILITY_H
#define UTILITY_H

using namespace std;

extern unsigned int ID;
extern vector <unsigned int> tex;
extern bool mouseMovement;

extern float fanRotation;
extern float fanRotationValue;

extern bool roomLightSwitch;
extern bool officeLightSwitch;

extern bool ambientLightSwitch;
extern bool diffuseLightSwitch;
extern bool specularLightSwitch;
extern bool spotLightSwitch;

void Scene();

void display(void);

void screenSize(int width, int height);

void key(unsigned char key, int x, int y);

void key(unsigned char key, int x, int y);

void keyUp(unsigned char key, int x, int y);

void idle(void);

void LoadTexture(const char*filename);

#endif // UTILITY_H
