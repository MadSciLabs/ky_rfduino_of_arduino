#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"
#include "ofxRFduinoApp.h"
#include "ofxRFduinoDelegate.h"
#include "ofxRFduinoDelegateCpp.h"
#include "RFduinoManager.h"

class ofApp : public ofxiOSApp, public ofxRFduinoApp {
	
    public:

    void setup();
    void update();
    void draw();
    void exit();

    void touchDown(ofTouchEventArgs & touch);
    void touchMoved(ofTouchEventArgs & touch);
    void touchUp(ofTouchEventArgs & touch);
    void touchDoubleTap(ofTouchEventArgs & touch);
    void touchCancelled(ofTouchEventArgs & touch);

    void lostFocus();
    void gotFocus();
    void gotMemoryWarning();
    void deviceOrientationChanged(int newOrientation);
    
    void didDiscoverRFduino(RFduino *rfduino);
    void didUpdateDiscoveredRFduino(RFduino *rfduino);
    void didConnectRFduino(RFduino *rfduino);
    void didLoadServiceRFduino(RFduino *rfduino);
    void didDisconnectRFduino(RFduino *rfduino);
    
    void receivedData( const char *data);
    void receivedDataInt( int _val);
    
    ofxRFduinoDelegate *rfduinoImpl;
    
    int count;
    
    //True Type Font
    ofTrueTypeFont ttf;
    int currVal;
    
    const int rangeSize = 5;
    int rangeVals[5];
    int rangeIndex;

};


