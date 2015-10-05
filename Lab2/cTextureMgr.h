/*
=================
cTextureMgr.h
- Header file for class definition - SPECIFICATION
- Header file for the cTexture class
=================
*/
#ifndef _CTEXTUREMGR_H
#define _CTEXTUREMGR_H
#include "GameConstants.h"
#include "cTexture.h"

class cTextureMgr
{
private:
	static cTextureMgr* pInstance;
	map<string, cTexture*> textureList;

public:
	static cTextureMgr* getInstance;
	cTextureMgr();
	cTextureMgr(LPCSTR theFilename);
	~cTextureMgr();
	void addTexture(LPCSTR theFilename);		// add the texture for use.
	GLuint getTexture(string textureName);		// return the texture.
	void deleteTextures();						// Delete all textures;
};
#endif