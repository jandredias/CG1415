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
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("Frogger V1");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	
	glutMainLoop();
	return 0;
}