//
// Created by Victor Sousa on 29/09/2019.
//

#ifndef CPP_RESTAPI_COMMENTSROUTER_H
#define CPP_RESTAPI_COMMENTSROUTER_H

#include "Rest/Router.h"

namespace API {

    class CommentsRouter : public Router {

    public:
        CommentsRouter(std::string const &className = "CommentsRouter") : Router(className) {

        }

        virtual ~CommentsRouter() {

        }

    protected:
        virtual void init() {

            this->_router.get("^[/]??$", [](auto beast_http_request, auto context) {
                context.send(make_200<beast::http::string_body>(beast_http_request, Json::json{
                        {"result", true},
                        {"method", "Get."}
                }.dump(), "application/json"));
            });

            this->_router.post("^[/]??$", [](auto beast_http_request, auto context) {
                context.send(make_200<beast::http::string_body>(beast_http_request, Json::json{
                        {"result", true},
                        {"method", "Post."}
                }.dump(), "application/json"));
            });

            this->_router.delete_("^[/]??$", [](auto beast_http_request, auto context) {
                context.send(make_200<beast::http::string_body>(beast_http_request, Json::json{
                        {"result", true},
                        {"method", "Delete."}
                }.dump(), "application/json"));
            });

        }

    };

}

#endif //CPP_RESTAPI_APIROUTER_H
