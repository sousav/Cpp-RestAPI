//
// Created by Victor Sousa on 01/10/2019.
//

#ifndef COMMENTSAPI_RESTROUTINGVALIDATOR_H
#define COMMENTSAPI_RESTROUTINGVALIDATOR_H

#include <Json.h>
#include <Validator.h>

namespace API {

    class RestRoutingValidator {

    public:
        static Validation::Validator Post() {
            return Validation::Validator() << Validation::Parameter("test_string").isNot().empty();
        }

    private:
        RestRoutingValidator() = delete;

    };

}

#endif //COMMENTSAPI_RESTROUTINGVALIDATOR_H
