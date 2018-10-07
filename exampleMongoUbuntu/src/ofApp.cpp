#include "ofApp.h"



void ofApp::setup()
 {
	// Make a connectio to MongoDB with the default URI "mongodb://localhost:27017"
    mongoclient.init(host, port);

}

void ofApp::update() 
{
	

}

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

void ofApp::keyPressed(int key)
{
	if(key == '1')
    {
        // insert
        int rnd = ofRandom(0.0f, 100000.0f);
        mongoclient.insert(db_name, collection_name, "myRandomField", ofToString(rnd));
    }
    else if(key == '2')
    {
        // create and insert draft
        string key1 = "key1";
        string key2 = "key2";
        string key3 = "key3";
        string key4 = "key4";
        string key5 = "key5";
        double d = static_cast<double>(ofRandom(0.0, 1000.0));
        float f = static_cast<float>(ofRandom(0.0, 1000.0));
        int i = static_cast<int>(ofRandom(0.0, 1000.0));;
        bool b = true;
        string val = "strVal";
        
        mongoclient.addToDraft(key1, i);
        mongoclient.addToDraft(key2, d);
        mongoclient.addToDraft(key3, f);
        mongoclient.addToDraft(key4, val);
        mongoclient.addToDraft(key5, b);
        
        mongoclient.insertDraft(db_name, collection_name);
    }
    
    if(key == '3')
    {
        // clear draft
        mongoclient.clearDraft();
    }
}
