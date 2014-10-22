#include "stdafx.h"
#include "Header.h"


GameManager *gm;
int y = 100;
int z = 120;
void display(void){gm->display();}
void reshape(int width, int height){gm->reshape(width, height);}
void update_game(int i){ gm->onTimer(); glutTimerFunc(UPDATE_TIME, update_game, UPDATE_TIME); }
void keyboardfunc_up(unsigned char key, int x, int y){ gm->keyUp(key); }
void keyboardfunc_down(unsigned char key, int x, int y){ gm->keyPressed(key); }
int _tmain(int argc, _TCHAR* argv[])
{
	gm = new GameManager();
	srand(time(0));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);


	glutInitWindowSize(600, 600);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("Frogger V1");

	glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LEQUAL);

	glutTimerFunc(UPDATE_TIME, update_game, UPDATE_TIME);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardUpFunc(keyboardfunc_up);
	glutKeyboardFunc(keyboardfunc_down);
	gm->init();
	glutMainLoop();
	return 0;
}