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

#include "RingShape.h"
#include <stdlib.h>

using namespace particle::shape;

RingShape::RingShape(bool _filled, double majorAxis, double minorAxis, double _angle)
	: filled(_filled), semiMajorAxis(majorAxis/2), semiMinorAxis(minorAxis/2), angle(_angle)
{
}

RingShape::RingShape(bool _filled, double radius)
	: filled(_filled), semiMajorAxis(radius/2), semiMinorAxis(radius/2), angle(0)
{
}


RingShape::~RingShape()
{
}

ofVec2f RingShape::nextPosition(const ofVec2f& center) const
{
	double distFromCenter = filled ? (rand()*1.0 / RAND_MAX) : 1.0;


    double alpha = (rand()*1.0 / RAND_MAX)*2*PI;
    double sinalpha = sin(alpha);
    double cosalpha = cos(alpha);

	double sinbeta = sin(angle);
	double cosbeta = cos(angle);
 
    return ofVec2f(
        static_cast<float>(center.x + (semiMajorAxis * cosalpha * cosbeta - semiMinorAxis * sinalpha * sinbeta) *distFromCenter),
        static_cast<float>(center.y + (semiMajorAxis * cosalpha * sinbeta + semiMinorAxis * sinalpha * cosbeta)*distFromCenter));
}

void RingShape::process(double secs)
{
}

void RingShape::setAngle(double _angle)
{
	angle = _angle;
}

double RingShape::getAngle() const
{
	return angle;
}


