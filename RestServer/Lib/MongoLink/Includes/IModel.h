//
// Created by Victor Sousa on 30/09/2019.
//

#ifndef CPP_RESTAPI_IMODEL_H
#define CPP_RESTAPI_IMODEL_H

#include <Json.h>
#include <bsoncxx/json.hpp>
#include <bsoncxx/array/value.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

namespace DB {

    class IModel {

    public:
        virtual ~IModel() {

        }

        virtual Json::json toJson() const = 0;
        virtual void fromJson(Json::json const &json) = 0;

    protected:
        virtual void fromBSON(bsoncxx::document::view const &view) = 0;
        virtual bsoncxx::document::value toBSON() const = 0;

    };

}

#endif //CPP_RESTAPI_IMODEL_H
