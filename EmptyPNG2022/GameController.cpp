#include "GameController.h"
#include "freeglut.h"

GameController* GameController::instance = nullptr;

GameController* GameController::GetInstance()
{
	if (instance == nullptr) {
		instance = new GameController();
	}
	return instance;
}

void GameController::Init()
{
	numOfArm = 4;
	Arms = new vector<RobotArm*>();
	for (int i = 0; i < numOfArm ;i++)
	{
		RobotArm* a = new RobotArm();
		a->ArmIdx = i;
		if (i == 1)
		{
			a->parent = Arms->at(0);
		}
		if (i == 2)
		{
			a->parent = Arms->at(0);
		}
		if (i == 3)
		{
			a->parent = Arms->at(2);
		}
		Arms->push_back(a);
	}


}

void GameController::UI()
{
	glColor3f(1, 0, 0);
	glRasterPos3d(10, 30, 0);
	string s = "curArmIdx = " + to_string(curArmIdx) + "\n (" + 
		to_string(Arms->at(curArmIdx)->rot_x) + "," +
		to_string(Arms->at(curArmIdx)->rot_y) + "," +
		to_string(Arms->at(curArmIdx)->rot_z) + "," +
		to_string(Arms->at(curArmIdx)->length) + ")" 
		;
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)s.c_str());
}

void GameController::Draw()
{
	gluLookAt(
		camX,camY,100, //camare
		0,camY,0,   //obj
		0,1,0);
	
	

	for (int i = 0; i < Arms->size() ;i++)
	{
		glPushMatrix();
		if (i == 0)
		{
			Arms->at(i)->r = 6;
		}
		if (i == 1)
		{
			Arms->at(i)->r = 3;
			
			glRotated(Arms->at(0)->rot_x, 0, 0, 1);
			glRotated(Arms->at(0)->rot_y, 0, 1, 0);
			glRotated(Arms->at(1)->rot_y * 2, 0, 1, 0);
			glRotated(Arms->at(0)->rot_z, 1, 0, 0);
			glTranslated(15, 0, 0);

		}
		if (i == 2)
		{
			Arms->at(i)->r = 3;
			glRotated(Arms->at(0)->rot_x, -1, 0, 0);
			glRotated(Arms->at(0)->rot_y, 0, -1, 0);
			glRotated(Arms->at(0)->rot_z, 0, 0, -1);
			glTranslated(30, 0, 0);

		}
		if (i == 3)
		{
			Arms->at(i)->r = 1;
			
			
		}
		

		Arms->at(i)->Draw();
		
		glPopMatrix();
	}
}

void GameController::update()
{
	for (int i = 0;i < Arms->size() ;i++)
	{
		Arms->at(i)->Update();
	}
}

void GameController::KeyDown(string key)
{
	if (key == "w" || key == "W")
	{
		camY += 2;

	}
	else if (key == "s" || key == "S")
	{
		camY -= 2;

	}
	else if (key == "a" || key == "A")
	{
		camX -= 1;
		

	}
	else if (key == "d" || key == "D")
	{
		camX += 1;

	}
	else if(key == "+")
	{
		
	}
	/*if (key == "UP") {
		if (curArmIdx < Arms->size() - 1) {
			curArmIdx = curArmIdx + 1;
		}
	}
	else if (key == "DOWN") {
		if (curArmIdx > 0) {
			curArmIdx = curArmIdx - 1;
		}
	}*/

}



