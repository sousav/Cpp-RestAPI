//
// Created by Victor Sousa on 29/09/2019.
//

#ifndef CPP_RESTAPI_BASEROUTER_H
#define CPP_RESTAPI_BASEROUTER_H

#include "ARouter.h"
#include "ApiRouter.h"
#include "Database.h"

namespace API {

    class BaseRouter: public ARouter {

    public:
        BaseRouter(std::string const &className = "BaseRouter"): ARouter(className), _db("mongodb://localhost:27017", "TestCommentsCpp")  {

        }

        virtual ~BaseRouter() {

        }

    protected:
        void init() {
            ApiRouter apiRouter;
            this->_router.use("^/api$", apiRouter.get());

            this->_router.all(R"(^.*$)", [](auto beast_http_request, auto context) {
                context.send(API::ARouter::send(beast_http_request, Json::json{
                        {"result", false},
                        {"status", "Endpoint not found."}
                }.dump(), status_code::not_found, "application/json"));
            });
        }

    private:
        DB::MongoDB _db;

    };
}

#endif //CPP_RESTAPI_BASEROUTER_H
