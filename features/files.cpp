//
// Created by eter on 22/06/2023.
//

#include "../headers/CNegtuneDirectives.h"

using namespace std;

namespace fs = filesystem;

bool fileExists( string fileName )
{
    ifstream File(fileName);

    return File.good();
}

bool writeFile( string dirFileName, string content )
{

    string data, cpData = "";

    // Copy the data already in the file if it does exist, that's why the if sentence
    ifstream RFile(dirFileName);

    if (RFile.good()) {
        // It saves each line of the document RFile in data
        while(getline(RFile, data)){
            cpData += data + "\n";
        }
    }
    // Close file for good practices
    RFile.close();

    ofstream File(dirFileName);

    File << cpData + content; // Putting the data before and after

    return File.good();
}

bool removeFile(string path)
{
    bool fileRemoved = fs::remove(path);
    return fileRemoved;
}

bool directoryExists(string path)
{
    bool directoryExists = fs::exists(path);
    return directoryExists;
}

