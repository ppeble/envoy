#pragma once

#include <string>

#include "envoy/server/instance.h"

#include "server/configuration_impl.h"

namespace Envoy {
namespace Server {
namespace Configuration {

/**
 * Config registration for the DogStatsD compatible statsd sink. @see StatsSinkFactory.
 */
class DogStatsdSinkFactory : Logger::Loggable<Logger::Id::config>, public StatsSinkFactory {
public:
  Stats::SinkPtr createStatsSink(const Protobuf::Message& config, Instance& server) override;

  ProtobufTypes::MessagePtr createEmptyConfigProto() override;

  std::string name() override;
};

} // namespace Configuration
} // namespace Server
} // namespace Envoy
