//
// Created by eter on 22/06/2023.
//

#include "../headers/CNegtuneDirectives.h"

using namespace std;

namespace fs = filesystem;

void firstMenu(string server_file, string cnegtune_files_dir)
{
    // Variable where the ip introduced by the user is gonna be saved
    string ip;

    // Verify if conf directory exists, and if not, create it
    bool directoryExist = directoryExists(cnegtune_files_dir);
    if (!directoryExist){
        fs::create_directory(cnegtune_files_dir);
    }

    // Write main information and configuration to server configuration file
    writeFile(server_file, "# Please, dont modify this file under any circumstances if you don't know the configuration patterns!\n"
                           "# For more information about the configuration patterns, please visit https://github.com/joshuamosc/CNegtune/\n\n"
                           "-connection\nremote\n\n");

    // Show Menu
    cout << endl << "--- Welcome to CNegtune ---" << endl;
    cout << endl << "[*] Please, enter the IP of the server you want to connect to" << endl;
    cout << endl << "[CNegtune]> ";
    getline(cin, ip);

    // Write server configuration
    writeFile(server_file, "-ip\n" + ip); // Where the client is gonna connect to
    writeFile(server_file, "\n-serverName\n" + ip + "_Server"); // Name to show in principal menu

    // Clear screen to go to the other menu
    clrscr();
    // Call the other menu here to create recursivity, so the program doesn't finish
    menu(server_file, cnegtune_files_dir);
}

void menu(string server_file, string cnegtune_files_dir)
{
    // Show menu
    cout << endl << "--- Welcome to CNegtune ---" << endl;
    cout << endl << "1.- Log In\n2.- Sign Up\n3.- Change server" << endl;
    // Choose an option by pressing a key
    char option = char(getch());

    // Evaluate each option
    if (option == '1')
    {
        clrscr();
        cout << "Logging in";
    }
    else if (option == '2')
    {
        clrscr();
        cout << "\nRequest an account - Form\n";
    }
    else if(option == '3')
    {
        // We are gonna remove the file to enter again the configuration
        removeFile(server_file);
        // Clear screen to show the other menu
        clrscr();
        // Create recursive function, so the program doesn't finish
        firstMenu(server_file, cnegtune_files_dir);
    }
}
