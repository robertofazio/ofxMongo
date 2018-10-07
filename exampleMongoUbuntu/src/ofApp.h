#pragma once

#include "ofxMongo.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    void keyPressed(int key);

	ofxMongo mongoclient;
    
    string host = "localhost";
    string port = "27017";
    string uri = "mongodb://" + host + ":" + port;
    string db_name = "openFrameworksDB";
    string collection_name = "of_collection";
	
};
