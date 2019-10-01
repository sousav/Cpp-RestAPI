//
// Created by Victor Sousa on 01/10/2019.
//

#include "ARouter.h"

namespace API {

    ARouter::ARouter(std::string const &className) : AClass(className), _router(std::regex::ECMAScript) {

    }

    ARouter::~ARouter() {

    }

    server::http::basic_router <server::http::reactor::_default::session_type> &ARouter::get() {
        this->init();
        return this->_router;
    }

}