#pragma once

#include "llvm/Config/llvm-config.h"

#if LLVM_VERSION_MAJOR <= 15
#include "llvm/ADT/Triple.h"
#include "llvm/Support/Host.h"
#else
#include "llvm/TargetParser/Host.h"
#include "llvm/TargetParser/Triple.h"
#endif