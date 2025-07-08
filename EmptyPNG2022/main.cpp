#include <iostream>
#include "GL/freeglut.h"
#include <string>
#include "Sprite.h"
#include "GameController.h"
#include <vector>

using namespace std;

int ballTextID;
int a = 0;

void initRendering() {
	glEnable(GL_DEPTH_TEST);                    // test 3D depth
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void cameraSetup(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);                // select projection matrix
	glLoadIdentity();                           // reset projection matrix
	gluPerspective(45.0, 1, 1.0, 200.0);      // 3D Camera
	//gluOrtho2D(0, w, 0, h);						// 2D Camera
}

void display() {
	glClearColor(0.5, 0.5, 0.5, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear Screen and Depth Buffer


	//UI
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0,800,800,0,0,200);

	glMatrixMode(GL_MODELVIEW);
	GameController::GetInstance()->UI();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	//ui



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glTranslated(0, 0, -20);
	//glRotated(a, 1, 1, 1);

	GameController::GetInstance()->Draw();


	glutSwapBuffers();
}

void Update(int value) {
	a++;
	GameController::GetInstance()->update();
	glutPostRedisplay();
	glutTimerFunc(30, Update, 0);
}

void Keyboard(unsigned char key, int x, int y)
{
	string s = "";
	s += key;
	GameController::GetInstance()->KeyDown(s);
}
void SpKeyboard(int key, int x, int y)
{
	if (key == GLUT_KEY_UP) {
		GameController::GetInstance()->KeyDown("UP");
	}
	else if (key == GLUT_KEY_DOWN) {
		GameController::GetInstance()->KeyDown("DOWN");
	}

}

int main(int argc, char** argv) {
	std::cout << "Programmer: <your name>\n";
	std::cout << "Compiled on " << __DATE__ << ", " << __TIME__ << std::endl << std::endl;

	// init GLUT and create Window
	glutInit(&argc, argv);                      // GLUT initialization
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 800);               // set the window size

	// create the window
	glutCreateWindow("Introduction to OpenGL");
	initRendering();                            // initialize rendering


	Sprite *sunImg = new Sprite("Resources/sun.png");
	GameController::GetInstance()->ballTexID = sunImg->GenTexture();
	delete(sunImg);


	GameController::GetInstance()->Init();

	// register handler functions
	glutReshapeFunc(cameraSetup);               // resiz window and camera setup
	glutDisplayFunc(display);                   // Display function
	glutKeyboardFunc(Keyboard);					// Keyboard handler
	glutSpecialFunc(SpKeyboard);
	//glutMouseFunc(mouseClick);				// Mouse Click handler
	//glutPassiveMotionFunc(mouseMove);			// Mouse move without mourse button pressed
	//glutMotionFunc(mouseOnClickMove);			// Mouse move with mourse button pressed
	//glutIdleFunc(idleUpdate);
	glutTimerFunc(30, Update, 0);				// Timer function

	glutMainLoop();                             // run GLUT mainloop
	return(0);                                  // this line is never reached
}