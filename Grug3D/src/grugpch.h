#pragma once

//STANDARD LIBS
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

//LOGGING INTERFACE (via spdlog)
#include "Grug3D/Log.h"

#ifdef GRUG_PLATFORM_WINDOWS
	#include <Windows.h>
#endif //GRUG_PLATFORM_WINDOWS

