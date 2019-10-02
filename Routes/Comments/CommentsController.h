//
// Created by Victor Sousa on 01/10/2019.
//

#ifndef COMMENTSAPI_COMMENTSCONTROLLER_H
#define COMMENTSAPI_COMMENTSCONTROLLER_H

#include "CommentsRouter.h"
#include "CommentsValidator.h"

namespace API {

    class CommentsController {

    public:

        static auto Get() {
            return [](auto req, auto res) {
                std::vector<DB::Comments> comments = DB::Comments().find<DB::Comments>({});

                res.send(ARouter::send(req, Json::json{
                        {"result", true},
                        {"comments", comments}
                }.dump(), status_code::ok, "application/json"));
            };
        };


        static auto Post() {
            return [](boost::beast::http::request<boost::beast::http::string_body> req, auto res) {
                Json::json validation = CommentsValidator::Post().validate(req.body());
                if (validation.at("accepted") == false) {
                    res.send(ARouter::send(req, validation.dump(), status_code::bad_request, "application/json"));
                    return;
                }

                DB::Comments comment = DB::Comments("test comment");
                comment.save();

                res.send(ARouter::send(req, Json::json{
                        {"result", true},
                        {"method", "Post."}
                }.dump(), status_code::created, "application/json"));
            };
        }

    private:
        CommentsController() = delete;

    };

}

#endif //COMMENTSAPI_COMMENTSCONTROLLER_H
