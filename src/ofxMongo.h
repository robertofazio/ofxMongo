/*
// https://mongodb.github.io/mongo-cxx-driver/mongocxx-v3/tutorial/#make-a-connection
*/

#pragma once

#include "ofMain.h"
#include <iostream>
#include <cstdlib>

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/stream/document.hpp>

#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/stdx/make_unique.hpp>
#include <bsoncxx/types.hpp>


#include <mongocxx/exception/exception.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>



using bsoncxx::builder::stream::open_document;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::finalize;

class ofxMongo
{
    
public:
    
    ofxMongo();
    ~ofxMongo();
    
    void init(string host, string port);
    void insert(string dbName, string collectionName, string field, string value);
    void createDocument();
    void deleteDocument(string dbName, string collectionName,string field, string value);
    
    void addToDraft(string _k, int _v); // converted to int64
    void addToDraft(string _k, float _v); // converted to double
    void addToDraft(string _k, double _v);
    void addToDraft(string _k, string _v);
    void addToDraft(string _k, bool _v);
    void clearDraft();
    // insert the draft as a BSON document into collection
    void insertDraft(string dbName, string collectionName);
    
    string getField;
    string getValue;
    
private:
    
    mongocxx::instance instance{}; // This should be done only once.
    string getHostName;
    string getPortName;
    
    // BSON temp document to be added to collection at once
    bsoncxx::builder::basic::document draft{};
};
