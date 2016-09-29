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

#include "Fireworks.h"
#include "RingShape.h"
#include "DynamicManager.h"
#include "NewtonPhysics.h"
#include "SimpleColoredBody.h"
#include "OFRenderer.h"

#include <iostream>

using namespace std;
using namespace math;
using namespace particle;
using namespace particle::physics;
using namespace particle::body;
using namespace particle::manager;
using namespace particle::shape;

Fireworks::Fireworks(void) : count(200,2000)
{			
}

void Fireworks::setup()
{	
	NewtonPhysics* newton1 = new NewtonPhysics(
			Range<float>(1),
			Range<int>(300,400),  //Force
			Range<float>(ofDegToRad(-50), ofDegToRad(-130)), //Direction
			Range<float>(ofDegToRad(0), ofDegToRad(180)), //Angle
			Range<float>(ofDegToRad(-720), ofDegToRad(720))); //Angular speed
		newton1->setGravity(ofVec2f(0,100));

		SimpleColoredBody* body1 = new SimpleColoredBody(			
			255, 210, 200, //Color 
			Range<int>(255)); //Alpha variation

		DynamicManager* manager = new DynamicManager();
		manager->addObserver(this);

		ParticleRenderer* renderer1 = new OFRenderer("img/point.png");
		emitter1 = new Emitter(ofVec2f(ofGetWidth() / 2.0f, ofGetHeight() - 100), //Center
			2, //Creations per second
			Range<float>(1.5f, 1.8f), //LifeTime
			manager, newton1, body1, renderer1); //Managers		


		NewtonPhysics* newton2 = new NewtonPhysics(
			Range<float>(1), //Mass
			Range<int>(1,100),  //Force
			Range<float>(ofDegToRad(0), ofDegToRad(360)), //Direction
			Range<float>(ofDegToRad(0), ofDegToRad(180)), //Angle
			Range<float>(ofDegToRad(-60), ofDegToRad(60))); //Angular speed

		explosionBody = new SimpleColoredBody(
			0, 255, 0, //Color 
			Range<int>(255,0)); //Alpha variation

		ParticleRenderer* renderer2 = new OFRenderer("img/sparkle.png", 0.5, true);
		emitter2 = new Emitter(ofVec2f(), //Center
			0, //Creations per second
			Range<float>(0.5f, 2.5f), //LifeTime
			new DynamicManager(), newton2, explosionBody, 
			renderer2); //Managers		
}

void Fireworks::teardown()
{
	delete emitter1;
	delete emitter2;
}

void Fireworks::update(float time, const MouseInfo& mouse)
{
	if (mouse.leftButton)
	{
		emitter2->setParticlesPerCreation(count.random());	
		emitter1->createParticles();
	}

	emitter1->process(time);
	emitter2->process(time);
}

void Fireworks::draw() const
{	
	emitter1->draw();
	emitter2->draw();		
}

void Fireworks::particleCreated(const particle::Particle& particle)
{
}

void Fireworks::particleDestroyed(const particle::Particle& particle)
{
	//Color of the particle
    int channel = Range<int>(0,100).random();
    if (channel < 20)
        explosionBody->setColor(150, 30, 30);
    else if (channel < 40)
        explosionBody->setColor(30, 150, 20);
    else if (channel < 60)
        explosionBody->setColor(30, 30, 150);
    else if (channel < 80)
        explosionBody->setColor(150, 150, 30);
    else if (channel < 90)
        explosionBody->setColor(150, 30, 150);
    else
        explosionBody->setColor(30, 150, 150);

	emitter2->setParticlesPerCreation(Range<int>(800,2000).random());
	emitter2->setPosition(particle.physics.position);
	emitter2->createParticles();

}
