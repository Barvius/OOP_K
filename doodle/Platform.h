#pragma once
#include <GL/glut.h>
#include "Coord.h"

class Platform{
protected:
	Coord Position;
	int SizeX = 34;
	int SizeY = 7;
	GLuint Texture;
public:
	//void MovePositionX(int tmp) { Position.x += tmp; }
	void SetPosition(Coord _Position) { Position = _Position; }
	void SetPositionX(int tmp) { Position.x = tmp; }
	void SetPositionY(int tmp) { Position.y = tmp; }
	void MovePositionY(int tmp) { Position.y += tmp; }
	Coord GetPosition() { return Position; }
	virtual void Draw() = 0;
	Platform();
	Platform(Coord, GLuint);
	virtual ~Platform();
};

