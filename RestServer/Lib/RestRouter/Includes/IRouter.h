//
// Created by Victor Sousa on 01/10/2019.
//

#ifndef CPP_RESTAPI_IROUTER_H
#define CPP_RESTAPI_IROUTER_H

#include <boost/asio/posix/stream_descriptor.hpp>
#include <boost/asio/signal_set.hpp>

#include <http/reactor/session.hxx>
#include <http/reactor/listener.hxx>
#include <http/basic_router.hxx>
#include <http/out.hxx>

#include "Json.h"

namespace beast = boost::beast;
namespace server = _0xdead4ead;

namespace API {

    class IRouter {

    public:
        virtual ~IRouter() {

        }

        virtual server::http::basic_router<server::http::reactor::_default::session_type> &get() = 0;

    protected:
        virtual void init() = 0;

    };
}

#endif //CPP_RESTAPI_IROUTER_H
