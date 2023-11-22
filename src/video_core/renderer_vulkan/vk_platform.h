// Copyright 2023 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <memory>
#include <variant>

#include "common/common_types.h"
#include "common/dynamic_library/dynamic_library.h"
#include "video_core/renderer_vulkan/vk_common.h"

namespace Frontend {
class EmuWindow;
class GraphicsContext;
enum class WindowSystemType : u8;
} // namespace Frontend

namespace Vulkan {

using DebugCallback =
    std::variant<vk::UniqueDebugUtilsMessengerEXT, vk::UniqueDebugReportCallbackEXT>;

std::shared_ptr<Common::DynamicLibrary> OpenLibrary(
    [[maybe_unused]] Frontend::GraphicsContext* context = nullptr);

vk::SurfaceKHR CreateSurface(vk::Instance instance, const Frontend::EmuWindow& emu_window);

vk::UniqueInstance CreateInstance(Frontend::WindowSystemType window_type,
                                    VkInstance vk_instance,
                                    PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr);

vk::UniqueInstance CreateInstance(const Common::DynamicLibrary& library,
                                  Frontend::WindowSystemType window_type, bool enable_validation,
                                  bool dump_command_buffers);

DebugCallback CreateDebugCallback(vk::Instance instance, bool& debug_utils_supported);

} // namespace Vulkan
