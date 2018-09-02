#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    // Make a connectio to MongoDB with the default URI "mongodb://localhost:27017"
    mongoclient.init(host, port);
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 20, 20);
    ofDrawBitmapStringHighlight("uri : " + uri, 20, 40);
    ofDrawBitmapStringHighlight("host : " + host, 20, 60);
    ofDrawBitmapStringHighlight("port : " + port, 20, 80);
    ofDrawBitmapStringHighlight("db_name : " + db_name, 20, 100);
    ofDrawBitmapStringHighlight("collection_name : " + collection_name, 20, 120);
    
    ofDrawBitmapStringHighlight("Press key '1' in order to add a random record to mongodb collection: ", 20, 160);
    ofDrawBitmapStringHighlight(mongoclient.getField + " : " + mongoclient.getValue, 20, 180, ofColor::red, ofColor::white);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if(key == '1')
    {
        // insert
        int rnd = ofRandom(0.0f, 100000.0f);
        mongoclient.insert(db_name, collection_name, "myRandomField", ofToString(rnd));
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
