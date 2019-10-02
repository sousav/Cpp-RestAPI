//
// Created by Victor Sousa on 29/09/2019.
//

#ifndef CPP_RESTAPI_COMMENTSROUTER_H
#define CPP_RESTAPI_COMMENTSROUTER_H

#include "ARouter.h"
#include "Comments.h"

#include "CommentsController.h"

namespace API {

    class CommentsRouter : public ARouter {

    public:
        CommentsRouter(std::string const &className = "CommentsRouter") : ARouter(className) {

        }

        virtual ~CommentsRouter() {

        }

    protected:
        virtual void init() {

            this->_router.get("^[/]??$", CommentsController::Get());

            this->_router.post("^[/]??$", CommentsController::Post());

        }

    };

}

#endif //CPP_RESTAPI_APIROUTER_H
