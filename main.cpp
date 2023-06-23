#include "headers/CNegtuneDirectives.h"

using namespace std;

namespace fs = filesystem;

std::string CNEGTUNE_FILES_DIR;
std::string SERVER_FILE;
struct ServerConfiguration server;

int main() {

    // Configure global variables depending on the OS with parameters by reference function
    globalVariables(CNEGTUNE_FILES_DIR, SERVER_FILE);

    // Verify if the server configuration file has a valid format
    bool validServerConfFile = verifyValidServerConfFile(SERVER_FILE);

    // If it already exists, opens the regular menu
    if ( validServerConfFile ) {
        menu(SERVER_FILE, CNEGTUNE_FILES_DIR, server);
    // If it doesn't exist, it asks for the information to create it
    } else {
        firstMenu(SERVER_FILE, CNEGTUNE_FILES_DIR, server);
    }

    return 0;
}
