//
// Created by Victor Sousa on 01/10/2019.
//

#ifndef CPP_RESTAPI_AROUTER_H
#define CPP_RESTAPI_AROUTER_H

#include "AClass.h"
#include "IRouter.h"


namespace beast = boost::beast;
namespace server = _0xdead4ead;
typedef beast::http::status status_code;

namespace API {

    class ARouter: public IRouter, public AClass {

    public:
        ARouter(std::string const &className = "ARouter");
        virtual ~ARouter();

        server::http::basic_router<server::http::reactor::_default::session_type> &get();

    protected:
        virtual void init() = 0;
        server::http::basic_router<server::http::reactor::_default::session_type> _router;

    public:
        static auto send(const beast::http::request<beast::http::string_body>& request,
                         typename beast::http::string_body::value_type body,
                         beast::http::status const &status_code,
                         beast::string_view content) {
            beast::http::response<beast::http::string_body> response{status_code, request.version()};
            response.set(beast::http::field::server, BOOST_BEAST_VERSION_STRING);
            response.set(beast::http::field::content_type, content);
            response.body() = body;
            response.prepare_payload();
            response.keep_alive(request.keep_alive());

            return response;
        }

    };
}

#endif //CPP_RESTAPI_AROUTER_H
