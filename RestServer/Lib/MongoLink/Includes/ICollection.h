//
// Created by Victor Sousa on 30/09/2019.
//

#ifndef CPP_RESTAPI_ICOLLECTION_H
#define CPP_RESTAPI_ICOLLECTION_H

#include <string>

#include <mongocxx/collection.hpp>

namespace DB {

    class ICollection {

    public:
        virtual ~ICollection() {

        }

        virtual std::string getCollectionName() const = 0;

        virtual bool save() = 0;

    private:
        virtual bsoncxx::document::value toBSON() const = 0;

    };

}

#endif //CPP_RESTAPI_ICOLLECTION_H
