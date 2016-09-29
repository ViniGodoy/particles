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

#include "Flame.h"
#include "RingShape.h"
#include "DynamicManager.h"
#include "NewtonPhysics.h"
#include "SimpleColoredBody.h"
#include "OFRenderer.h"

using namespace math;
using namespace particle;
using namespace particle::physics;
using namespace particle::body;
using namespace particle::manager;
using namespace particle::shape;

Flame::Flame(void) { }

void Flame::setup()
{
    ofVec2f CENTER = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
    
	newton = new NewtonPhysics(
		Range<float>(1), //Mass
		Range<int>(50,100),  //Force
		Range<float>(ofDegToRad(-85), ofDegToRad(-95)), //Angle
		Range<float>(0),
		Range<float>(0)); 

	SimpleColoredBody* body = new SimpleColoredBody(
		255, 30, 0, //Color
		Range<int>(50,0)); //Alpha variation

	ParticleRenderer* renderer = new OFRenderer("img/smoke.png", 1, true);

	emitter = new Emitter(CENTER, //Center
		500, //Creations per second
		Range<float>(0.2f, 1.0f), //LifeTime
		new DynamicManager(), newton, body, renderer
		); //Managers
	
	emitter->setParticlesPerCreation(1);
}

void Flame::teardown()
{
	delete emitter;
}

void Flame::update(float time, const MouseInfo& mouse)
{
	if (mouse.leftButton)
	{
		float x = mouse.position.x - emitter->getPosition().x;
		x = (x < 0 ? -400 : 400) - x;		
		ofVec2f accel(-x,0);
		newton->setForces(accel);
	}

	emitter->process(time);
}

void Flame::draw() const
{	
	emitter->draw();	
}
