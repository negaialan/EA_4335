#pragma once
class RobotArm
{
public:
	RobotArm();
	~RobotArm();

public:
	void Draw();
	void Update();
	void GetParentTransforms(RobotArm *p);

public:
	RobotArm* parent;
	float rot_x, rot_y, rot_z;
	float length;
	int ArmIdx;
	int r;
	float speed;
};

