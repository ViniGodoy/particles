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
#include "AbstractParticleManager.h"

#include <vector>

namespace particle
{
	namespace manager
	{
		class DynamicManager : public AbstractParticleManager
		{
			private:
				std::vector<Particle*> live;
				std::vector<Particle*> dead;

			public:
				DynamicManager();
				virtual ~DynamicManager();
		
				virtual int createParticles(int amount, const Emitter& emitter, physics::PhysicsCalculator& physics, body::BodyCalculator& body);
				virtual void processParticles(float secs, physics::PhysicsCalculator& physics, body::BodyCalculator& body);				
				virtual void draw(const ParticleRenderer& renderer) const;
		};
	}
}

