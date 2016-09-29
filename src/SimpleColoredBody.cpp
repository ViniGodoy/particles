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

#include "SimpleColoredBody.h"

using namespace math;
using namespace particle;
using namespace particle::body;

SimpleColoredBody::SimpleColoredBody(int _r, int _g, int _b, Range<int> _a)
	: r(_r), g(_g), b(_b), a(_a)
{
}

void SimpleColoredBody::init(ParticleBody& body)
{
	body.r = r;
	body.g = g;
	body.b = b;
	body.a = a.getValue(0);
}

void SimpleColoredBody::setColor(int _r, int _g, int _b, Range<int> _a)
{
	setColor(_r, _g, _b);
}

void SimpleColoredBody::setAlpha(math::Range<int> _a)
{
	a = _a;
}

void SimpleColoredBody::setColor(int _r, int _g, int _b)
{
	r = _r;
	g = _g;
	b = _b;
}

void SimpleColoredBody::calculate(float time, const ParticleLife& life, ParticleBody& body)
{
	body.a = a.getValue(life.age / life.time);
}


SimpleColoredBody::~SimpleColoredBody(void)
{
}
