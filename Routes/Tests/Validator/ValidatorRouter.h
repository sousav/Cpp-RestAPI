//
// Created by Victor Sousa on 29/09/2019.
//

#ifndef CPP_RESTAPI_VALIDATORROUTER_H
#define CPP_RESTAPI_VALIDATORROUTER_H

#include "ARouter.h"

#include "ValidatorController.h"

namespace API {

    class ValidatorRouter : public ARouter {

    public:
        ValidatorRouter(std::string const &className = "ValidatorRouter") : ARouter(className) {

        }

        virtual ~ValidatorRouter() {

        }

    protected:
        virtual void init() {

            this->_router.post("^[/]??$", ValidatorController::Post());

        }

    };

}

#endif //CPP_RESTAPI_APIROUTER_H
