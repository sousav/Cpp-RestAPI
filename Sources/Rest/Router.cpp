//
// Created by Victor Sousa on 29/09/2019.
//

#include "Rest/Router.h"

#include "ApiRouter.h"

namespace API {

    Router::Router(std::string const &className) : AClass(className), _router(std::regex::ECMAScript) {
    }

    Router::~Router() {

    }

    server::http::basic_router <server::http::reactor::_default::session_type> &Router::get() {
        this->init();
        return this->_router;
    }

    void Router::init() {

        ApiRouter apiRouter;
        this->_router.use("^/api$", apiRouter.get());

        this->_router.all(R"(^.*$)", [](auto beast_http_request, auto context) {
            context.send(API::Router::make_404<beast::http::string_body>(beast_http_request, Json::json{
                    {"result", false},
                    {"status", "Endpoint not found."}
            }.dump(), "application/json"));
        });
    }

}