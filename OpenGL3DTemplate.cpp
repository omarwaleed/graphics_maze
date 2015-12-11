#include "TextureBuilder.h"
#include <glut.h>

double eye_x = 1.0;
double eye_y = 10.0;
double eye_z = 20.0;
double center_x = 0.0;
double center_y = 0.0;
double center_z = 0.0;

int xStart[11];
int zStart[11];
int xEnd[11];
int zEnd[11];
int wallnumber = 0;
GLuint groundID,wallID;

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
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x1,0, z1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x2,0, z1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x2, 0, z2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x1,0, z2);
	glEnd();
	glPopMatrix();
	
}

void drawCuboid(int x1, int x2, int z1, int z2)
{
	glPushMatrix();
		glPushMatrix(); // bottom
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(x1, 0, z1);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(x2, 0, z1);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(x2, 0, z2);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(x1, 0, z2);
		glEnd();
		glPopMatrix();

		glPushMatrix(); // top
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(x1, 1, z1);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(x2, 1, z1);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(x2, 1, z2);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(x1, 1, z2);
		glEnd();
		glPopMatrix();

		glPushMatrix();// left
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(x1, 0, z1);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(x1, 1, z1);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(x1, 1, z2);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(x1, 0, z2);
		glEnd();
		glPopMatrix();

		glPushMatrix();//right
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(x2, 0, z1);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(x2, 1, z1);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(x2, 1, z2);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(x2, 0, z2);
		glEnd();
		glPopMatrix();
	
		glPushMatrix();//front
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(x1, 0, z1);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(x2, 0, z1);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(x2, 1, z1);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(x1, 1, z1);
		glEnd();
		glPopMatrix();
	
		glPushMatrix();//back
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(x1, 0, z2);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(x2, 0, z2);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(x2, 1, z2);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(x1, 1, z2);
		glEnd();
		glPopMatrix();

	glPopMatrix();
	xStart[wallnumber] = x1;
	xEnd[wallnumber] = x2;
	zStart[wallnumber] = z1;
	zEnd[wallnumber] = z2;
	wallnumber++;
}

void drawGround() {
  glBegin(GL_QUADS);

  DrawRect(6,-6,6,-7);

  glEnd();
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

void loadTextures(){
	loadBMP(&groundID, "ground.bmp");
	loadBMP(&wallID, "brick.bmp");

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
	
		glPushMatrix();
		drawCuboid(-2, -1, 5, 2);//wall0	
		glPopMatrix();

		glPushMatrix();
		drawCuboid(-1, 6, 5, 4);//wall1
		glPopMatrix();

		glPushMatrix();
		drawCuboid(6, 5, 4, -1);//wall2
		glPopMatrix();

		glPushMatrix();
		drawCuboid(6, 4, -1, -2);//wall3
		glPopMatrix();

		glPushMatrix();
		drawCuboid(6, 5, -2, -7);//wall4
		glPopMatrix();

		glPushMatrix();
		drawCuboid(1, 3, 2, 1); //wall5
		glPopMatrix();

		glPushMatrix();
		drawCuboid(0, 1, -3, 2);//wall6
		glPopMatrix();

		glPushMatrix();
		drawCuboid(3, 1, -2, -3);//wall7
		glPopMatrix();

		glPushMatrix();
		drawCuboid(6, -3, -7, -6);//wall8
		glPopMatrix();

		glPushMatrix();
		drawCuboid(-3, -4, -7, -4);//wall9
		glPopMatrix();

		glPushMatrix();
		drawCuboid(0, -5, 0, -1);//wall10
		glPopMatrix();

		glPushMatrix();
		drawCuboid(-5, -6, 6, -7);//wall11
		glPopMatrix();
	
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
	//glColor3f(1, 0, 0);
	glBindTexture(GL_TEXTURE_2D, wallID);
	DrawMaze();
	glPopMatrix();
	

	glPushMatrix();
	glTranslated(-4.5, 1, -7);
	glScaled(2, 2, 2);
	DrawLamp();
	glPopMatrix();
	
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, groundID);
	drawGround();
	glPopMatrix();

	loadTextures();

	glFlush();

}

void Anim()
{

}

void Key(unsigned char key, int x, int y)
{
	if (key == 'w')
	{
		eye_y += 0.1;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(600, 600);
	glutInitWindowPosition(150, 50);

	glutCreateWindow("OpenGL - 3D Template");
	glutDisplayFunc(Display);
	glutIdleFunc(Anim);
	glutKeyboardFunc(Key);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 600 / 600, 0.1f, 300.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye_x, eye_y, eye_z, center_x, center_y, center_z, 0.0f, 1.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_CULL_FACE);


	glShadeModel(GL_SMOOTH);



	glutMainLoop();
	return 0;
}


