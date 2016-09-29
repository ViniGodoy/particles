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

#include "Range.h"
#include "Particle.h"

#include "EmitterShape.h"
#include "ParticleManager.h"

#include "PhysicsCalculator.h"
#include "BodyCalculator.h"

#include <vector>

namespace particle 
{
	class Emitter
	{	
		private:		
			ofVec2f position;
			bool active;

			int particlesPerCreation;
			float creationsPerSec;
			double lastCreation;                

			math::Range<float> lifeTime;

			shape::EmitterShape* shape;
			manager::ParticleManager* manager;
			physics::PhysicsCalculator* physics;
			body::BodyCalculator* body;
			ParticleRenderer* renderer;

			Particle* newParticle();
		public:
			Emitter(const ofVec2f& _position,
				float _particlesPerSec, const math::Range<float>& _lifeTime,
				manager::ParticleManager* _manager, 
				physics::PhysicsCalculator* _physics, 
				body::BodyCalculator* _body,
				ParticleRenderer* _renderer);

			void setParticlesPerCreation(int amount);
			int getParticlesPerCreation() const;
		
			void createParticles();
			void process(float secs);
			void draw() const;	
	
			const ofVec2f& getPosition() const;
			void setPosition(const ofVec2f& newPosition);

			const math::Range<float>& getLifeTime() const;
			void setLifeTime(const math::Range<float> &newLifeTime);

			const ofVec2f& getAcceleration() const;
			void setAcceleration(const ofVec2f& accel);

			void setShape(shape::EmitterShape* shape);
			shape::EmitterShape& getShape() const;

			void setActive(bool _active);
			bool isActive() const;

			~Emitter();
	};
}
