#pragma once
#include "Platform.h"
#include "PlatformBasic.h"
#include "PlatformToss.h"
#include <iostream>
#include <random>
using namespace std;

class PlatformArrangement {
private:
	int N=2;
	float MV[2] = {0.8f,0.2f};
	float ORT[2];
public:
	int Gen();
	PlatformArrangement();
	~PlatformArrangement();
};

