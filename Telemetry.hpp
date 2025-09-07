#pragma once
#include "Core.hpp"
#include <string>
#include <string_view>

namespace Dualys::telemetry
{

    // Émet une ligne JSONL (ou plain) vers un fichier/FD
    Result<void> emit_line(std::string_view line);

    // Helpers (optionnels) pour produire un petit JSON manuellement
    std::string kv(const char *k, std::string_view v);   // "k":"v"
    std::string kv(const char *k, uint64_t v);           // "k":123
    std::string obj(std::initializer_list<std::string>); // { ... }

}
