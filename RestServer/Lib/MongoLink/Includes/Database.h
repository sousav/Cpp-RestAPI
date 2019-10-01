//
// Created by Victor Sousa on 30/09/2019.
//

#ifndef CPP_RESTAPI_DATABASE_H
#define CPP_RESTAPI_DATABASE_H

#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/uri.hpp>

#include "AClass.h"

namespace DB {

    class MongoDB : public AClass {

    public:
        MongoDB(std::string const &uri, std::string const &dbName, std::string const &className = "MongoDB");
        static MongoDB &getInstance();
        virtual ~MongoDB();

        mongocxx::database &getDB();

    protected:
        static MongoDB *_instance;

    private:
        mongocxx::instance _mongoInstance;
        mongocxx::client _client;
        mongocxx::database _db;

    private:
        MongoDB(const MongoDB&) = delete;
        MongoDB& operator=(const MongoDB&) = delete;

    };

}

#endif //CPP_RESTAPI_DATABASE_H
