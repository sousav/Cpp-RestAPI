//
// Created by Victor Sousa on 02/10/2019.
//

#ifndef COMMENTSAPI_PARAMETER_H
#define COMMENTSAPI_PARAMETER_H

#include <string>

namespace API {

    namespace Validation {

        class Parameter {

        public:
            Parameter(std::string const &key) {
                this->_key = key;
                this->_message = "Invalid Parameters";
            }

            ~Parameter() {

            }

            bool validate(std::string const &value) {
                if (this->_not) {
                    return !this->_function(value);
                }
                return this->_function(value);
            }

            std::string const &getKey() const {
                return this->_key;
            }

            std::string const &getMessage() const {
                return this->_message;
            }

            Parameter &withMessage(std::string const &message) {
                this->_message = message;
                return *this;
            }

            Parameter &isNot() {
                this->_not = true;
                return *this;
            }

            Parameter &empty() {
                this->_function = std::bind(&Parameter::_empty, *this, std::placeholders::_1);
                return *this;
            }

        private:
            bool _empty(std::string const &value) {
                return value.empty();
            };

        private:
            std::string _key;
            std::string _message;
            bool _not = false;
            std::function<bool(std::string const &value)> _function;

        };

    }

}
#endif //COMMENTSAPI_PARAMETER_H
