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
#pragma once

#include "Emitter.h"
#include "ParticleManager.h"
#include <vector>

namespace particle
{
	namespace manager
	{
		class AbstractParticleManager : public ParticleManager
		{
			private:
				std::vector<ParticleObserver*> observers;

			protected:
				virtual int createParticles(int amount, const Emitter& emitter,
					physics::PhysicsCalculator& physics, body::BodyCalculator& body) = 0;

				virtual void processParticles(float secs, physics::PhysicsCalculator& physics, 
					body::BodyCalculator& body) = 0;

				virtual void resetParticle(Particle* particle, const Emitter& emitter, 
					physics::PhysicsCalculator& physics, body::BodyCalculator& body);		

				virtual void processParticle(float time, Particle* particle, 
					physics::PhysicsCalculator& physics, body::BodyCalculator& body);

				void fireParticleCreated(Particle* particle) const;
				void fireParticleDestroyed(Particle* particle) const;

			public:
				AbstractParticleManager();
				virtual void addObserver(ParticleObserver* observer);
				virtual void removeObserver(ParticleObserver* observer);				
				virtual ~AbstractParticleManager();
		};
	}
}
