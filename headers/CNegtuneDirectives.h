//
// Created by eter on 22/06/2023.
//

#pragma once

#ifndef CNEGTUNE_CNEGTUNEDIRECTIVES_H
#define CNEGTUNE_CNEGTUNEDIRECTIVES_H

// C/C++ Libraries

#include <iostream>
#include <filesystem>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <string>

// CNegtune Libraries

#include "files.h"
#include "crossPlatformsFunctionalities.h"
#include "menu.h"

// Macros
#if defined(_WIN64) || defined(_WIN32)
#include <windows.h> // Library required to know the current username
#endif

#endif //CNEGTUNE_CNEGTUNEDIRECTIVES_H
