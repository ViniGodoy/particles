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

#include "ofApp.h"
#include "ParticleShow.h"

ParticleShow particles;
MouseInfo mouse;
bool mouseSet = false;

//--------------------------------------------------------------
void ofApp::setup(){
    particles.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetBackgroundColor(0, 0, 0);
    particles.update(ofGetLastFrameTime(), mouse);
    if (mouseSet) {
        mouse.leftButton = false;
        mouse.rightButton = false;
        mouseSet = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    particles.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mouse.position = ofVec2f(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mouse.leftButton = button == OF_MOUSE_BUTTON_1;
    mouse.rightButton = button == OF_MOUSE_BUTTON_3;
    mouse.position = ofVec2f(x, y);
    mouseSet = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
