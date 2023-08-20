#ifndef _RIVEEXTENSION_CONTROLLER_H_
#define _RIVEEXTENSION_CONTROLLER_H_

// Stdlib
#include <vector>

// Godot
#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/string.hpp>

// Rive
#include <rive/animation/state_machine_instance.hpp>
#include <rive/file.hpp>

// Skia
#include <skia/dependencies/skia/include/core/SkBitmap.h>
#include <skia/dependencies/skia/include/core/SkCanvas.h>
#include <skia/dependencies/skia/include/core/SkSurface.h>

#include <skia/renderer/include/skia_factory.hpp>
#include <skia/renderer/include/skia_renderer.hpp>

// Extension
#include "utils/types.hpp"

class RiveController {
   public:
    godot::String path;
    rive::Vec2D size = rive::Vec2D{ 1, 1 };
    float elapsed = 0;

    Ptr<rive::File> file = nullptr;
    sk_sp<SkSurface> surface = nullptr;
    Ptr<rive::SkiaRenderer> renderer = nullptr;
    Ptr<rive::SkiaFactory> factory = nullptr;
    Ptr<rive::ArtboardInstance> artboard = nullptr;
    Ptr<rive::Scene> scene = nullptr;
    rive::Mat2D inverse_transform;

   public:
    RiveController();
    RiveController(godot::String path_value);
    void load();
    void start();
    void resize(unsigned int width, unsigned int height);
    void pointer_down(rive::Vec2D position);
    void pointer_up(rive::Vec2D position);
    void pointer_move(rive::Vec2D position);

    godot::PackedByteArray frame(float delta);

   private:
    void update_align();
    godot::PackedByteArray byte_array();
    SkImageInfo make_image_info();
};

#endif