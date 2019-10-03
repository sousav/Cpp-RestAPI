//
// Created by Victor Sousa on 29/09/2019.
//

#ifndef CPP_RESTAPI_RESTROUTINGROUTER_H
#define CPP_RESTAPI_RESTROUTINGROUTER_H

#include "ARouter.h"
#include "RestRouting.h"

#include "RestRoutingController.h"

namespace API {

    class RestRoutingRouter : public ARouter {

    public:
        RestRoutingRouter(std::string const &className = "RestRoutingRouter") : ARouter(className) {

        }

        virtual ~RestRoutingRouter() {

        }

    protected:
        virtual void init() {

            this->_router.get("^[/]??$", RestRoutingController::Get());

            this->_router.post("^[/]??$", RestRoutingController::Post());

        }

    };

}

#endif //CPP_RESTAPI_RESTROUTINGROUTER_H
