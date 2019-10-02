//
// Created by Victor Sousa on 30/09/2019.
//

#ifndef CPP_RESTAPI_AMODEL_H
#define CPP_RESTAPI_AMODEL_H

#include "AClass.h"
#include "IModel.h"
#include "ACollection.h"

namespace DB {

    class AModel: public AClass, public IModel, public ACollection {

    public:
        AModel(std::string const &id = "undefined", std::string const &className = "AModel");
        virtual ~AModel();

        virtual Json::json toJson() const;
        virtual void fromJson(Json::json const &json);

    protected:
        virtual void fromBSON(bsoncxx::document::view const &view);
        virtual bsoncxx::document::value toBSON() const;

    public:
    public:
        std::string const &getId() const;

    protected:
        std::string _id;

    };

    void to_json(Json::json &j, const AModel &c);
    void from_json(const Json::json& j, AModel &p);

}

#endif //CPP_RESTAPI_AMODEL_H
