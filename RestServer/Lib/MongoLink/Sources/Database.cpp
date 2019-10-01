//
// Created by Victor Sousa on 30/09/2019.
//

#include <iostream>
#include "../Includes/Database.h"

namespace DB {

    MongoDB *MongoDB::_instance = nullptr;

    MongoDB &MongoDB::getInstance() {
        return *MongoDB::_instance;
    }

    MongoDB::MongoDB(std::string const &uriString, std::string const &dbName, std::string const &className): AClass(className), _client(mongocxx::uri(uriString)) {
        MongoDB::_instance = this;

        this->_db = this->_client[dbName];
    }

    MongoDB::~MongoDB() {

    }

    mongocxx::database &MongoDB::getDB() {
        return this->_db;
    }

}