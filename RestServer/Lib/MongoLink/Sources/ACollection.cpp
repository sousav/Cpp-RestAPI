//
// Created by Victor Sousa on 30/09/2019.
//

#include <bsoncxx/json.hpp>

#include "Database.h"
#include "ACollection.h"

namespace DB {

    ACollection::ACollection(std::string const &collectionName) {
        this->_collectionName = collectionName;
        this->_collection = MongoDB::getInstance().getDB()[this->_collectionName];
    }

    ACollection::~ACollection() {

    }

    std::string ACollection::getCollectionName() const {
        return this->_collectionName;
    }

    bool ACollection::save() {
        bsoncxx::stdx::optional<mongocxx::result::insert_one> result = this->_collection.insert_one(this->toBSON());
        return result.value().result().inserted_count() > 0;
    }

}