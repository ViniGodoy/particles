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

#include "LineShape.h"
#include <stdlib.h>

using namespace particle::shape;

LineShape::LineShape(int _size, float _angle, double _startTime)
	: direction(cos(_angle), sin(_angle)), size(_size), lifeTime(0), startTime(_startTime)
{
}

ofVec2f LineShape::nextPosition(const ofVec2f& center) const
{		
	int maxSize = static_cast<int>(lifeTime >= startTime ? size : (size * lifeTime / startTime));
	int actualSize = (maxSize == 0 ? 0 : (rand() % maxSize)) - size / 2;	
	return direction * static_cast<float>(actualSize) + center;
}

void LineShape::process(double secs)
{
	if (lifeTime >= startTime)
		return;

	lifeTime += secs;	
}
