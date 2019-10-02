//
// Created by Victor Sousa on 02/10/2019.
//


#include "../Includes/Validator.h"

namespace API::Validation {

    Validator::Validator() {

    }

    Validator::~Validator() {

    }

    Validator &Validator::operator<<(Parameter const &param) {
        this->_params.push_back(param);
        return *this;
    }

    Json::json Validator::validate(std::string const &body) {
        Json::json error{
                {"accepted", false},
                {"errors", Json::json::array()},
        };
        try {
            Json::json::parse(body);
        } catch (std::exception &e) {
            error["errors"] = "request body must be application/json";
            return error;
        }

        Json::json json = Json::json::parse(body);
        for (auto param : this->_params) {
            if (!json.exist(param.getKey())) {
                error.at("errors").push_back(Json::json{
                        {"location", "body"},
                        {"msg", "Missing parameter"},
                        {"param", param.getKey()},
                });
            } else if (!param.validate(json.at(param.getKey()))) {
                error.at("errors").push_back(Json::json{
                        {"location", "body"},
                        {"msg", param.getMessage()},
                        {"param", param.getKey()},
                });
            }
        }

        error["accepted"] = error.at("errors").empty();
        return error;
    }

}