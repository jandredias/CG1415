TO DO!!!!!!!!!!!!!
.change getsize / 2 to gethalfsize

class WHEELS{
		public:
			static void execute(GLdouble x, GLdouble y, GLdouble z, GLdouble radius, GLdouble t){
			glPushMatrix();
			glColor3f(0, 1, 0);
				glTranslatef(x, y, z);
				glScalef(sqrt(3)*radius / 2, t, radius);
				glPushMatrix(); //Poligono da Frente
					glTranslatef(0, -t / 2, 0);
					glBegin(GL_POLYGON);
						glNormal3f(0, -1, 0);
						glVertex3f(0, 0, 1);				//1
						glVertex3f(sqrt(3) / 2, 0, 0.5);	//2
						glVertex3f(sqrt(3) / 2, 0, -0.5);	//3
						glVertex3f(0, 0, -1);				//4
						glVertex3f(-sqrt(3) / 2, 0, -0.5);	//5
						glVertex3f(-sqrt(3) / 2, 0, 0.5);	//6
					glEnd();
				glPopMatrix();
				glPushMatrix(); //Poligono de Tras
					glTranslatef(0, t / 2, 0);
					glBegin(GL_POLYGON);
						glNormal3f(0, 1, 0);
						glVertex3f(0, 0, 1);				//1
						glVertex3f(sqrt(3) / 2, 0, 0.5);	//2
						glVertex3f(sqrt(3) / 2, 0, -0.5);	//3
						glVertex3f(0, 0, -1);				//4
						glVertex3f(-sqrt(3) / 2, 0, -0.5);	//5
						glVertex3f(-sqrt(3) / 2, 0, 0.5);	//6
					glEnd();
				glPopMatrix();

				glColor3f(0, 1, 0);
				glPushMatrix();
					glTranslatef(-sqrt(3)/2, -t / 2, 0);
					glBegin(GL_POLYGON);//POligono da Esquerda
						glNormal3f(-1, 0, 0);
						glVertex3f(0, 0, 0.5);		//1
						glVertex3f(0, t, 0.5);		//2
						glVertex3f(0, t, -0.5);		//3
						glVertex3f(0, 0, -0.51);	//4
					glEnd();
				glPopMatrix();

				glColor3f(1, 0, 1);
				glPushMatrix();
					glTranslatef(sqrt(3)/2, -t / 2, 0);
					glBegin(GL_POLYGON);//POligono da Direita
						glNormal3f(1, 0, 0);
						glVertex3f(0, 0, 0.5);		//1
						glVertex3f(0, t, 0.5);		//2
						glVertex3f(0, t, -0.5);		//3
						glVertex3f(0, 0, -0.51);	//4
					glEnd();
				glPopMatrix();

				glColor3f(1, 1, 1);
				glPushMatrix();
					glTranslatef(-sqrt(3)/2, -t/2, 0.5);
					glBegin(GL_POLYGON);//POligono da Esquerda Cima
						glNormal3f(-0.5, 0, sqrt(3)/2);
						glVertex3f(0, 0, 0);		//1
						glVertex3f(sqrt(3)/2, 0, 0.5);		//2
						glVertex3f(sqrt(3)/2, t, 0.5);		//3
						glVertex3f(0, t, 0);	//4
					glEnd();
				glPopMatrix();


				glColor3f(1, 1, 0);
				glPushMatrix();
					glTranslatef(sqrt(3)/2, -t/2, 0.5);
					glBegin(GL_POLYGON);//POligono da Direita Cima
						glNormal3f(0.5, 0, sqrt(3)/2);
						glVertex3f(0, 0, 0);		//1
						glVertex3f(-sqrt(3)/2, 0, 0.5);		//2
						glVertex3f(-sqrt(3)/2, t, 0.5);		//3
						glVertex3f(0, t, 0);	//4
					glEnd();
				glPopMatrix();


				glColor3f(1, 0, 0);
				glPushMatrix();
					glTranslatef(0, -t/2, -1);
					glBegin(GL_POLYGON);//POligono da Esquerda Baixo
						glNormal3f(-0.5, 0, -sqrt(3)/2);
						glVertex3f(0, 0, 0);		//1
						glVertex3f(-sqrt(3)/2, 0, 0.5);		//2
						glVertex3f(-sqrt(3)/2, t, 0.5);		//3
						glVertex3f(0, t, 0);	//4
					glEnd();
				glPopMatrix();
				
				glColor3f(0, 1, 1);
				glPushMatrix();
					glTranslatef(0, -t/2, -1);
					glBegin(GL_POLYGON);//POligono da Direita Baixo
						glNormal3f(0.5, 0, -sqrt(3)/2);
						glVertex3f(0, 0, 0);		//1
						glVertex3f(sqrt(3)/2, 0, 0.5);		//2
						glVertex3f(sqrt(3)/2, t, 0.5);		//3
						glVertex3f(0, t, 0);	//4
					glEnd();
				glPopMatrix();
			glPopMatrix();
		}
};

// 1 => glNormal3f(0.5,-1/3,sqrt(3)/6);
// 2 => glNormal3f(0.5,-1/3,-sqrt(3)/6);
// 3 => glNormal3f(0,-1/3,-sqrt(3)/3);
// 4 => glNormal3f(-1/3,-1/3,-sqrt(3)/6);
// 5 => glNormal3f(-1/3,-1/3,sqrt(3)/6);
// 6 => glNormal3f(0,-1/3,sqrt(3)/3);
// 7 => glNormal3f(0.5,1/3,sqrt(3)/6);
// 8 => glNormal3f(0.5,1/3,-sqrt(3)/6);
// 9 => glNormal3f(0,1/3,-sqrt(3)/3);
//10 => glNormal3f(-1/3,1/3,-sqrt(3)/6);
//11 => glNormal3f(-1/3,1/3,sqrt(3)/6);
//12 => glNormal3f(0,1/3,sqrt(3)/6);