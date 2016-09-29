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

#include "OFRenderer.h"

#include "ofMain.h"

OFRenderer::OFRenderer(const char* name, float _scale, bool _aditive)
	: scale(_scale), aditive(_aditive)
{
    sprite.load(name);
    sprite.setAnchorPercent(0.5, 0.5);
}

void OFRenderer::draw(const particle::Particle& particle) const
{
    
    ofEnableBlendMode(aditive ? OF_BLENDMODE_ADD : OF_BLENDMODE_ALPHA);    
    
    ofPushMatrix();
        ofTranslate(particle.physics.position);
        ofScale(scale, scale);
        ofRotateZ(particle.physics.angle);
        ofSetColor(particle.body.r, particle.body.g, particle.body.b, particle.body.a);
        sprite.draw(0, 0);
    ofPopMatrix();
    
    ofDisableAlphaBlending();
}

OFRenderer::~OFRenderer()
{
}
