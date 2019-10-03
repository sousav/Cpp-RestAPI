//
// Created by Victor Sousa on 30/09/2019.
//

#ifndef CPP_RESTAPI_RESTROUTING_H
#define CPP_RESTAPI_RESTROUTING_H

#include "AModel.h"

namespace DB {

    class RestRouting: public AModel {

    public:
        RestRouting(bsoncxx::document::view const &view): AModel("RestRouting") {
            this->fromBSON(view);
        }

        RestRouting(std::string const &test_string = "", std::string const &id = "undefined"): AModel(id, "RestRouting") {
            this->_test_string = test_string;
        }

        virtual ~RestRouting() {

        }

        virtual Json::json toJson() const {
            Json::json j{
                    {"test_string", this->getTestString()},
            };
            j.merge_patch(AModel::toJson());
            return j;
        }

        virtual void fromJson(Json::json const &json) {
            AModel::fromJson(json);
            this->_test_string = json.at("test_string");
        }

    public:
        std::string const &getTestString() const {
            return this->_test_string;
        }

    private:
        std::string _test_string;

    };

}

#endif //CPP_RESTAPI_RESTROUTING_H
