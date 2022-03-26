///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>
#include <xrn/Ecs.hpp>
#include <Game/Menu.hpp>
#include <Game/Window.hpp>
#include <Game/Systems.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// *structors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::xrn::Menu::Menu(
    ::xrn::Window& window
)
    : m_window{ window }
{
    m_entities.emplace(::xrn::component::Drawable{ "testWallpaper.png", m_window });

    { // play text
        ::xrn::component::Text text{ "Play", ::sf::Color::Blue, m_window };
#ifdef DEBUG_HITBOX
        ::xrn::component::Hitbox hitbox{ 5, 5, 225, 90, window };
#else
        ::xrn::component::Hitbox hitbox{ 0, 0, 1920, 200 };
#endif

        ::xrn::component::Movable movable;
        movable.setPosition(m_window.getSize().x / 2 - 112.5, m_window.getSize().y / 2.5 - 50);

        text.updatePosition(movable);
        hitbox.updatePosition(movable);

        m_playButtonId = m_entities.emplace(::std::move(text), ::std::move(hitbox)).getId();
    }

    { // quit text
        ::xrn::component::Text text{ "Quit", ::sf::Color::Blue, m_window };
#ifdef DEBUG_HITBOX
        ::xrn::component::Hitbox hitbox{ 5, 5, 225, 90, window };
#else
        ::xrn::component::Hitbox hitbox{ 0, 0, 1920, 200 };
#endif

        ::xrn::component::Movable movable;
        movable.setPosition(m_window.getSize().x / 2 - 112.5, m_window.getSize().y / 1.75 - 50);

        text.updatePosition(movable);
        hitbox.updatePosition(movable);

        m_quitButtonId = m_entities.emplace(::std::move(text), ::std::move(hitbox)).getId();
    }

    // systems
    m_systems.emplace<::xrn::system::overlapText>();

    // const systems
    m_constSystems.emplace<::xrn::system::draw>();
    m_constSystems.emplace<::xrn::system::drawText>();
#ifdef DEBUG_HITBOX
    m_constSystems.emplace<::xrn::system::drawHitbox>();
#endif
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Actions
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
auto ::xrn::Menu::update()
    -> bool
{
    m_systems.run(m_clock.restart(), m_entities);
    return true;
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::Menu::draw() const
{
    m_window.clear();
    m_constSystems.run(m_constClock.restart(), m_entities);
    m_window.display();
}

///////////////////////////////////////////////////////////////////////////
[[ nodiscard ]] auto ::xrn::Menu::isOver() const
    -> bool
{
    return m_isOver;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::Menu::handleEvent(
    sf::Event& event
) -> bool
{
    switch (event.type) {
    case ::sf::Event::Closed: m_isOver = true; return false;
    case ::sf::Event::MouseButtonPressed:
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (
                auto* hitbox{ m_components.get<::xrn::component::Hitbox>(m_playButtonId) };
                hitbox->contains(m_window.getMousePosition())
            ) {
                return false;
            } else if (
                auto* hitbox{ m_components.get<::xrn::component::Hitbox>(m_quitButtonId) };
                hitbox->contains(m_window.getMousePosition())
            ) {
                m_isOver = true;
                return false;
            }
        }
        return true;
    case ::sf::Event::KeyPressed:
        switch (event.key.code) {
        case sf::Keyboard::Key::Escape: m_isOver = true; return false;
        default: return true;
        }
    default: return true;
    }
}
