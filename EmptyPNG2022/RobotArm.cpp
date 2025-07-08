#include "RobotArm.h"
#include "freeglut.h"
#include "GameController.h"
#include "TextureManager.h"

RobotArm::RobotArm()
{
	rot_x = 0;
	rot_y = 0;
	rot_z = 0;
	length = 2;
	ArmIdx = 0;
	r = 0;
	speed = 1;
}

RobotArm::~RobotArm()
{
}

void RobotArm::Draw()
{
	glPushMatrix();

	if (parent != nullptr)
	{
		GetParentTransforms(parent);
	}
	glRotated(rot_x, 1, 0, 0);
	glRotated(rot_y, 0, 1, 0);
	glRotated(rot_z, 0, 0, 1);


	glEnable(GL_TEXTURE_2D);
	GLUquadric* ball = gluNewQuadric();
	gluQuadricTexture(ball,GameController::GetInstance()->ballTexID);
	gluSphere(ball, r, 20, 20);

	glLineWidth(5);
	glBegin(GL_LINES);
	glColor3ub(255, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(10, 0, 0);

	glColor3ub(0, 255, 255);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 10, 0);

	glColor3ub(0, 255, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, 10);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void RobotArm::Update()
{
		rot_y += speed;
}

void RobotArm::GetParentTransforms(RobotArm* p)
{
	if (p->parent != nullptr)
	{
		GetParentTransforms(p->parent);
	}
	
	
		/*glRotated(p->rot_x, 0, 0, 1);
		glRotated(p->rot_y, 0, 1, 0);
		glRotated(p->rot_z, 1, 0, 0);
		glTranslated(10, 0, 0);*/
	

	return;
}
