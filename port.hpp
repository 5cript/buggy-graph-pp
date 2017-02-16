#pragma once

#include "json_convert.hpp"

namespace Buggy
{
    struct Port : public JSON::Stringifiable <Port>
                , public JSON::Parsable <Port>
    {
        std::string port;
        std::string kind;
        std::string type;
    };
}

BOOST_FUSION_ADAPT_STRUCT
(
    Buggy::Port,
    (std::string, port)
    (std::string, kind)
    (std::string, type)
)
