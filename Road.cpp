#include "Road.h"
#include <iostream>
#include "GL/glut.h"
#include "Polygon.h"

#include "GameManager.h"
#include "Texture.h"
extern GameManager  *gm;
Road::Road(){
	setSize(300, 30, 10);
	if(gm->getDebug()) std::cout << "TEXT ROAD" << std::endl;
	setTexture(Texture::loadBMP_custom("Asphalt.bmp"), 512); }
Road::~Road(){}
Road::Road(double x, double y, double z): Road() {setPosition(x, y, z);}
void Road::draw(){
	glPushMatrix();
		glTranslated(	getPosition().getX(),
						getPosition().getY(),
						0);
		defineMaterial(	0.00, 0.00, 0.00, 1.00,	//Ambient
						0.20, 0.20, 0.20, 1.00,	//Diffuse
						0.20, 0.20, 0.20, 1.00,	//Specular
						0.00, 0.00, 0.00, 1.00,	//Emission
						77, getTexture());		//SHININESS
		glColor3f(0.1137, 0.1137, 0.1137);
		Polygon::execute(2 * getSize().getX(), 2 * getSize().getY(), gm->getSettings().getNrPolygons(), gm->getSettings().getNrPolygons());
		for (int i = -3; i < 4; i+= 2)
			for (int j = -5; j < 6; j++){
				glPushMatrix();
					defineMaterial(	0.00, 0.00, 0.00, 1.00,	//Ambient
									1.00, 1.00, 1.00, 1.00,	//Diffuse
									1.00, 1.00, 1.00, 1.00,	//Specular
									0.00, 0.00, 0.00, 1.00,	//Emission
									77);					//SHININESS
					glColor3f(0.5764, 0.5764, 0.5764);
					glTranslated(j * (40), i * 6,0.01);
					Polygon::execute(20, 1, 2, 1);
				glPopMatrix();
			}
	glPopMatrix();
}
