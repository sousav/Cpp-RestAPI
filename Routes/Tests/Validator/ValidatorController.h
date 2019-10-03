//
// Created by Victor Sousa on 02/10/2019.
//

#ifndef COMMENTSAPI_VALIDATORCONTROLLER_H
#define COMMENTSAPI_VALIDATORCONTROLLER_H

#include "ValidatorValidator.h"

namespace API {

    class ValidatorController {

    public:

        static auto Post() {
            return [](boost::beast::http::request<boost::beast::http::string_body> req, auto res) {
                Json::json validation = ValidatorValidator::Post().validate(req.body());
                res.send(ARouter::send(req, validation.dump(), validation.at("accepted") == false ? status_code::bad_request : status_code::ok, "application/json"));
            };
        }

    private:
        ValidatorController() = delete;

    };

}

#endif //COMMENTSAPI_VALIDATORCONTROLLER_H
