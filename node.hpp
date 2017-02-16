#pragma once

#include "port.hpp"
#include "settings.hpp"
#include "edge.hpp"

#ifdef GRAPH_DRAW_INFORMATION
#   include "buggy-draw-pp/draw_information.hpp"
#endif

#include "json_convert.hpp"

#include <functional>

namespace Buggy
{
    struct Node : public JSON::Stringifiable <Node>
                , public JSON::Parsable <Node>
    {
        std::string id;
        std::vector <Port> ports;
        Settings settings;
        boost::optional <std::vector <Node>> nodes;
        boost::optional <bool> atomic;
        std::string componentId;
        boost::optional <std::string> version;
        boost::optional <std::vector <std::string>> path;
        std::vector <Edge> edges;
#ifdef GRAPH_DRAW_INFORMATION
        boost::optional <DrawInformation> drawInformation; // not fundamental part of the graph, but simplifies graph drawing by a lot. (dirty, I know)
#endif
    };
}

BOOST_FUSION_ADAPT_STRUCT
(
    Buggy::Node,
    (std::string, id)
    (std::vector <Buggy::Port>, ports)
    (Buggy::Settings, settings)
    (boost::optional <std::vector <Buggy::Node>>, nodes)
    (boost::optional <bool>, atomic)
    (std::string, componentId)
    (boost::optional <std::string>, version)
    (boost::optional <std::vector <std::string> >, path)
    (std::vector <Buggy::Edge>, edges)
#ifdef GRAPH_DRAW_INFORMATION
    (boost::optional <Buggy::DrawInformation>, drawInformation)
#endif
)
