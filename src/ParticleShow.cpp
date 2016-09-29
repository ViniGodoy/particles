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

#include "ParticleShow.h"
#include "Fireworks.h"
#include "RingOfFire.h"
#include "Flame.h"

ParticleShow::ParticleShow() : current(0)
{
	views.push_back(new Flame());
	views.push_back(new RingOfFire());
	views.push_back(new Fireworks());
}

void ParticleShow::setup() 
{
	views[0]->setup();
}

void ParticleShow::update(float time, const MouseInfo& mouse)
{
	if (mouse.rightButton)
	{
		views[current]->teardown();
		current = (current + 1) % views.size();
		views[current]->setup();
	}

	views[current]->update(time, mouse);
}

void ParticleShow::draw() const
{		
	views[current]->draw();
}

void ParticleShow::teardown() 
{
	views[current]->teardown();
}

