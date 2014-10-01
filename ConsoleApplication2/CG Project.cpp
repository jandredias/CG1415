#include "stdafx.h"
#include "Header.h"

#define UPDATE_TIME 20

GameManager *gm;

void display(void){gm->display();}
void reshape(int width, int height){gm->reshape(width, height);}
void update(int i){gm->update(i);glutPostRedisplay();glutTimerFunc(UPDATE_TIME, update, UPDATE_TIME);}
void keyboardfunc_up(unsigned char key, int x, int y){ /*std::cout << 1;*/ gm->keyPressed(key, 1); }
void keyboardfunc_down(unsigned char key, int x, int y){ /*std::cout << -1;*/ gm->keyPressed(key, -1); }
int _tmain(int argc, _TCHAR* argv[])
{
	gm = new GameManager();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("Frogger V1");
	glutTimerFunc(UPDATE_TIME, update, UPDATE_TIME);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardUpFunc(keyboardfunc_up);
	glutKeyboardFunc(keyboardfunc_down);
	gm->init();
	glutMainLoop();
	return 0;
}

void addTimber(int a){

}