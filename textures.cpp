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

void LoadFiles()
{
    //0
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\tile_color_1.bmp");
    //1
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\tile_color_2.bmp");
    //2
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\brick.bmp");
    //3
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\grass.bmp");
    //4
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\roof.bmp");
    //5
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\wooden_floor.bmp");
    //6
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\wall_1.bmp");
    //7
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\door_3.bmp");
    //8
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\window_panel_1.bmp");
    //9
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\door_panel_1.bmp");
    //10
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\olive_color_1.bmp");
    //11
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\pink_1.bmp");
    //12
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\olive_color_2.bmp");
    //13
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\grass_5.bmp");
    //14
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\footpath_1.bmp");
    //15
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\road_1.bmp");
    //16
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\road_lines_3.bmp");
    //17
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\steel_color_1.bmp");
    //18
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\steel_color_2.bmp");
    //19
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\steel_color_3.bmp");
    //20
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\green_metal_1.bmp");
    //21
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\wood_plank_1.bmp");
    //22
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\door_2.bmp");
    //23
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\door_1.bmp");
    //24
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\wood_1.bmp");
    //25
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\wooden_board_1.bmp");
    //26
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\fabric_color_1.bmp");
    //27
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\cherry_wood_1.bmp");
    //28
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\cherry_wood_2.bmp");
    //29
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\cherry_wood_3.bmp");
    //30
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\cherry_wood_4.bmp");
    //31
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\cherry_wood_5.bmp");
    //32
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\cherry_wood_6.bmp");
    //33
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\cherry_wood_7.bmp");
    //34
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\textile_1.bmp");
    //35
    LoadTexture("E:\\4-2\\CSE 4208 - Graphics Lab\\Project\\1607039\\textures\\textile_2.bmp");
}
