//
// Created by Victor Sousa on 01/10/2019.
//

#ifndef COMMENTSAPI_RESTROUTINGCONTROLLER_H
#define COMMENTSAPI_RESTROUTINGCONTROLLER_H

#include "RestRoutingRouter.h"
#include "RestRoutingValidator.h"

namespace API {

    class RestRoutingController {

    public:

        static auto Get() {
            return [](auto req, auto res) {
                std::vector<DB::RestRouting> comments = DB::RestRouting().find<DB::RestRouting>({});

                res.send(ARouter::send(req, Json::json{
                        {"result", true},
                        {"rest_routing", comments}
                }.dump(), status_code::ok, "application/json"));
            };
        };


        static auto Post() {
            return [](boost::beast::http::request<boost::beast::http::string_body> req, auto res) {
                Json::json validation = RestRoutingValidator::Post().validate(req.body());
                if (validation.at("accepted") == false) {
                    res.send(ARouter::send(req, validation.dump(), status_code::bad_request, "application/json"));
                    return;
                }

                Json::json body = Json::json::parse(req.body());

                DB::RestRouting restRouting = DB::RestRouting(body.at("test_string").get<std::string>());
                if (!restRouting.save()) {
                    res.send(ARouter::send(req, Json::json{
                            {"result", false},
                    }.dump(), status_code::internal_server_error, "application/json"));
                }

                res.send(ARouter::send(req, Json::json{
                        {"result", true},
                        {"restRouting", restRouting}
                }.dump(), status_code::created, "application/json"));
            };
        }

    private:
        RestRoutingController() = delete;

    };

}

#endif //COMMENTSAPI_RESTROUTINGCONTROLLER_H
