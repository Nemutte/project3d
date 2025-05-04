#pragma once
#include "v3.h"

class Camera
{
public:
	int width = 1200;
	int height = 900;
	V3d position;
	V3d baseDireection;
	V3d currentDireection;
	float ccy = 0.f;
	float csy = 0.f;
	float ccp = 0.f;
	float csp = 0.f;
	float cy = 0.f;
	float sy = 0.f;
	float cp = 0.f;
	float sp = 0.f;
	float viewerDistance = 500.f;
	Camera();
	V3d Projectle(V3d point);
	void SetAngles(float alfa, float beta);

};