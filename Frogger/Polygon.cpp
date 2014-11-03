#include "Polygon.h"
#include "GL/glut.h"

Polygon::Polygon(){}
Polygon::~Polygon(){}
void Polygon::execute(GLfloat w, GLfloat h, GLfloat qt){
	int qt_w = qt;
	int qt_h = qt * (h / w);
	int width = w / qt_w;
	int height = h / qt_h;
	glPushMatrix();
	glTranslatef(-w / 2, -h / 2, 0);
	for (int x = 0; x < qt_w; x++){
		for (int y = 0; y < qt_h; y++){
			glPushMatrix();
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
