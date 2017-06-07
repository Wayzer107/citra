// Copyright 2017 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include "core/frontend/input.h"

namespace InputCommon {
namespace LibRetro {

/// Function provided by Retroarch dynamically to poll input.
int16_t CheckButton(unsigned port, unsigned device,
                 unsigned index, unsigned id);

/// Initializes and registers LibRetro device factories
void Init();

/// Unresisters LibRetro device factories and shut them down.
void Shutdown();

} // namespace LibRetro
} // namespace InputCommon
