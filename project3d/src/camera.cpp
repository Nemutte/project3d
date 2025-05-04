#include "camera.h"
#include "math.h"
#include "SFML/Graphics.hpp"

Camera::Camera() : position{V3d(0.f, 0.f, -500.f)}, baseDireection{ V3d(0.f, 0.f, 1.f) }
{
	currentDireection = baseDireection;
}

V3d Camera::Projectle(V3d point)
{
	// Obrót wokó³ osi Y
	float x1 = baseDireection.x * ccy + baseDireection.z * csy;
	float z1 = -baseDireection.x * csy + baseDireection.z * ccy;

	// Obrót wokó³ osi X
	float y1 = baseDireection.y * ccp - z1 * csp;
	float z2 = baseDireection.y * csp + z1 * ccp;

	currentDireection.x = x1;
	currentDireection.y = y1;
	currentDireection.z = z2;
	V3d perspectivPosition = point - position;
	// Obrót wokó³ osi Y
	x1 = perspectivPosition.x * cy + perspectivPosition.z * sy;
	z1 = -perspectivPosition.x * sy + perspectivPosition.z * cy;

	// Obrót wokó³ osi X
	y1 = perspectivPosition.y * cp - z1 * sp;
	z2 = perspectivPosition.y * sp + z1 * cp;

	z2 -= viewerDistance;
	float x = (x1 * viewerDistance) / (z2 + viewerDistance);
	float y = (y1 * viewerDistance) / (z2 + viewerDistance);
	y *= -1;
	V3d projectle = { x + width / 2.f, y + height / 2.f, 0.f};

	return projectle;
}

void Camera::SetAngles(float alfa, float beta)
{
	ccy = cos(alfa);
	csy = sin(alfa);
	ccp = cos(beta);
	csp = sin(beta);
	cy = cos(-alfa);
	sy = sin(-alfa);
	cp = cos(-beta);
	sp = sin(-beta);
}


