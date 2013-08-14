#pragma once

#include "ofMain.h"
#include "Primitive.h"
#include "ofxGui.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
        void audioIn(float * input, int bufferSize, int nChannels);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void randomiseAll();
        ofSoundStream soundStream;
        vector <float> left;
    
        int 	bufferCounter;
    
        float smoothedVol;
        float scaledVol;
    
        vector<Primitive>prims;
    
        static const int objectNum = 100; //何個描画するか。
    
        bool bang;
        bool bHide;
        ofxPanel panel;
        ofParameter<ofVec3f> pos;
        ofParameter<ofVec3f> size;
        ofParameter<ofVec3f> rotate;
        ofParameter<float> thresh;
        ofParameter<int> repeat;
        ofParameter<ofColor> color;
        ofxToggle bGlobalRotate;
        ofxToggle bFillTog;
        ofxToggle bBackgroundChange;
        slide globalRotate;
    
        ofPoint bFill;
        bool bReverse;
        ofxToggle bReverseTog;
        int rotAxisMode;
};
