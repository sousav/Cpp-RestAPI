//
// Created by Victor Sousa on 30/09/2019.
//

#ifndef CPP_RESTAPI_COMMENTS_H
#define CPP_RESTAPI_COMMENTS_H

#include "AModel.h"

namespace DB {

    class Comments: public AModel {

    public:
        Comments(bsoncxx::document::view const &view): AModel("Comments") {
            this->fromBSON(view);
        }

        Comments(std::string const &comment = "", std::string const &id = "undefined"): AModel(id, "Comments") {
            this->_comment = comment;
        }

        virtual ~Comments() {

        }

        virtual Json::json toJson() const {
            Json::json j{
                    {"comment", this->getComment()},
            };
            j.merge_patch(AModel::toJson());
            return j;
        }

        virtual void fromJson(Json::json const &json) {
            AModel::fromJson(json);
            this->_comment = json.at("comment");
        }

    public:
        std::string const &getComment() const {
            return this->_comment;
        }

    private:
        std::string _comment;

    };

}

#endif //CPP_RESTAPI_COMMENTS_H
