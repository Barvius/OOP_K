#include "Platform.h"



Platform::Platform()
{
}

Platform::Platform(Coord _Position, GLuint _Texture) {
	Position = _Position;
	Texture = _Texture;
}

Platform::~Platform()
{
}
