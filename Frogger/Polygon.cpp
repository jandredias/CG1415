#include "Polygon.h"
#include "GL/glut.h"
#include <iostream>
#include "GameManager.h"
extern GameManager *gm;
Polygon::Polygon(){}
Polygon::~Polygon(){}
void Polygon::execute(GLfloat w, GLfloat h, GLfloat size_w, GLfloat size_h){
	float aux_w = size_w / 50;
	float aux_h = size_h / 50;

	glPushMatrix();
	glTranslatef(-w / 2, -h / 2, 0);
	for (float x = 0; x < w; x += size_w){
		for (float y = 0; y < h; y += size_h){
			glPushMatrix();
			glTranslatef(x, y, 0);
			if (gm->getSettings().getDebug()) glColor3f(rand() % 100 * 0.01, rand() % 100 * 0.01, rand() % 100 * 0.01);
			glBegin(GL_POLYGON);
						glNormal3f(0, 0, 1);

						glTexCoord2f(0.0f, 0.0f);
						glVertex3f(0, 0, 0);

						//glTexCoord2f(aux_w, 0.0f);
						glTexCoord2f((x + size_w > w) ? w - x : size_w, 0.0f);
						glVertex3f((x + size_w > w) ? w - x: size_w, 0, 0);

						//glTexCoord2f(aux_w, aux_h);
						glTexCoord2f((x + size_w > w) ? w - x : size_w, (y + size_h > h) ? h - y : size_h);
						glVertex3f((x + size_w > w) ? w - x : size_w, (y + size_h > h) ? h - y : size_h, 0);

						//glTexCoord2f(0.0f, aux_h);
						glTexCoord2f(0, (y + size_h > h) ? h - y : size_h);
						glVertex3f(0, (y + size_h > h) ? h - y : size_h, 0);
				glEnd();

			glPopMatrix();
		}
	}
	glPopMatrix();
	return; 
}
