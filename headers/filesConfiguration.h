//
// Created by Cuent on 22/06/2023.
//

#include <string>

struct ServerConfiguration {
    std::string connection;
    std::string ip;
    std::string serverName;
    std::string ipVersion;
};

#ifndef CNEGTUNE_FILESCONFIGURATION_H
#define CNEGTUNE_FILESCONFIGURATION_H

void asignServer(std::string server_file, struct ServerConfiguration&);

#endif //CNEGTUNE_FILESCONFIGURATION_H
