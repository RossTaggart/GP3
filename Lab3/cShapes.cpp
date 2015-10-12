/*
==================================================================================
cShapes.cpp
==================================================================================
*/

#include "cShapes.h"


cShapes::cShapes()
{
	m_rotAngle.x = 0.0f;
	m_rotAngle.y = 0.0f;
	m_rotAngle.z = 0.0f;
}

void cShapes::render(glm::vec3 rotAngle)
{
	//glRotatef(rotAngle, 0.0f, 1.0f, 0.0f); 
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

glm::vec3 cShapes::getRotAngle()
{
	return m_rotAngle;
}

void cShapes::setRotAngle(glm::vec3 rotAngle)
{
	m_rotAngle.x = rotAngle.x;
	m_rotAngle.y = rotAngle.y;
	m_rotAngle.z = rotAngle.z;
}

void cShapes::prepare(glm::vec3 rAngle)
{
	m_rotAngle.x = rAngle.x;
	m_rotAngle.y = rAngle.y;
	m_rotAngle.z = rAngle.z;
	if (m_rotAngle.x > 360.0f)
	{
		m_rotAngle.x -= 360.0f;
	}
	if (m_rotAngle.y > 360.0f)
	{
		m_rotAngle.y -= 360.0f;
	}
	if (m_rotAngle.z > 360.0f)
	{
		m_rotAngle.z -= 360.0f;
	}
}
