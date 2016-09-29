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

#include "PhysicsCalculator.h"
#include "Range.h"

namespace particle
{
	namespace physics
	{
		class NewtonPhysics : public PhysicsCalculator
		{
			private:
				math::Range<float> mass;

				math::Range<int> force;
				math::Range<float> direction;				

				math::Range<float> angle;
				math::Range<float> angularSpeed;

				ofVec2f forces;
				ofVec2f gravity;

			public:
				NewtonPhysics(
					math::Range<float> _mass, 
					math::Range<int> _force, math::Range<float> _direction,
					math::Range<float> angle, math::Range<float> angularSpeed);

				void setForces(const ofVec2f& _forces);
				const ofVec2f& getForces() const;

				void setGravity(const ofVec2f& _gravity);
				const ofVec2f& getGravity() const;
		
				virtual void init(ParticleDynamics& physics);
				virtual void calculate(float secs, const ParticleLife& life, ParticleDynamics& physics);
				virtual ~NewtonPhysics();
		};
	}
}

