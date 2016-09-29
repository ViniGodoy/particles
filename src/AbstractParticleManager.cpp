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

#include "AbstractParticleManager.h"
#include <algorithm>

using namespace std;

using namespace particle;
using namespace particle::manager;
using namespace particle::body;
using namespace particle::physics;

AbstractParticleManager::AbstractParticleManager(void)
{
}

void AbstractParticleManager::resetParticle(Particle* particle, const Emitter& emitter, PhysicsCalculator& physics, BodyCalculator& body)
{		
	particle->life.time = emitter.getLifeTime().random();
	particle->life.age = 0;
	particle->physics.position = emitter.getShape().nextPosition(emitter.getPosition());
	physics.init(particle->physics);
	body.init(particle->body);
}

void AbstractParticleManager::processParticle(float time, Particle* particle, PhysicsCalculator& physics, BodyCalculator& body)
{
	physics.calculate(time, particle->life, particle->physics);
	body.calculate(time, particle->life, particle->body);
	particle->life.age += time;
}

void AbstractParticleManager::fireParticleCreated(Particle* particle) const
{
	for (unsigned i = 0; i < observers.size(); ++i)
		observers[i]->particleCreated(*particle);
}

void AbstractParticleManager::fireParticleDestroyed(Particle* particle) const
{
	for (unsigned i = 0; i < observers.size(); ++i)
		observers[i]->particleDestroyed(*particle);
}

void AbstractParticleManager::addObserver(ParticleObserver* observer)
{
		observers.push_back(observer);
}

void AbstractParticleManager::removeObserver(ParticleObserver* observer)
{	
	vector<ParticleObserver*> live;

	for (unsigned i = 0; i < observers.size(); ++i)
		if (observers[i] == observer)
			live.push_back(observer);
	swap(live, observers);
}



AbstractParticleManager::~AbstractParticleManager()
{
}
