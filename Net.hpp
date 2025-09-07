#pragma once
#include "Core.hpp"
#include <string>
#include <vector>

namespace Dualys::net {

// Coupe tout réseau sortant (mode “no-net” via proxy/broker)
Result<void> no_network();

// Autorise uniquement ces destinations (host[:port], CIDR, etc.)
Result<void> allowlist(const std::vector<std::string>& rules);

// Fixe des quotas logiques (mesurés par proxy)
Result<void> set_quota(uint64_t tx_bytes, uint64_t rx_bytes);

} // namespace dualys::net
