#include "Person.h"


void Person::Draw() {
	//glColor3f(0.0, 1.0, 1.0);
	
	glBindTexture(GL_TEXTURE_2D, Texture);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	
	if (lookLeft) {
		glTexCoord2d(1.045, 0.54); glVertex2d(Position.x - Size, Position.y - Size);
		glTexCoord2d(1.045, 0.97); glVertex2d(Position.x - Size, Position.y + Size);
		glTexCoord2d(0.6, 0.97); glVertex2d(Position.x + Size, Position.y + Size);
		glTexCoord2d(0.6, 0.54); glVertex2d(Position.x + Size, Position.y - Size);
	}
	if (lookRight) {
		glTexCoord2d(0.6, 0.54); glVertex2d(Position.x - Size, Position.y - Size);
		glTexCoord2d(0.6, 0.97); glVertex2d(Position.x - Size, Position.y + Size);
		glTexCoord2d(1.045, 0.97); glVertex2d(Position.x + Size, Position.y + Size);
		glTexCoord2d(1.045, 0.54); glVertex2d(Position.x + Size, Position.y - Size);
	}
	
	glEnd();
	glDisable(GL_TEXTURE_2D);

}

Person::Person(){
}

Person::Person(Coord _Position, GLuint _Texture){
	Position = _Position;
	Texture = _Texture;
}


Person::~Person()
{
}
