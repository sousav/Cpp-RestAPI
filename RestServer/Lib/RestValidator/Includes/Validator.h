//
// Created by Victor Sousa on 02/10/2019.
//

#ifndef COMMENTSAPI_VALIDATOR_H
#define COMMENTSAPI_VALIDATOR_H

#include <Json.h>
#include "Parameter.h"

namespace API {

    namespace Validation {

        class Validator {

        public:
            Validator();

            ~Validator();

            Validator &operator<<(Parameter const &param);

            Json::json validate(std::string const &body);

        private:
            std::vector<Parameter> _params;

        };

    }

}

#endif //COMMENTSAPI_VALIDATOR_H
