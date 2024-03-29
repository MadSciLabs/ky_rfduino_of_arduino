#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    //rfduinoManager = RFduinoManager.sharedRFduinoManager;
    
    rfduinoImpl = [[ofxRFduinoDelegate alloc] init];
    [rfduinoImpl setApplication:this];
    
    count = 0;
    currVal = 0;

    ofBackground(0,0,0);
    
    ttf.loadFont("verdana.ttf", 32, true, true, true);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
    for (int i=0; i<5; i++)
    {
        ttf.drawString(ofToString(rangeVals[i]), 20, 50+i*100);
    }

}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){
    unsigned char data[3];
    data[0] = '1';
    data[1] = '2';
    data[2] = '3';
    ofxRFDSendData(rfduinoImpl, &data[0], 3);
}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void ofApp::lostFocus(){

}

//--------------------------------------------------------------
void ofApp::gotFocus(){

}

//--------------------------------------------------------------
void ofApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void ofApp::deviceOrientationChanged(int newOrientation){

}

//--------------------------------------------------------------
void ofApp::didDiscoverRFduino(RFduino *rfduino)
{
    cout << " didDiscoverRFduino " << endl;
    ofxRFDConnectRFduino(rfduino);
}

void ofApp::didUpdateDiscoveredRFduino(RFduino *rfduino)
{
    cout << " didUpdateDiscoveredRFduino " << endl;
}

void ofApp::didConnectRFduino(RFduino *rfduino)
{
    cout << " didConnectRFduino " << endl;
}

void ofApp::didLoadServiceRFduino(RFduino *rfduino)
{
    cout << " didLoadServiceRFduino " << endl;
}

void ofApp::didDisconnectRFduino(RFduino *rfduino)
{
    cout << " didDisconnectRFduino " << endl;
}

void ofApp::receivedData( const char *data)
{
    count++;
    cout << " got some data! " << count << " " << strlen(data) << " " << endl;

    
    int num = ( (const char)data[1] << 8 | (const char)data[0] );
    cout << num << endl;
}

void ofApp::receivedDataInt( int _val)
{
    if (_val == 0) {
        rangeIndex = 0;
    }
    else
    {
        rangeVals[rangeIndex] = _val;

        rangeIndex++;

        if (rangeIndex > rangeSize) {
            rangeIndex = 0;
        }

    }

    //cout << data << endl
    //int num = ( (const char)data[1] << 8 | (const char)data[0] );

}