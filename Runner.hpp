#pragma once
#include "Policy.hpp"

namespace Dualys::exec {

struct Exit {
  int code = 0;            // code de retour du job
  uint64_t rss_max = 0;    // pic mémoire observé (si dispo)
  uint64_t cpu_time_ms = 0; // temps CPU (si dispo)
};

// Lance et attend la fin (applique limites “meilleur-effort” selon l’OS)
Result<Exit> run(const Policy&);

// Variante async (optionnelle plus tard) : spawn et rend le PID/handle
struct Handle {
  int pid = -1; // ou HANDLE sous Windows via opaque struct
};
Result<Handle> spawn(const Policy&);

} // namespace dualys::exec
