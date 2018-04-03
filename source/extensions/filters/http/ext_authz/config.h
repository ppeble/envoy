#pragma once

#include <string>

#include "envoy/config/filter/http/ext_authz/v2/ext_authz.pb.h"
#include "envoy/server/filter_config.h"

#include "common/config/well_known_names.h"

namespace Envoy {
namespace Extensions {
namespace HttpFilters {
namespace ExtAuthz {

/**
 * Config registration for the external authorization filter. @see NamedHttpFilterConfigFactory.
 */
class ExtAuthzFilterConfig : public Server::Configuration::NamedHttpFilterConfigFactory {
public:
  Server::Configuration::HttpFilterFactoryCb
  createFilterFactory(const Json::Object& json_config, const std::string&,
                      Server::Configuration::FactoryContext& context) override;

  Server::Configuration::HttpFilterFactoryCb
  createFilterFactoryFromProto(const Protobuf::Message& proto_config,
                               const std::string& stats_prefix,
                               Server::Configuration::FactoryContext& context) override;

  ProtobufTypes::MessagePtr createEmptyConfigProto() override {
    return ProtobufTypes::MessagePtr{new envoy::config::filter::http::ext_authz::v2::ExtAuthz()};
  }

  std::string name() override { return Config::HttpFilterNames::get().EXT_AUTHORIZATION; }

private:
  Server::Configuration::HttpFilterFactoryCb
  createFilter(const envoy::config::filter::http::ext_authz::v2::ExtAuthz& proto_config,
               const std::string& stats_prefix, Server::Configuration::FactoryContext& context);
};

} // namespace ExtAuthz
} // namespace HttpFilters
} // namespace Extensions
} // namespace Envoy
