#include "stdafx.h"
#include "Header.h"

GameManager *gm;

int _tmain(int argc, _TCHAR* argv[])
{
	
	gm = new GameManager();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("Frogger V1");
	glutDisplayFunc(gm->display);
	glutReshapeFunc(gm->reshape);
	
	glutMainLoop();
	return 0;
}