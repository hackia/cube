#pragma once
#include "Core.hpp"

namespace Dualys
{

    // Limites “portables” (meilleur-effort selon l’OS)
    struct Limits
    {
        uint64_t memory_bytes = 0; // 0 = illimité
        uint32_t cpu_percent = 0;  // 0 = illimité (sinon 1..100)
        uint64_t disk_bytes = 0;   // quota logique (VFS)
        uint64_t net_tx_bytes = 0; // quota I/O logique (proxy)
        uint64_t net_rx_bytes = 0;
        bool no_network = false;
        uint64_t ttl_ms = 0; // temps mur max (0 = infini)
    };

    struct FsMount
    {
        std::string host_path;  // chemin sur l’hôte
        std::string guest_path; // “montage” logique dans la cage
        bool read_only = false;
    };

    struct Policy
    {
        Limits limits;
        std::vector<FsMount> mounts;
        std::vector<std::string> env;  // VAR=VALUE
        std::vector<std::string> argv; // binaire + args
        std::string cwd;               // répertoire de travail logique
        bool drop_privs = true;        // diminuer les privilèges si possible
    };

    // Parsing/validation du DSL .hc -> Policy
    namespace policy
    {

        // `basedir` sert à résoudre @include "..."
        Result<Policy> from_hc(std::string_view text, std::string_view basedir);

        // Vérifie cohérences (ex: argv non vide, chemins montés valides, N=2^dim si hypercube, etc.)
        Result<void> validate(const Policy &);

    }
}