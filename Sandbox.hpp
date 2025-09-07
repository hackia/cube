#pragma once
#include "Policy.hpp"

namespace Dualys::sandbox {

// Applique la meilleure isolation disponible selon l’OS/droits :
// - Linux : cgroup v2 + rlimit, Landlock si dispo (sinon noop)
// - Windows : Job Objects + Restricted Token
// - OpenBSD : pledge/unveil
// - FreeBSD : Capsicum (+RCTL)
// - macOS : sandbox_init + rlimit
Result<void> apply_portable(const Policy&);

} // namespace dualys::sandbox
