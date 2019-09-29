//
// Created by Victor Sousa on 29/09/2019.
//

#ifndef CPP_RESTAPI_ROUTER_H
#define CPP_RESTAPI_ROUTER_H

#include "AClass.h"
#include "Rest/Rest.h"

#include "Json.h"

namespace API {

    class Router: public AClass {

    public:
        Router(std::string const &className = "Router");
        virtual ~Router();

        server::http::basic_router<server::http::reactor::_default::session_type> &get();

    protected:
        virtual void init();
        server::http::basic_router<server::http::reactor::_default::session_type> _router;

    protected:
        // Returns a success response (200)
        template<class ResponseBody, class RequestBody>
        static auto make_200(const beast::http::request<RequestBody>& request,
                      typename ResponseBody::value_type body,
                      beast::string_view content)
        {
            beast::http::response<ResponseBody> response{beast::http::status::ok, request.version()};
            response.set(beast::http::field::server, BOOST_BEAST_VERSION_STRING);
            response.set(beast::http::field::content_type, content);
            response.body() = body;
            response.prepare_payload();
            response.keep_alive(request.keep_alive());

            return response;
        }

        // Returns a not found response (404)
        template<class ResponseBody, class RequestBody>
        static auto make_404(const beast::http::request<RequestBody>& request,
                      typename ResponseBody::value_type body,
                      beast::string_view content)
        {
            beast::http::response<ResponseBody> response{beast::http::status::not_found, request.version()};
            response.set(beast::http::field::server, BOOST_BEAST_VERSION_STRING);
            response.set(beast::http::field::content_type, content);
            response.body() = body;
            response.prepare_payload();
            response.keep_alive(request.keep_alive());

            return response;
        }

    };
}

#endif //CPP_RESTAPI_ROUTER_H
