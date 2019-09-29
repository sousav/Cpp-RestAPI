//
// Created by Victor Sousa on 28/09/2019.
//

#include "Rest/Rest.h"
#include "Rest/Router.h"

namespace API {

    boost::asio::io_context Rest::ioc;
    boost::asio::posix::stream_descriptor Rest::out{Rest::ioc, ::dup(STDERR_FILENO)};
    boost::asio::signal_set Rest::sig_set(Rest::ioc, SIGINT, SIGTERM);

    Rest::Rest(unsigned short port, const std::string &className): AClass(className), _port(port) {

    }

    Rest::~Rest() {

    }

    void Rest::run() {

        server::http::basic_router<server::http::reactor::_default::session_type> router{std::regex::ECMAScript};
        Router baseRouter;
        router.use("", baseRouter.get());

        // Error and warning handler
        const auto& onError = [](auto system_error_code, auto from) {
            server::http::out::prefix::version::time::pushn<std::ostream>(
                    out, "From:", from, "Info:", system_error_code.message());

            // I/O context will be stopped, if code value is EADDRINUSE or EACCES
            if (system_error_code == boost::system::errc::address_in_use or
                system_error_code == boost::system::errc::permission_denied)
                ioc.stop();
        };


        // Handler incoming connections
        const auto& onAccept = [&](auto asio_socket) {
            auto endpoint = asio_socket.remote_endpoint();
            server::http::out::prefix::version::time::pushn<std::ostream>(
                    out, endpoint.address().to_string() + ':' + std::to_string(endpoint.port()), "connected!");

            // Start receive HTTP request
            server::http::reactor::_default::session_type::recv(std::move(asio_socket), router, onError);
        };


        // Start accepting
        auto const address = boost::asio::ip::address_v4::any();
        server::http::out::prefix::version::time::pushn<std::ostream>(out, "Start accepting on", address.to_string() + ':' + std::to_string(this->_port));
        server::http::reactor::_default::listener_type::launch(ioc, {address, this->_port}, onAccept, onError);


        // Capture SIGINT and SIGTERM to perform a clean shutdown
        sig_set.async_wait([](boost::system::error_code const&, int sig) {
            server::http::out::prefix::version::time::pushn<std::ostream>(
                    out, "Capture", sig == SIGINT ? "SIGINT." : "SIGTERM.", "Stop!");
            ioc.stop();
        });


        // Run the I/O service on the requested number of threads
        uint32_t pool_size = std::thread::hardware_concurrency() * 2;
        std::vector<std::thread> threads;
        threads.reserve(pool_size > 0 ? pool_size : 4);
        for(uint32_t i = 0; i < pool_size; i++)
            threads.emplace_back(std::bind(static_cast<std::size_t (boost::asio::io_context::*)()>(&boost::asio::io_context::run), std::ref(ioc)));

        // Block until all the threads exit
        for(auto& t : threads)
            t.join();
    }

}