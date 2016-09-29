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

#include <vector>
#include "Particle.h"

#include "PhysicsCalculator.h"
#include "BodyCalculator.h"
#include "ParticleObserver.h"
#include "ParticleRenderer.h"

namespace particle
{
	class Emitter;

	namespace manager
	{
		class ParticleManager
		{
			public:
				virtual int createParticles(int amount, const Emitter& emitter,
					physics::PhysicsCalculator& physics, body::BodyCalculator& body) = 0;

				virtual void processParticles(float secs, 
					physics::PhysicsCalculator& physics, body::BodyCalculator& body) = 0;

				virtual void draw(const ParticleRenderer& renderer) const = 0;

				virtual void addObserver(ParticleObserver* observer) = 0;
				virtual void removeObserver(ParticleObserver* observer) = 0;

				virtual ~ParticleManager() {}
		};
	}
}
