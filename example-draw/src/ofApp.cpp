#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(50, 40, 50);

    gifEncoder.setup(gifW, gifH, 0.25f, 8); // colors = 8
    ofAddListener(ofxGifEncoder::OFX_GIF_SAVE_FINISHED, this, &ofApp::onGifSaved);
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
    // 1. Draw anything

    // Technique to make a perfect loop: normalize the time, then use sin()

    // normalized time (between 0.0 and 1.0)
    float t = (framesCurr % framesTotal) / static_cast<float>(framesTotal);
    // an oscillating size
    float sz = 60 + 50 * sinf(t * TWO_PI);
    // draw a circle
    ofDrawCircle(gifW/2, gifH/2, sz);

    // 2. Save frame if we're not done yet
    if(framesCurr < framesTotal) {
        img.grabScreen(0, 0, gifW, gifH);
        gifEncoder.addFrame(img, 0.033f);
    }

    // 3. If we're done, save the gif to disk
    if(framesCurr == framesTotal) {
        gifEncoder.save("test.gif");
    }
    framesCurr++;
}

void ofApp::onGifSaved(string &fileName) {
    cout << "gif saved as " << fileName << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}

//--------------------------------------------------------------
void ofApp::exit() {
    gifEncoder.exit();
}
