//
// Created by Victor Sousa on 01/10/2019.
//

#include "BaseRouter.h"

extern "C" API::IRouter* create_object()
{
    return new API::BaseRouter();
}

extern "C" void destroy_object(API::IRouter* object )
{
    delete object;
}