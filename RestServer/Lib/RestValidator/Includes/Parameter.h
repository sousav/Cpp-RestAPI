//
// Created by Victor Sousa on 02/10/2019.
//

#ifndef COMMENTSAPI_PARAMETER_H
#define COMMENTSAPI_PARAMETER_H

#include <string>
#include <iostream>

namespace API {

    namespace Validation {

        class Parameter {

        public:
            Parameter(std::string const &key) {
                this->_key = key;
                this->_messageSet = false;
                this->_message = "Invalid Parameters";
            }

            ~Parameter() {

            }

            bool validate(Json::json const &value) {
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
                this->_messageSet = true;
                return *this;
            }

            Parameter &isNot() {
                this->_not = true;
                return *this;
            }

            Parameter &is() {
                this->_not = false;
                return *this;
            }

            Parameter const &empty() {
                this->_function = std::bind(&Parameter::_empty, this, std::placeholders::_1);
                this->setMessage("field can not be empty");
                return *this;
            }

            Parameter const &string() {
                this->_function = std::bind(&Parameter::_string, this, std::placeholders::_1);
                this->setMessage("field must be of type string");
                return *this;
            }

            Parameter const &number() {
                this->_function = std::bind(&Parameter::_number, this, std::placeholders::_1);
                this->setMessage("field must be of type number");
                return *this;
            }

            Parameter const &array() {
                this->_function = std::bind(&Parameter::_array, this, std::placeholders::_1);
                this->setMessage("field must be of type array");
                return *this;
            }

            Parameter const &boolean() {
                this->_function = std::bind(&Parameter::_boolean, this, std::placeholders::_1);
                this->setMessage("field must be of type boolean");
                return *this;
            }

        private:
            bool _empty(std::string const &value) {
                return value.empty();
            };

            bool _string(Json::json const &value) {
                return value.is_string();
            };

            bool _number(Json::json const &value) {
                return value.is_number();
            };

            bool _array(Json::json const &value) {
                return value.is_array();
            };

            bool _boolean(Json::json const &value) {
                return value.is_boolean();
            };

            void setMessage(std::string const &messsage) {
                if (!this->_messageSet) {
                    this->_message = messsage;
                }
            }

        private:
            std::string _key;

            bool _messageSet;
            std::string _message;

            bool _not = false;
            std::function<bool(Json::json const &value)> _function;

        };

    }

}
#endif //COMMENTSAPI_PARAMETER_H
