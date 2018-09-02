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
