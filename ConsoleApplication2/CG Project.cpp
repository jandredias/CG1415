#include "stdafx.h"
#include "Header.h"

GameManager *gm;

void display(void){
	gm->display();
}
void reshape(int width, int height){
	gm->reshape(width, height);
}
int _tmain(int argc, _TCHAR* argv[])
{
	
	gm = new GameManager();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("Frogger V1");
	//glEnable(GL_DEPTH_TEST);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//glEnable(GL_COLOR_MATERIAL);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	gm->init();
	glutMainLoop();
	return 0;
}