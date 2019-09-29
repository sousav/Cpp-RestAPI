//
// Created by Victor Sousa on 29/09/2019.
//

#ifndef CPP_RESTAPI_APIROUTER_H
#define CPP_RESTAPI_APIROUTER_H

#include "Rest/Router.h"
#include "Comments/CommentsRouter.h"

namespace API {

    class ApiRouter : public Router {

    public:
        ApiRouter(std::string const &className = "ApiRouter") : Router(className) {

        }

        virtual ~ApiRouter() {

        }

    protected:
        virtual void init() {

            CommentsRouter commentsRouter;
            this->_router.use("^/comments$", commentsRouter.get());

        }

    };

}

#endif //CPP_RESTAPI_APIROUTER_H
