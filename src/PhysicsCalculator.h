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

#include "Particle.h"

namespace particle
{
	namespace physics
	{
		class PhysicsCalculator
		{
			public:
				virtual void init(ParticleDynamics& physics) = 0;
				virtual void calculate(float secs, const ParticleLife& life, ParticleDynamics& physics) = 0;
				virtual ~PhysicsCalculator() {};
		};
	}
}
