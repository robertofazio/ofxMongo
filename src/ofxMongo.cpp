#include "ofxMongo.h"

ofxMongo::ofxMongo()
{
    
}

ofxMongo::~ofxMongo()
{
    
}

void ofxMongo::init(string host, string port)
{
    try
    {
        mongocxx::uri uri("mongodb://" + host + ":" + port);
        mongocxx::client client(uri);
        cout << "Connected to MongoDB : " << "mongodb://" << host << ":" << port << endl;
        getHostName = host;
        getPortName = port;
    }
    catch (const std::exception& xcp)
    {
        std::cout << "connection failed: " << xcp.what() << std::endl;
    }
    
    
}


void ofxMongo::insert(string dbName, string collectionName,string field, string value)
{
    mongocxx::client conn{mongocxx::uri{"mongodb://" + getHostName + ":" + getPortName}};
    bsoncxx::builder::stream::document document{};
    
    auto collection = conn[dbName][collectionName];
    collection.insert_one(make_document(kvp(field, value)));
    
    cout << "insert to collection record : "  << field << value << endl;
    getField = field;
    getValue = value;
    
//    auto cursor = collection.find({});
//
//    for (auto&& doc : cursor)
//    {
//        std::cout << bsoncxx::to_json(doc) << std::endl;
//    }
    
    
    
}

void ofxMongo::createDocument()
{
    mongocxx::client conn{mongocxx::uri{"mongodb://" + getHostName + ":" + getPortName}};
    bsoncxx::builder::stream::document document{};
    //auto collection = conn[dbName][collectionName];

}

void ofxMongo::addToDraft(string _k, int _v) {
    draft.append(kvp(_k, _v));
    
};
void ofxMongo::addToDraft(string _k, float _v) {
    draft.append(kvp(_k, static_cast<double>(_v)));
};
void ofxMongo::addToDraft(string _k, double _v) {
    draft.append(kvp(_k, _v));
};
void ofxMongo::addToDraft(string _k, string _v) {
    draft.append(kvp(_k, _v));
};
void ofxMongo::addToDraft(string _k, bool _v) {
    draft.append(kvp(_k, _v));
};


void ofxMongo::clearDraft(){
    draft.clear();
};

void ofxMongo::insertDraft(string dbName, string collectionName) {
    mongocxx::client conn{mongocxx::uri{"mongodb://" + getHostName + ":" + getPortName}};
    auto collection = conn[dbName][collectionName];
    collection.insert_one(draft.view());
    
    ofLog(OF_LOG_NOTICE) << "draft added to " << dbName << " collection: " << collectionName;
    
};

void ofxMongo::deleteDocument(string dbName, string collectionName,string field, string value)
{
    mongocxx::client conn{mongocxx::uri{"mongodb://" + getHostName + ":" + getPortName}};
    bsoncxx::builder::stream::document document{};

    auto collection = conn["dbName"]["collectionName"];
    //collection.delete_one(document{} << "name" << "of_collection" << bsoncxx::builder::stream::finalize);

}
