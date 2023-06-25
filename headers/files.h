//
// Created by eter on 22/06/2023.
//

#include <string>

#ifndef CNEGTUNE_FILES_H
#define CNEGTUNE_FILES_H

bool fileExists( std::string fileName );
bool writeFile( std::string dirFileName, std::string content );
bool removeFile(std::string path);
bool directoryExists(std::string path);

#endif //CNEGTUNE_FILES_H
