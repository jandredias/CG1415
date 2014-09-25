#include "stdafx.h"
#include "Header.h"

GameManager *gamemanager = new GameManager();

int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("Frogger V1");
	glutDisplayFunc(gamemanager->display);
	glutReshapeFunc(gamemanager->reshape);
	glutMainLoop();
	return 0;
}