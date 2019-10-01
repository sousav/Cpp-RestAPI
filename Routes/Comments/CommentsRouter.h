//
// Created by Victor Sousa on 29/09/2019.
//

#ifndef CPP_RESTAPI_COMMENTSROUTER_H
#define CPP_RESTAPI_COMMENTSROUTER_H

#include "../../BaseRouter.h"
#include "Comments.h"

namespace API {

    class CommentsRouter : public ARouter {

    public:
        CommentsRouter(std::string const &className = "CommentsRouter") : ARouter(className) {

        }

        virtual ~CommentsRouter() {

        }

    protected:
        virtual void init() {

            this->_router.get("^[/]??$", [](auto beast_http_request, auto context) {

                std::vector<DB::Comments> comments = DB::Comments().find<DB::Comments>({});
                context.send(make_200<beast::http::string_body>(beast_http_request, Json::json{
                        {"result", true},
                        {"comments", comments}
                }.dump(), "application/json"));
            });

            this->_router.post("^[/]??$", [](auto beast_http_request, auto context) {
                DB::Comments comment = DB::Comments("test comment");
                comment.save();

                context.send(make_200<beast::http::string_body>(beast_http_request, Json::json{
                        {"result", true},
                        {"method", "Post."}
                }.dump(), "application/json"));
            });

        }

    };

}

#endif //CPP_RESTAPI_APIROUTER_H
