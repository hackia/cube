#pragma once
#include "Policy.hpp"

namespace Dualys::fs
{

    // Entre dans un “root” logique user-mode :
    // - change cwd vers Policy::cwd ou un root virtuel
    // - prépare l’application des montages logiques (RO/RW) côté broker
    // (Implémentation minimale au début : mapping de préfixes + vérifs)
    Result<void> enter_root(const Policy &);

    // Optionnel : calcule et applique un quota logique sur les écritures
    Result<void> set_quota(uint64_t bytes);

}
