//
// Created by Victor Sousa on 29/09/2019.
//

#ifndef CPP_RESTAPI_TESTSROUTER_H
#define CPP_RESTAPI_TESTSROUTER_H

#include "ARouter.h"

#include "RestRouting/RestRoutingRouter.h"
#include "Validator/ValidatorRouter.h"

namespace API {

    class TestsRouter : public ARouter {

    public:
        TestsRouter(std::string const &className = "TestsRouter") : ARouter(className) {

        }

        virtual ~TestsRouter() {

        }

    protected:
        virtual void init() {

            RestRoutingRouter restRoutingRouter;
            this->_router.use("^/rest_routing$", restRoutingRouter.get());

            ValidatorRouter validatorRouter;
            this->_router.use("^/validator$", validatorRouter.get());

        }

    };

}

#endif //CPP_RESTAPI_APIROUTER_H
