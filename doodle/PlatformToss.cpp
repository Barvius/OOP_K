#include "PlatformToss.h"


void PlatformToss::Draw() {
	
	glBindTexture(GL_TEXTURE_2D, Texture);
	glEnable(GL_TEXTURE_2D);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	
	
	glTexCoord2d(0.1, 0.575); glVertex2d(Position.x - SizeX, Position.y - SizeY);
	glTexCoord2d(0.1, 0.73); glVertex2d(Position.x - SizeX, Position.y + SizeY);
	glTexCoord2d(0.51, 0.73); glVertex2d(Position.x + SizeX, Position.y + SizeY);
	glTexCoord2d(0.51, 0.575); glVertex2d(Position.x + SizeX, Position.y - SizeY);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

PlatformToss::PlatformToss() {

}

PlatformToss::PlatformToss(Coord _Position, GLuint _Texture) {
	Position = _Position;
	Texture = _Texture;
	SizeY = 11;
}

PlatformToss::~PlatformToss() {

}
