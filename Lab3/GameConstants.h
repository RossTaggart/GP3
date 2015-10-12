#ifndef _GAMECONSTANTS_H
#define _GAMECONSTANTS_H

#define GLM_FORCE_RADIANS
//Define the string to appear in the top left corner of the window
#define WINDOW_TITLE "OpenGl Earth & Moon"

// Windows & OpenGL 
#include <stdlib.h>
#include <Windows.h>
#include "GL\glut.h"
#include <iostream>
#include <string>
#include <ctime>

// Image Texture loading library
#include "IL\il.h"
#include "IL\ilu.h"
#include "IL\ilut.h"

// Maths functions
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\geometric.hpp"
#include "glm\gtc\quaternion.hpp"
#include "glm\gtc\type_ptr.hpp"
#include "glm\gtx\quaternion.hpp"

// STL Container & Algorithms
#include <vector>
#include <map>
#include <algorithm>

// Textures
#include "cTexture.h"

extern int drawMode;
extern float rotationAngle;


#endif