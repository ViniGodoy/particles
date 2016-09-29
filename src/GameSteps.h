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

#include "ofMain.h"

struct MouseInfo {
    bool leftButton = false;
    bool rightButton = false;
    ofVec2f position;
};

class GameSteps
{
    public:
        virtual void setup() = 0;
        
        virtual void update(float time, const MouseInfo& mouse) = 0;
        virtual void draw() const = 0;

        virtual void teardown() = 0;
        virtual ~GameSteps() {};
};
