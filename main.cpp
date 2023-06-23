#include "headers/CNegtuneDirectives.h"

using namespace std;

namespace fs = filesystem;

std::string CNEGTUNE_FILES_DIR;
std::string SERVER_FILE;

int main() {

    // Configure global variables depending on the OS with parameters by reference function
    globalVariables(CNEGTUNE_FILES_DIR, SERVER_FILE);

    // Verify if the server configuration file exists, to see which menu to open
    bool serverFileExists = fileExists(SERVER_FILE);

    // If it already exists, opens the regular menu
    if ( serverFileExists ) {
        menu(SERVER_FILE, CNEGTUNE_FILES_DIR);
    // If it doesn't exist, it asks for the information to create it
    } else {
        firstMenu(SERVER_FILE, CNEGTUNE_FILES_DIR);
    }

    return 0;
}
