#pragma once
#include "Platform.h"
class PlatformBasic : public Platform {
public:
	void Draw();
	PlatformBasic();
	PlatformBasic(Coord, GLuint);
	virtual ~PlatformBasic();
};

