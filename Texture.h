#pragma once
#include <GL/glut.h>

class Texture{
public:
	Texture();
	~Texture();
	static GLuint loadBMP_custom(const char *imagepath);
};
