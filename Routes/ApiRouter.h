//
// Created by Victor Sousa on 29/09/2019.
//

#ifndef CPP_RESTAPI_APIROUTER_H
#define CPP_RESTAPI_APIROUTER_H

#include "ARouter.h"
#include "Tests/TestsRouter.h"

namespace API {

    class ApiRouter : public ARouter {

    public:
        ApiRouter(std::string const &className = "ApiRouter") : ARouter(className) {

        }

        virtual ~ApiRouter() {

        }

    protected:
        virtual void init() {

            TestsRouter testsRouter;
            this->_router.use("^/tests$", testsRouter.get());

        }

    };

}

#endif //CPP_RESTAPI_APIROUTER_H
