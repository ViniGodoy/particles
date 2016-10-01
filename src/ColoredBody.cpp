/******************************************************************************
 *
 * COPYRIGHT Vinicius G. Mendonca ALL RIGHTS RESERVED.
 *
 * This software cannot be copied, stored, distributed without
 * Vinicius G. Mendonca prior authorization.
 *
 * This file was made available on http://github.com/ViniGodoy and it is free
 * to be restributed or used under Creative Commons license 2.5 br:
 * http://creativecommons.org/licenses/by-sa/2.5/br/
 *
 *******************************************************************************
 * Este software nao pode ser copiado, armazenado, distribuido sem autorizacao
 * a priori de Vinicius G. Mendonca
 *
 * Este arquivo foi disponibilizado no site http://github.com/ViniGodoy e esta
 * livre para distribuicao seguindo a licenca Creative Commons 2.5 br:
 * http://creativecommons.org/licenses/by-sa/2.5/br/
 *
 ******************************************************************************/

#include "ColoredBody.h"

using namespace math;
using namespace particle;
using namespace particle::body;

ColoredBody::ColoredBody(int r, int g, int b, Range<int> _a)
	: color(r, g, b), a(_a), transitionTime(0), ellapsedTime(0)
{
}

void ColoredBody::init(ParticleBody& body)
{
	ofVec3f pc = color;
	if (transitionTime > 0) {
		float t = ellapsedTime / transitionTime;
		pc = (1.0f - t) * color + t * newColor;
	}

	body.r = min(max((int) pc.x, 0), 255);
	body.g = min(max((int) pc.y, 0), 255);
	body.b = min(max((int) pc.z, 0), 255);
	body.a = a.getValue(0);
}

void ColoredBody::setAlpha(math::Range<int> _a)
{
	a = _a;
}

void ColoredBody::setColor(int _r, int _g, int _b, float time)
{
	if (time <= 0)
		color.set(_r, _g, _b);
	else {
		if (transitionTime > 0)
			color = newColor;

		newColor.set(_r, _g, _b);
		transitionTime = time;
		ellapsedTime = 0;
	}

}

void ColoredBody::calculate(float time, const ParticleLife& life, ParticleBody& body)
{
	if (transitionTime > 0 && time != lastTime) {
		lastTime = time;
		ellapsedTime += time;		
		if (ellapsedTime >= transitionTime) {
			color = newColor;
			transitionTime = 0;
		}
	}

	body.a = a.getValue(life.age / life.time);
}


ColoredBody::~ColoredBody(void)
{
}
