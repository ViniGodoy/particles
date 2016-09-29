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

#include "NewtonPhysics.h"

using namespace math;
using namespace particle;
using namespace particle::physics;

NewtonPhysics::NewtonPhysics(
					Range<float> _mass, 
					Range<int> _force, Range<float> _direction,
					Range<float> _angle, Range<float> _angularSpeed)
: mass(_mass), 
		force(_force), direction(_direction), 
		angle(_angle), angularSpeed(_angularSpeed)
{
}

void NewtonPhysics::setForces(const ofVec2f& _forces)
{
    forces = _forces;
}

const ofVec2f& NewtonPhysics::getForces() const
{
	return forces;
}

void NewtonPhysics::setGravity(const ofVec2f& _gravity)
{
    gravity = _gravity;
}

const ofVec2f& NewtonPhysics::getGravity() const
{
	return gravity;
}

void NewtonPhysics::init(ParticleDynamics& physics)
{
	physics.mass = mass.random();
    float a = direction.random();
    float f = force.random();
    
    physics.momentum = ofVec2f(cos(a) * f, sin(a) * f);
	physics.angle = angle.random();
	physics.angularSpeed = angularSpeed.random();
}

void NewtonPhysics::calculate(float secs, const ParticleLife& life, ParticleDynamics& physics)
{
	ofVec2f accelSecs = (forces / physics.mass + gravity) * secs;
	physics.position += (physics.momentum + accelSecs / 2.0f) * secs;
	physics.momentum += accelSecs;
	physics.angle += physics.angularSpeed * secs;
}

NewtonPhysics::~NewtonPhysics()
{
}
