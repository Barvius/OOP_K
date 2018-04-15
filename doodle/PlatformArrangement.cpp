#include "PlatformArrangement.h"


int PlatformArrangement::Gen() {
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0, 1);
	float val = dis(gen);
	int ReturnValue = 1;
	//cout << val << endl;
	for (int i = 0; i < N; i++) {
		if (ORT[i] >= val) {
			return i + 1;
		}
	}
	//cout << ReturnValue << endl;
	return 1;
}

PlatformArrangement::PlatformArrangement(){
	float val = 0;
	for (int i = 0; i < N; i++) {
		val += MV[i];
		ORT[i] = val;
	}
}

PlatformArrangement::~PlatformArrangement()
{
}
