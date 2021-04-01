#pragma once

#define BF_MODULE_VERSION "0.0.1"

#if defined(unix) || defined(__unix__) || defined(__unix)
#define IS_UNIX
#endif

// SDK
#include "cpp-sdk/SDK.h"
#include "Log.h"

// Module
#include "runtime.h"
#include "resource.h"
