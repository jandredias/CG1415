#include "Polygon.h"
#include "GL/glut.h"
#include <iostream>
Polygon::Polygon(){}
Polygon::~Polygon(){}
void Polygon::execute(GLfloat w, GLfloat h, GLfloat qt){
	GLfloat w_nr = 0;
	GLfloat h_nr = 0;
	GLfloat nr = 0;
	w_nr = sqrt(qt * w / h );
	h_nr = sqrt(qt * h / w );
	
	GLfloat step_w = w / w_nr;
	GLfloat step_h = h / h_nr;
	
	for(GLfloat x = 0; x <= w; x += step_w){
		for(GLfloat y = 0; y <= h; y += step_h){
			glPushMatrix();
				glColor3f
			
			glPopMatrix();
		}
	}
	GLfloat qt_w = qt;
	GLfloat qt_h = w / qt;
	GLfloat width = w / qt_w;
	GLfloat height = h / qt_h;
	glPushMatrix();
	glTranslatef(-w / 2, -h / 2, 0);
	
	for (GLfloat x = 0; x < qt_w; x++){
		for (GLfloat y = 0; y < qt_h; y++){
			glPushMatrix();
				glColor3f(rand() % 100 * 0.01,rand() % 100 * 0.01,rand() % 100 * 0.01);
				glTranslatef(x * width, y*height, 0);
				glBegin(GL_POLYGON);
					glNormal3f(0, 0, 1);
					glVertex3f(0, 0, 0);
					glVertex3f(width, 0, 0);
					glVertex3f(width, height, 0);
					glVertex3f(0, height, 0);
				glEnd();
			glPopMatrix();
		}
	}
	
	glPopMatrix();
}
