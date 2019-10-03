//
// Created by Victor Sousa on 30/09/2019.
//

#include <iostream>
#include "AModel.h"

namespace DB {

    AModel::AModel(std::string const &id, std::string const &className) : AClass(className), ACollection(className) {
        this->_id = id;
    }

    AModel::~AModel() {

    }

    Json::json AModel::toJson() const {
        return this->_id == "undefined" ? R"({
            "_id": null
        })"_json : Json::json{
                {"_id", this->_id},
        };
    }

    void AModel::fromJson(Json::json const &json) {
        this->_id = json["_id"]["$oid"];
    }

    void AModel::fromBSON(bsoncxx::document::view const &view) {
        fromJson(Json::json::parse(bsoncxx::to_json(view)));
    };

    bsoncxx::document::value AModel::toBSON() const {
        Json::json j = *this;
        return bsoncxx::from_json(j.dump());
    }

    std::string const &AModel::getId() const {
        return this->_id;
    }

    void AModel::setId(std::string const &id) {
        this->_id = id;
    }

    void to_json(Json::json &j, const AModel &c) {
        j = c.toJson();
    }

    void from_json(const Json::json& j, AModel &p) {
        p.fromJson(j);
    }

}