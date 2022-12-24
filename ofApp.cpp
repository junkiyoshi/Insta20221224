#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofSetLineWidth(3);
	ofSetCircleResolution(60);
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	
	for (int len = 200; len <= 600; len += 50) {

		int param_start = ofMap(ofNoise(len * 0.005, ofGetFrameNum() * 0.0035), 0, 1, 0, 200);
		for (int param = param_start; param <= param_start + 80; param += 1) {

			if ((param - param_start) % 2 == 1) {

				ofDrawLine(this->make_point(len, param), this->make_point(len, param + 1));
			}
			else {

				ofDrawCircle((this->make_point(len, param) + this->make_point(len, param + 1)) / 2, 3);
			}
		}

		ofDrawCircle(this->make_point(len, param_start + 90), 6);
	}
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, int param) {

	param = param % 100;
	if (param < 25) {

		return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param < 50) {

		return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param < 75) {

		return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
