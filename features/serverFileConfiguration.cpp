//
// Created by eter on 22/06/2023.
//

#include "../headers/CNegtuneDirectives.h"

using namespace std;

void asignServer(string server_file, struct ServerConfiguration& server)
{

    string data;
    bool passIp = false, passConnection = false, passServerName = false, passIpVersion = false;

    ifstream ServerFile(server_file);
    while(getline(ServerFile, data)){
        if (passIp) {
            server.ip = data;
            passIp = false;
        }
        if (data == "-ip"){
            passIp = true;
        }

        if (passConnection) {
            server.connection = data;
            passConnection = false;
        }
        if (data == "-connection"){
            passConnection = true;
        }

        if (passServerName) {
            server.serverName = data;
            passServerName = false;
        }
        if (data == "-serverName"){
            passServerName = true;
        }

        if (passIpVersion) {
            server.ipVersion = data;
            passIpVersion = false;
        }
        if (data == "-ipVersion"){
            passIpVersion = true;
        }
    }

    ServerFile.close();

}

bool verifyValidServerConfFile(string server_file)
{
    bool isValid = false, passIp = false, passConnection = false, passServerName = false, passIpVersion = false;
    string data, ip = "", connection = "", ipVersion = "", serverName = "";

    bool serverFileExists = fileExists(server_file);

    if ( serverFileExists ) {
        ifstream File(server_file);
        while(getline(File, data)){
            if (passIp) {
                ip = data;
                passIp = false;
            }
            if (data == "-ip"){
                passIp = true;
            }

            if (passConnection) {
                connection = data;
                passConnection = false;
            }
            if (data == "-connection"){
                passConnection = true;
            }

            if (passServerName) {
                serverName = data;
                passServerName = false;
            }
            if (data == "-serverName"){
                passServerName = true;
            }

            if (passIpVersion) {
                ipVersion = data;
                passIpVersion = false;
            }
            if (data == "-ipVersion"){
                passIpVersion = true;
            }

            if ( passIp && passIpVersion && passConnection && passServerName ) {
                break;
            }
        }

        File.close();

        if (ip != "" && ipVersion != "" && serverName != "" && connection != ""){
            isValid = true;
        }
    }

    if (!isValid && serverFileExists) {
        removeFile(server_file);
    }

    return isValid;
}