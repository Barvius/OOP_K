#pragma once
#include "Person.h"
#include "Platform.h"
#include "PlatformBasic.h"
#include "PlatformToss.h"

#include "PlatformArrangement.h"

#include <iostream>
#include <random>

using namespace std;

#define N 10

class Game {
private:
	Platform *Platform[N];
	Person _Person;
	PlatformArrangement _PA;
	GLuint _Texture;
	
public:
	void MoveRight();
	void MoveLeft();
	void Render();
	void Calculate();
	void MoveY(int);
	Game(GLuint);
	Game();
	~Game();
};

