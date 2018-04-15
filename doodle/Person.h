#pragma once
#include <GL/glut.h>
#include "Coord.h"

class Person{
private:
	Coord Position;
	int Size = 30;
	GLuint Texture;

	bool lookLeft = false;
	bool lookRight = true;
	
public:
	void LookLeft() {
		lookLeft = true;
		lookRight = false;
	}
	void LookRight() {
		lookRight = true;
		lookLeft = false;
	}
	void MovePositionX(int tmp) { Position.x += tmp; }
	void SetPositionX(int tmp) { Position.x = tmp; }
	void SetPositionY(int tmp) { Position.y = tmp; }
	Coord GetPosition() { return Position; }
	void Draw();
	Person();
	Person(Coord,GLuint);
	~Person();
};

