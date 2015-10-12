/*
==========================================================================
cShapes.h
==========================================================================
*/

#ifndef _SHAPES_H
#define _SHAPES_H

#include "windowOGL.h"
#include "glm\glm.hpp"
#include "glx\glext.h"
#include "wglext.h"
#include <vector>
#include "cColours.h"
#include "cTexture.h"

class cShapes : public windowOGL
{
public:
	cShapes();
	virtual void render(glm::vec3 rotAngle);
	glm::vec3 getRotAngle();
	void setRotAngle(glm::vec3 rotAngle);
	void prepare(glm::vec3 rAngle);
	virtual void initialise(cTexture theTexture) = 0;

	PFNGLGENBUFFERSARBPROC glGenBuffers = NULL;
	PFNGLBINDBUFFERPROC glBindBuffer = NULL;
	PFNGLBUFFERDATAPROC glBufferData = NULL;

private:
	glm::vec3 m_rotAngle;
};

#endif