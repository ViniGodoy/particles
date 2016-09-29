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

#include "Emitter.h"

#include <algorithm>
#include <iostream>

#include "PointShape.h"
#include "DynamicManager.h"

using namespace std;
using namespace math;

using namespace particle;
using namespace particle::manager;
using namespace particle::body;
using namespace particle::physics;
using namespace particle::shape;

Emitter::Emitter(const ofVec2f& _position, float _particlesPerSec, const Range<float>& _lifeTime,
	ParticleManager* _manager, PhysicsCalculator* _physics, BodyCalculator* _body, ParticleRenderer* _renderer)
	: position(_position), active(true),
	particlesPerCreation(1), creationsPerSec(_particlesPerSec), lastCreation(0), lifeTime(_lifeTime),
	shape(new PointShape()), manager(_manager), physics(_physics), body(_body), renderer(_renderer)
{
}

void Emitter::setParticlesPerCreation(int amount)
{
	particlesPerCreation = amount;
}

int Emitter::getParticlesPerCreation() const
{
	return particlesPerCreation;
}

void Emitter::createParticles()
{	
	manager->createParticles(particlesPerCreation, *this, *physics, *body);	
}

void Emitter::process(float secs)
{
	manager->processParticles(secs, *physics, *body);
	if (!active || (creationsPerSec <= 0 && particlesPerCreation <= 0))
		return;

	//Cria novas partículas, se necessário
	double timeBetweenCreations = 1.0 / creationsPerSec;
	lastCreation += secs;
	while (lastCreation > timeBetweenCreations)
	{
		createParticles();
		lastCreation -= timeBetweenCreations;
	}

	shape->process(secs);	
}

void Emitter::draw() const
{
	manager->draw(*renderer);
}

const ofVec2f& Emitter::getPosition() const
{
	return position;
}

void Emitter::setPosition(const ofVec2f& newPosition)
{
    position = newPosition;
}

const Range<float>& Emitter::getLifeTime() const
{
	return lifeTime;
}

void Emitter::setLifeTime(const Range<float>& newLifeTime)
{
	lifeTime.set(newLifeTime.getFrom(), newLifeTime.getTo());
}

EmitterShape& Emitter::getShape() const
{
	return *shape;
}

void Emitter::setShape(EmitterShape* newShape)
{
	if (newShape == nullptr)
		return;

	delete shape;
	shape = newShape;
}

void Emitter::setActive(bool _active)
{
	active = _active;
}

bool Emitter::isActive() const
{
	return active;
}

Emitter::~Emitter()
{
	delete body;
	delete physics;
	delete shape;
	delete manager;	
	delete renderer;
}
