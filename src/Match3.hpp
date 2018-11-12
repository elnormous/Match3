#pragma once

#include "ouzel.hpp"

class Match3: public ouzel::Application
{
public:
    Match3();

    bool handleKeyboard(const ouzel::KeyboardEvent& event);
    bool handleMouse(const ouzel::MouseEvent& event) const;
    bool handleTouch(const ouzel::TouchEvent& event) const;
    bool handleGamepad(const ouzel::GamepadEvent& event) const;
    bool handleUI(const ouzel::UIEvent& event) const;

protected:
    ouzel::scene::Layer layer;
    ouzel::scene::Actor cameraActor;
    ouzel::scene::Camera camera;
    ouzel::scene::Scene scene;
    ouzel::assets::Bundle bundle;

    ouzel::EventHandler eventHandler;
};
