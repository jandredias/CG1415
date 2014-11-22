#include "Riverside.h"
#include "GL/glut.h"
#include "Polygon.h"
#include "GameManager.h"
#include "Texture.h"
extern GameManager *gm;
Riverside::Riverside(){
	setSize(500, 10, 10);
	if (gm->getDebug()) std::cout << "TEXT RIVERSIDE" << std::endl;
	setTexture(Texture::loadBMP_custom("Grass.bmp"), 512);
}
Riverside::Riverside(double x, double y, double z):Riverside(){setPosition(x, y, z);}
Riverside::~Riverside(){}
void Riverside::draw(){
	glPushMatrix();
		glTranslated(	getPosition().getX(),
						getPosition().getY(),
						getPosition().getZ());
		
		defineMaterial(	0.00, 0.10, 0.00, 1.00,	//Ambient
						0.00, 1.00, 0.00, 1.00,	//Diffuse
						1.00, 1.00, 1.00, 1.00,	//Specular
						0.00, 0.00, 0.00, 1.00,	//Emission
						77, getTexture());		//SHININESS
		glColor3f(0, 0.6, 0);
		Polygon::execute(2 * getSize().getX(), 2 * getSize().getY(), gm->getSettings().getNrPolygons(), gm->getSettings().getNrPolygons());
	glPopMatrix();
}
