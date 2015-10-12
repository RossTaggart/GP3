/*
==================================================================================
cSphere.cpp
==================================================================================
*/

#include "cSphere.h"


cSphere::cSphere()
{
	setRotAngle(glm::vec3(0.0f,0.0f,0.0f));
}

cSphere::cSphere(GLdouble dRadius, GLint dSlices, GLint dStacks)
{
	setRotAngle(glm::vec3(0.0f,0.0f,0.0f));
	sRadius = dRadius;
	sSlices = dSlices;
	sStacks = dStacks;
}

void cSphere::render(glm::vec3 rotAngle)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);


	glBindTexture(GL_TEXTURE_2D, m_TextureID);

	glTranslatef(m_Position.x, m_Position.y, m_Position.z);
	glRotatef(getRotAngle().x, 1, 0, 0);
	glRotatef(getRotAngle().y, 0, 1, 0);
	glRotatef(getRotAngle().z, 0, 0, 1);

	gluSphere(quad, sRadius, sSlices, sStacks);

	glDisable(GL_NORMALIZE);
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void cSphere::initialise(cTexture theTexture)
{
	quad = gluNewQuadric();

	gluQuadricDrawStyle(quad, GLU_FILL);
	gluQuadricNormals(quad, GLU_SMOOTH);
	gluQuadricTexture(quad, GL_TRUE);

	glBindTexture(GL_TEXTURE_2D, theTexture.getTexture());

	glTranslatef(0.0f, 0.0f, -12.0f);
	glRotatef(270, 1.0f, 0.0f, 0.0f);
}

void cSphere::initialise(GLint theTextureID, glm::vec3 thePosition, glm::vec3 theTranslation)
{
	quad = gluNewQuadric();
	m_TextureID = theTextureID;
	m_Position = thePosition;
	m_Translation = theTranslation;

	gluQuadricDrawStyle(quad, GLU_FILL);
	gluQuadricNormals(quad, GLU_SMOOTH);
	gluQuadricTexture(quad, GL_TRUE);

	glBindTexture(GL_TEXTURE_2D, m_TextureID);

	//glRotatef(90, 1.0f, 0.0f, 0.0f);
	glTranslatef(m_Position.x, m_Position.y, m_Position.z);
}