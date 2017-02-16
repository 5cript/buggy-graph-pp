#pragma once

#include "../json_convert.hpp"

namespace Buggy
{
    struct TypeInformation : public JSON::Stringifiable <TypeInformation>
                           , public JSON::Parsable <TypeInformation>
    {

    };

    struct MetaInformation : public JSON::Stringifiable <MetaInformation>
                           , public JSON::Parsable <MetaInformation>
    {
        boost::optional <float> value;
        boost::optional <std::string> type;
        boost::optional <TypeInformation> typeInformation;

    };
}

BOOST_FUSION_ADAPT_STRUCT
(
    Buggy::TypeInformation,
)

BOOST_FUSION_ADAPT_STRUCT
(
    Buggy::MetaInformation,
    (boost::optional <float>, value)
    (boost::optional <std::string>, type)
    (boost::optional <TypeInformation>, typeInformation)
)
