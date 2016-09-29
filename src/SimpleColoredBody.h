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

#include "BodyCalculator.h"
#include "Range.h"

namespace particle
{
	namespace body 
	{
		class SimpleColoredBody : public BodyCalculator
		{
			private:
				int r;
				int g;
				int b;
				math::Range<int> a;
		

			public:
				SimpleColoredBody(int _r, int _g, int _b, math::Range<int> a);
				virtual void init(particle::ParticleBody& body);
				virtual void calculate(float time, const particle::ParticleLife& life, particle::ParticleBody& body);				
				void setAlpha(math::Range<int> _a);
				void setColor(int _r, int _g, int _b);
				void setColor(int _r, int _g, int _b, math::Range<int> _a);				
				virtual ~SimpleColoredBody();
		};
	}
}
