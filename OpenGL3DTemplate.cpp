#include <glut.h>
int xStart[11];
int zStart[11];
int xEnd[11];
int zEnd[11];
int wallnumber = 0;
void setupLights() {
	GLfloat ambient[] = { 0.7f, 0.7f, 0.7, 1.0f };
	GLfloat diffuse[] = { 0.6f, 0.6f, 0.6, 1.0f };
	GLfloat specular[] = { 1.0f, 1.0f, 1.0, 1.0f };
	GLfloat shininess[] = { 50 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	GLfloat lightIntensity[] = { 0.7f, 0.7f, 1, 1.0f };
	GLfloat lightPosition[] = { -7.0f, 6.0f, 3.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightIntensity);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
	
}


void setupLights2() {
	//GLfloat ambient[] = { 0.7f, 0.7f, 0.7, 1.0f };
	//GLfloat diffuse[] = { 0.6f, 0.6f, 0.6, 1.0f };
	//GLfloat specular[] = { 1.0f, 1.0f, 1.0, 1.0f };
	//GLfloat shininess[] = { 50 };
	GLfloat no_mat[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat mat_ambient_color[] = { 0.8f, 0.8f, 0.2f, 1.0f };
	GLfloat mat_diffuse[] = { 0.1f, 0.5f, 0.8f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat no_shininess = 0.0f;
	GLfloat low_shininess = 5.0f;
	GLfloat high_shininess = 100.0f;
	GLfloat mat_emission[] = { 0.3f, 0.2f, 0.2f, 0.0f };
	GLfloat emissive[] = { 0.0f, 0.0f, 0.0, 1.0f };
	//glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emissive);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, shininess);


	GLfloat lightIntensity[] = { 1.0f, 1.0f, 1, 1.0f };
	glLightfv(GL_LIGHT0, GL_EMISSION, lightIntensity);
	glPushMatrix();
	glRotated(-20, 0, 1, 0);
	glRotated(25, 1, 0, 0);
	GLfloat lightPosition[] = { 0.25f, 0.42f, 0.35f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glPopMatrix();



}

void DrawRect(int x1, int x2, int z1, int z2){
	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex3f(x1,0, z1);
	glVertex3f(x2,0, z1);
	glVertex3f(x2, 0, z2);
	glVertex3f(x1,0, z2);
	glEnd();
	glPopMatrix();
	
}
void Spiral(void){

	glPushMatrix();


	for (int i = 0; i <= 10800; i++){
		glPushMatrix();


		glTranslatef(0, 0, 0);

		glScalef(0.05, 0.01, 0.05);







		glTranslatef(0, 0.001*i, 0);

		glRotatef(i, 0, 1, 0);
		glTranslatef(0, 0, 0.5);
		glColor3f(0.1, 0.1, 0.1);
		glutSolidSphere(0.03, 25, 25);
		glPopMatrix();
	}

	glPopMatrix();


}



void drawRect(int x1, int z1, int x2, int z2) {
	
	glBegin(GL_POLYGON);
	glVertex3f(x1, 0, z1);
	glVertex3f(x2, 0, z1);
	glVertex3f(x2, 0, z2);
	glVertex3f(x1, 0, z2);
	glEnd();
	xStart[wallnumber] = x1;
	xEnd[wallnumber] = x2;
	zStart[wallnumber] = z1;
	zEnd[wallnumber] = z2;
	wallnumber++;
}

void DrawMaze(){
	glPushMatrix();
	DrawRect(2, 1, -5, -2);//wall0
	DrawRect(1, -6, -5, -4);//wall1
	DrawRect(-6, -5, -4, 1);//wall2
	DrawRect(-6, -4, 1, 2);//wall3
	DrawRect(-6, -5, 2, 7);//wall4
	DrawRect(-1, -3, -2, -1); //wall5
	DrawRect(0, -1, 3, -2);//wall6
	DrawRect(-3, -1, 2, 3);//wall7
	DrawRect(-6, 3, 7, 6);//wall8
	DrawRect(3, 4, 7, 4);//wall9
	DrawRect(0, 5, 0, 1);//wall10
	DrawRect(5, 6, -6, 7);//wall11
	glPopMatrix();

}
void DrawLamp(){
	setupLights2();
	glPushMatrix();
	glTranslated(0.0, 0.0, 0.0);
	glColor3f(1, 1, 0.3);
	glutSolidSphere(0.1, 15, 15);
	glPopMatrix();
	glPushMatrix();
	glColor3f(1, 1, 0.6);
	glRotated(90, 1, 0, 0);
	glTranslated(0, 0, 0.05);
	glutSolidCone(0.09, 0.2, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glTranslated(0, -0.17, 0);
	glRotated(-180, 0, 0, 1);
	Spiral();
	glPopMatrix();

}







void Display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	DrawMaze();
	glPopMatrix();

	
	glPushMatrix();
	glTranslated(4.5, 1, 7);
	glScaled(2, 2, 2);
	DrawLamp();
	glPopMatrix();





	glFlush();

}



int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(300, 300);
	glutInitWindowPosition(150, 150);

	glutCreateWindow("OpenGL - 3D Template");
	glutDisplayFunc(Display);
	


	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 300 / 300, 0.1f, 300.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0f, 7.0f, -20.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);



	glutMainLoop();
	return 0;
}


