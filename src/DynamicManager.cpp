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

#include "DynamicManager.h"

using namespace std;
using namespace particle;
using namespace particle::manager;
using namespace particle::body;
using namespace particle::physics;

DynamicManager::DynamicManager()
{
}

DynamicManager::~DynamicManager()
{
	for (unsigned i = 0; i < live.size(); i++)
		delete live[i];
	for (unsigned i = 0; i < dead.size(); i++)
		delete dead[i];
}

int DynamicManager::createParticles(int amount, const Emitter& emitter, PhysicsCalculator& physics, BodyCalculator& body)
{
	for (int i = 0; i < amount; ++i)
	{
		Particle* particle;
		if (dead.size() == 0)
		{
			particle = new Particle();			
		}
		else
		{
			particle = dead[dead.size()-1];
			dead.pop_back();			
		}
		resetParticle(particle, emitter, physics, body);
		live.push_back(particle);		
		fireParticleCreated(particle);
	}
	return amount;
}

void DynamicManager::processParticles(float secs, PhysicsCalculator& physics, BodyCalculator& body)
{
	//Processa as partículas e remove as mortas
	vector<Particle*> newLive;	
	for (unsigned i = 0; i < live.size(); i++) 
	{
		processParticle(secs, live[i], physics, body);
		if (!live[i]->isDead())
			newLive.push_back(live[i]);
		else
		{
			dead.push_back(live[i]);
			fireParticleDestroyed(live[i]);
		}
	}
	swap(live, newLive);
}

void DynamicManager::draw(const ParticleRenderer& renderer) const
{
	for (unsigned i = 0; i < live.size(); i++) 
		renderer.draw(*live[i]);
}
