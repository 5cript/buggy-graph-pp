#pragma once

#include "json_convert.hpp"

namespace Buggy
{
    struct Settings : public JSON::Stringifiable <Settings>
                    , public JSON::Parsable <Settings>
    {
        boost::optional <bool> isRecursive;
    };
}

BOOST_FUSION_ADAPT_STRUCT
(
    Buggy::Settings,
    (boost::optional <bool>, isRecursive)
)
