#pragma once
#include "Platform.h"
class PlatformToss : public Platform {
public:
	void Draw();
	PlatformToss();
	PlatformToss(Coord, GLuint);
	virtual ~PlatformToss();
};

