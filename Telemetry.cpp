#include "Telemetry.hpp"

namespace Dualys::telemetry
{

    // Émet une ligne JSONL (ou plain) vers un fichier/FD
    Result<void> emit_line(std::string_view line)
    {
        // Implémentation de la fonction emit_line
    }

    // Helpers (optionnels) pour produire un petit JSON manuellement
    std::string kv(const char *k, std::string_view v)
    {
        // Implémentation de la fonction kv pour string_view
    }
    std::string kv(const char *k, uint64_t v)
    {
        // Implémentation de la fonction kv pour uint64_t
    }
    std::string obj(std::initializer_list<std::string> list)
    {
        // Implémentation de la fonction obj
    }

}