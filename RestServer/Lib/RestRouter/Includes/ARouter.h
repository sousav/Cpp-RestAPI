//
// Created by Victor Sousa on 01/10/2019.
//

#ifndef CPP_RESTAPI_AROUTER_H
#define CPP_RESTAPI_AROUTER_H

#include "IRouter.h"
#include "../../ClassBase/Includes/AClass.h"


namespace beast = boost::beast;
namespace server = _0xdead4ead;

namespace API {

    class ARouter: public IRouter, public AClass {

    public:
        ARouter(std::string const &className = "ARouter");
        virtual ~ARouter();

        server::http::basic_router<server::http::reactor::_default::session_type> &get();

    protected:
        virtual void init() = 0;
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


#endif //CPP_RESTAPI_AROUTER_H
