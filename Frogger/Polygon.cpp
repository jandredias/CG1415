#include "Polygon.h"
#include "GL/glut.h"
#include <iostream>
#include "GameManager.h"
#define TEXTURE_SIZE	512
extern GameManager *gm;
Polygon::Polygon(){}
Polygon::~Polygon(){}
void Polygon::execute(GLfloat w, GLfloat h, GLfloat size_w, GLfloat size_h){
	glPushMatrix();
	glTranslatef(-w / 2, -h / 2, 0);
	GLfloat x_inc = w / (TEXTURE_SIZE / size_w) / 100;
	GLfloat y_inc = w / (TEXTURE_SIZE / size_h) / 100; //h / (TEXTURE_SIZE * size_h) * (w/h);
	GLfloat x_text;
	GLfloat y_text;
	for (float x = 0, x_text = 0; x < w; x += size_w, x_text += x_inc)
		for (float y = 0, y_text = 0; y < h; y += size_h, y_text += y_inc){
			glPushMatrix();
			glTranslatef(x, y, 0);
			if (gm->getSettings().getDebug()) glColor3f(rand() % 100 * 0.01, rand() % 100 * 0.01, rand() % 100 * 0.01);
			glBegin(GL_POLYGON);
						glNormal3f(0, 0, 1);

						glTexCoord2f(x_text, y_text);
						glVertex3f(0, 0, 0);

						glTexCoord2f(x_text + x_inc, y_text);
						glVertex3f((x + size_w > w) ? w - x: size_w, 0, 0);

						glTexCoord2f(x_text + x_inc, y_text + y_inc);
						glVertex3f((x + size_w > w) ? w - x : size_w, (y + size_h > h) ? h - y : size_h, 0);

						glTexCoord2f(x_text, y_text + y_inc);
						glVertex3f(0, (y + size_h > h) ? h - y : size_h, 0);
				glEnd();

			glPopMatrix();
		}
	glPopMatrix();
	return; 
}
