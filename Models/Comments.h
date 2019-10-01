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

        Comments(std::string const &id = "undefined", std::string const &comment = ""): AModel("Comments") {
            this->_id = id;
            this->_comment = comment;
        }

        virtual ~Comments() {

        }

        virtual Json::json toJson() const {
            return Json::json{
                {"comment", this->getComment()},
                {"_id", this->getId()},
            };
        }

        virtual void fromJson(Json::json const &json) {
            this->_id = json["_id"]["$oid"];
            this->_comment = json.at("comment");
        }

    public:
        std::string const &getComment() const {
            return this->_comment;
        }

        std::string const &getId() const {
            return this->_id;
        }

    private:
        std::string _id;
        std::string _comment;

    };

}

#endif //CPP_RESTAPI_COMMENTS_H
