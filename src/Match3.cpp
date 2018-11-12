#include "Match3.hpp"

using namespace std;
using namespace ouzel;

Match3::Match3():
    bundle(engine->getCache())
{
#if OUZEL_PLATFORM_LINUX
    sharedEngine->getFileSystem()->addResourcePath("Resources");
#elif OUZEL_PLATFORM_WINDOWS
    sharedEngine->getFileSystem()->addResourcePath("Resources");
#endif

    eventHandler.keyboardHandler = std::bind(&Match3::handleKeyboard, this, std::placeholders::_1);
    eventHandler.mouseHandler = std::bind(&Match3::handleMouse, this, std::placeholders::_1);
    eventHandler.touchHandler = std::bind(&Match3::handleTouch, this, std::placeholders::_1);
    eventHandler.gamepadHandler = std::bind(&Match3::handleGamepad, this, std::placeholders::_1);
    eventHandler.uiHandler = std::bind(&Match3::handleUI, this, std::placeholders::_1);

    engine->getEventDispatcher().addEventHandler(&eventHandler);

    engine->getRenderer()->setClearColor(Color(64, 0, 0));

    engine->getSceneManager().setScene(&scene);

    cameraActor.addComponent(&camera);
    layer.addChild(&cameraActor);
    scene.addLayer(&layer);

    engine->getInputManager()->startDeviceDiscovery();
}

bool Match3::handleKeyboard(const KeyboardEvent& event)
{
    if (event.type == ouzel::Event::Type::KEY_PRESS)
    {
        Vector3 position = cameraActor.getPosition();

        switch (event.key)
        {
            case input::Keyboard::Key::UP:
                position.y += 10.0f;
                break;
            case input::Keyboard::Key::DOWN:
                position.y -= 10.0f;
                break;
            case input::Keyboard::Key::LEFT:
                position.x -= 10.0f;
                break;
            case input::Keyboard::Key::RIGHT:
                position.x += 10.0f;
                break;
            case input::Keyboard::Key::ENTER:
                engine->getWindow()->setSize(Size2(640.0f, 480.0f));
                break;
            default:
                break;
        }

        cameraActor.setPosition(position);
    }

    return false;
}

bool Match3::handleMouse(const MouseEvent& event) const
{
    switch (event.type)
    {
        case ouzel::Event::Type::MOUSE_PRESS:
        {
            break;
        }
        case ouzel::Event::Type::MOUSE_MOVE:
        {
            break;
        }
        default:
            break;
    }

    return false;
}

bool Match3::handleTouch(const TouchEvent& event) const
{
    return false;
}

bool Match3::handleGamepad(const GamepadEvent& event) const
{
    if (event.type == ouzel::Event::Type::GAMEPAD_BUTTON_CHANGE)
    {

    }

    return false;
}

bool Match3::handleUI(const UIEvent& event) const
{
    return false;
}
