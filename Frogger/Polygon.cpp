#include "Polygon.h"
#include "GL/glut.h"
#include <iostream>
#include "GameManager.h"
extern GameManager *gm;
Polygon::Polygon(){}
Polygon::~Polygon(){}
void Polygon::execute(GLfloat w, GLfloat h, GLfloat qt_w, GLfloat qt_h){
	float width;
	float height;
	float step_w = w / qt_w;
	float step_h = h / qt_h;
	glPushMatrix();
	glTranslatef(-w / 2, -h / 2, 0);
	for (float x = 0; x < qt_w; x++){
		for (float y = 0; y < qt_h; y++){
			glPushMatrix();
			glTranslatef(step_w *x, step_h*y, 0);
			if (gm->getDebug()) glColor3f(rand() % 100 * 0.01, rand() % 100 * 0.01, rand() % 100 * 0.01);
				glBegin(GL_POLYGON);
						glNormal3f(0, 0, 1);
						glVertex3f(0, 0, 0);
						glVertex3f(step_w, 0, 0);
						glVertex3f(step_w, step_h, 0);
						glVertex3f(0, step_h, 0);
				glEnd();
		glPopMatrix();
		}
	}
	glPopMatrix();
}
