//
// Created by Victor Sousa on 01/10/2019.
//

#ifndef COMMENTSAPI_VALIDATORVALIDATOR_H
#define COMMENTSAPI_VALIDATORVALIDATOR_H

#include <Json.h>
#include <Validator.h>

namespace API {

    class ValidatorValidator {

    public:
        static Validation::Validator Post() {
            return Validation::Validator()
                    << Validation::Parameter("string").is().string()
                    << Validation::Parameter("number").is().number()
                    << Validation::Parameter("array").is().array()
                    << Validation::Parameter("boolean").is().boolean()

                    << Validation::Parameter("string_not_empty").is().string()
                    << Validation::Parameter("string_not_empty").isNot().empty();

        }

    private:
        ValidatorValidator() = delete;

    };

}

#endif //COMMENTSAPI_VALIDATORVALIDATOR_H
