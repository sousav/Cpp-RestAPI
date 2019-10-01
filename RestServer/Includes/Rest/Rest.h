//
// Created by Victor Sousa on 28/09/2019.
//

#ifndef CPP_RESTAPI_REST_H
#define CPP_RESTAPI_REST_H

#include <utility>
#include <thread>

#include <boost/asio/posix/stream_descriptor.hpp>
#include <boost/asio/signal_set.hpp>

#include <http/reactor/listener.hxx>
#include <http/reactor/session.hxx>
#include <http/basic_router.hxx>
#include <http/out.hxx>

#include "AClass.h"

#include "Database.h"

namespace beast = boost::beast;
namespace server = _0xdead4ead;

namespace API {

    class Rest: public AClass {

    public:
        Rest(std::string const &baseRouterPath, unsigned short port, std::string const &className = "Rest");
        ~Rest();

        void run();

    private:
        std::string _baseRouterPath;
        unsigned short const _port;

    private:
        static boost::asio::io_context ioc;
        static boost::asio::posix::stream_descriptor out;
        static boost::asio::signal_set sig_set;

    };

}

#endif //CPP_RESTAPI_REST_H
