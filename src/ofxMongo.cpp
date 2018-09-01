#include "ofxMongo.h"

void ofxMongo::hello_mongo()
{
    
    mongocxx::instance inst; // This should be done only once.

    try
    {

        mongocxx::client client{mongocxx::uri{}};
        /*
        //const auto uri = mongocxx::uri uri("mongodb://localhost:27017");
        const auto uri = mongocxx::uri::k_default_uri;

        auto client = mongocxx::client(uri);
        */
        auto admin = client["admin"];
        auto result = admin.run_command(make_document(kvp("isMaster", 1)));
        std::cout << bsoncxx::to_json(result) << std::endl;
        

    }
    catch (const std::exception& xcp)
    {
        std::cout << "connection failed: " << xcp.what() << std::endl;
    }
}

void ofxMongo::insert(string name, string field)
{
    
    mongocxx::client conn{mongocxx::uri{}};
    bsoncxx::builder::stream::document document{};
    
    auto collection = conn["api-rest"]["users"];
    
    // document << "hola" << "man";
    //collection.insert_one(document.view());
   
    collection.insert_one(make_document(kvp(name, field)));
    
    auto cursor = collection.find({});
    
    for (auto&& doc : cursor)
    {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }
    
}
