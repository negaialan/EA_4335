#pragma once
#include "RobotArm.h"
#include <vector>
#include <string>

using namespace std;

class GameController
{
private:
	static GameController* instance;

public:
	static GameController* GetInstance();


public:
	void Init();
	void UI();
	void Draw();
	void update();
	void KeyDown(string key);

public:
	int ballTexID, marsid;
	int numOfArm;
	vector<RobotArm*> *Arms;
	int curArmIdx;
	float camX, camY;
	float rotX;
};

