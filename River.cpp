
#include "River.h"
#include "GL/glut.h"
#include <iostream>
#include "Polygon.h"
#include "GameManager.h"
#include "Texture.h"
extern GameManager *gm;
River::River(){ setSize(200, 30, 10);
if (gm->getDebug()) std::cout << "TEXT RIVER" << std::endl; 
setTexture(Texture::loadBMP_custom("WaterPlain.bmp"), 512);
}
River::River(double x, double y, double z): River(){setPosition(x, y, z);}
River::~River(){}
void River::draw(){
	glPushMatrix();
		glTranslated(	getPosition().getX(),
						getPosition().getY(),
						0);
			defineMaterial(	0.01, 0.01, 0.05, 1.00,	//Ambient
							0.20, 0.20, 1.00, 1.00,	//Diffuse
							1.00, 1.00, 1.00, 1.00,	//Specular
							0.00, 0.00, 0.00, 1.00,	//Emission
							77, getTexture());					//SHININESS
			glColor3f(0.1176, 0.1176, 0.5961);
			Polygon::execute(2 * getSize().getX(), 2 * getSize().getY(), gm->getSettings().getNrPolygons(), gm->getSettings().getNrPolygons());
	glPopMatrix();
}
