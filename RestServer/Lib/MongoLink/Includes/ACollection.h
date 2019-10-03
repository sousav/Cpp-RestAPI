//
// Created by Victor Sousa on 30/09/2019.
//

#ifndef CPP_RESTAPI_ACOLLECTION_H
#define CPP_RESTAPI_ACOLLECTION_H

#include "AClass.h"
#include "ICollection.h"

#include <iostream>

namespace DB {

    class ACollection: public ICollection {

    public:
        ACollection(std::string const &collectionName);
        virtual ~ACollection();

        std::string getCollectionName() const;

        bool save();

        template<class T>
        std::vector<T> find(bsoncxx::document::view_or_value filter, const mongocxx::options::find &options = mongocxx::options::find()) {
            std::vector<T> collections;
            mongocxx::cursor cursor = this->_collection.find(filter, options);
            for(auto doc : cursor) {
                collections.push_back(T(doc));
            }
            return collections;
        }

    private:
        virtual bsoncxx::document::value toBSON() const = 0;

    protected:
        std::string _collectionName;
        mongocxx::collection _collection;

    protected:
        virtual void setId(std::string const &id) = 0;

    };

}

#endif //CPP_RESTAPI_ACOLLECTION_H
