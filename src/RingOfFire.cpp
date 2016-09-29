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

#include "RingOfFire.h"
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

RingOfFire::RingOfFire(void)
	: shape1(nullptr), shape2(nullptr)
{		
}

void RingOfFire::setup()
{
	
	NewtonPhysics* newton1 = new NewtonPhysics(
		Range<float>(1),	//Mass
		Range<int>(50,100),  //Force
		Range<float>(ofDegToRad(-85), ofDegToRad(-95)), //Direction
		Range<float>(0), //Angle
		Range<float>(0)); //Angular Speed

	SimpleColoredBody* body1 = new SimpleColoredBody(
		200, 0, 0, //Color 
		Range<int>(50,0)); //Alpha variation
	
	ParticleRenderer* renderer1 = new OFRenderer("img/smoke.png",2);
    ofVec2f CENTER = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
    
	emitter1 = new Emitter(CENTER, //Center
		1500, //Creations per second
		Range<float>(0.2f, 2.0f), //LifeTime
		new DynamicManager(), newton1, body1, renderer1); //Managers

	shape1 = new RingShape(false, 100, 200, ofDegToRad(-30));
	emitter1->setShape(shape1);	

	NewtonPhysics* newton2 = new NewtonPhysics(
		Range<float>(1), //Mass
		Range<int>(50,100),  //Force
		Range<float>(ofDegToRad(-80), ofDegToRad(-100)), //Direction
		Range<float>(0), //Initial angle
		Range<float>(0, 6)); //Angular speed

	SimpleColoredBody* body2 = new SimpleColoredBody(
		255, 170, 0, //Color 
		Range<int>(50,0)); //Alpha variation

	ParticleRenderer* renderer2 = new OFRenderer("img/ember.png",2);
	emitter2 = new Emitter(CENTER, //Center
		1500, //Creations per second
		Range<float>(0.2f, 0.7f), //LifeTime
		new DynamicManager(), newton2, body2, renderer2); //Managers

	shape2 = new RingShape(false, 100, 200, ofDegToRad(-30));
	emitter2->setShape(shape2);	
}

void RingOfFire::teardown()
{
	delete emitter1;
	delete emitter2;
}

void RingOfFire::update(float time, const MouseInfo& mouse)
{
	if (mouse.leftButton)
	{
		emitter1->setActive(!emitter1->isActive());
		emitter2->setActive(!emitter2->isActive());
	}

	double angle = shape1->getAngle();
	angle += ofDegToRad(-60) * time;
	shape1->setAngle(angle);
	shape2->setAngle(angle);
	emitter1->process(time);
	emitter2->process(time);
}

void RingOfFire::draw() const
{	
	emitter1->draw();
	emitter2->draw();		
}
