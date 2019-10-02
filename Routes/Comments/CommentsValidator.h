//
// Created by Victor Sousa on 01/10/2019.
//

#ifndef COMMENTSAPI_COMMENTSVALIDATOR_H
#define COMMENTSAPI_COMMENTSVALIDATOR_H

#include <Json.h>
#include <Validator.h>

namespace API {

    class CommentsValidator {

    public:

        static Validation::Validator Post() {
            return Validation::Validator() << Validation::Parameter("comment").isNot().empty().withMessage("field comment must not be empty");
        }

    private:
        CommentsValidator() = delete;

    };

}

#endif //COMMENTSAPI_COMMENTSVALIDATOR_H
