//
// Created by Victor Sousa on 30/09/2019.
//

#include <iostream>
#include "AModel.h"

namespace DB {

    AModel::AModel(std::string const &className) : AClass(className), ACollection(className) {

    }

    AModel::~AModel() {

    }

    Json::json AModel::toJson() const {
        return Json::json();
    }

    void AModel::fromJson(Json::json const &json) {
    }

    void AModel::fromBSON(bsoncxx::document::view const &view) {
        fromJson(Json::json::parse(bsoncxx::to_json(view)));
    };

    bsoncxx::document::value AModel::toBSON() const {
        Json::json j = *this;
        return bsoncxx::from_json(j.dump());
    }

    void to_json(Json::json &j, const AModel &c) {
        j = c.toJson();
    }

    void from_json(const Json::json& j, AModel &p) {
        p.fromJson(j);
    }

}