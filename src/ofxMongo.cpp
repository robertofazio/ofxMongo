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
    
//    bsoncxx::document::value restaurant_doc =
//    document{} << "address" << open_document << "street"
//    << "2 Avenue"
//    << "zipcode"
//    << "10075"
//    << "building"
//    << "1480"
//    << "coord" << open_array << -73.9557413 << 40.7720266 << close_array
//    << close_document << "borough"
//    << "Manhattan"
//    << "cuisine"
//    << "Italian"
//    << "grades" << open_array << open_document << "date"
//    << bsoncxx::types::b_date{12323} << "grade"
//    << "A"
//    << "score" << 11 << close_document << open_document << "date"
//    << bsoncxx::types::b_date{121212} << "grade"
//    << "B"
//    << "score" << 17 << close_document << close_array << "name"
//    << "Vella"
//    << "restaurant_id"
//    << "41704620" << finalize;
//    
//    // We choose to move in our document here, which transfers ownership to insert_one()
//    auto res = db["restaurants"].insert_one(std::move(restaurant_doc));
}

void ofxMongo::deleteDocument(string dbName, string collectionName,string field, string value)
{
    mongocxx::client conn{mongocxx::uri{"mongodb://" + getHostName + ":" + getPortName}};
    bsoncxx::builder::stream::document document{};

    auto collection = conn["dbName"]["collectionName"];
    collection.delete_one(document{} << "name" << "of_collection" << bsoncxx::builder::stream::finalize);

}
