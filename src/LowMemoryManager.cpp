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

#include "LowMemoryManager.h"
#include <algorithm>

using namespace std;
using namespace particle;
using namespace particle::manager;
using namespace particle::physics;
using namespace particle::body;

LowMemoryManager::LowMemoryManager(unsigned _limit) : limit(_limit)
{
}

int LowMemoryManager::createParticles(int amount, const Emitter& emitter, PhysicsCalculator& physics, BodyCalculator& body)
{
	int count = 0;
	for (int i = 0; i < amount; i++) {
		if (limit != 0 && particles.size() == limit)
			break;
		Particle* particle = new Particle();
		resetParticle(particle, emitter, physics, body);
		particles.push_back(particle);
		fireParticleCreated(particle);
		count++;
	}
	return count;
}

void LowMemoryManager::processParticles(float secs, PhysicsCalculator& physics, BodyCalculator& body)
{	
	for (unsigned i = 0; i < particles.size(); i++)
	{
		processParticle(secs, particles[i], physics, body);
		if (particles[i]->isDead())
		{
			fireParticleDestroyed(particles[i]);
			delete particles[i];
			swap(particles[i], particles[particles.size()-1]);
			particles.pop_back();
		}
	}
}

void LowMemoryManager::draw(const ParticleRenderer& renderer) const
{
	for (unsigned i = 0; i < particles.size(); i++)
		renderer.draw(*particles[i]);		
}

LowMemoryManager::~LowMemoryManager()
{
	for (unsigned i = 0; i < particles.size(); i++)
		delete particles[i];
}
