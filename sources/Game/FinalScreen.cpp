///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>
#include <xrn/Ecs.hpp>
#include <Game/FinalScreen.hpp>
#include <Game/Window.hpp>
#include <Game/Systems.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// *structors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::xrn::FinalScreen::FinalScreen(
    ::xrn::Window& window,
    ::std::size_t score
)
    : m_window{ window }
{
    m_entities.emplace(::xrn::component::Drawable{ "testWallpaper.png", m_window });

    { // score
        ::xrn::component::Text text{ "Score: " + ::std::to_string(score), ::sf::Color::Blue, m_window };

        ::xrn::component::Movable movable;
        movable.setDirection({0.0f, 1.0f});
        movable.setPosition(m_window.getSize().x / 2 - 250, m_window.getSize().y / 2.5 - 50);

        text.updatePosition(movable);
        m_entities.emplace(::std::move(text));
    }

    { // quit text
        ::xrn::component::Text text{ "Return to menu", ::sf::Color::Blue, m_window };
#ifdef DEBUG_HITBOX
        ::xrn::component::Hitbox hitbox{ 5, 5, 775, 90, window };
#else
        ::xrn::component::Hitbox hitbox{ 0, 0, 775, 90 };
#endif

        ::xrn::component::Movable movable;
        movable.setPosition(m_window.getSize().x / 2 - 390, m_window.getSize().y / 1.75 - 50);

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
auto ::xrn::FinalScreen::update()
    -> bool
{
    m_systems.run(m_clock.restart(), m_entities);
    return true;
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::FinalScreen::draw() const
{
    m_window.clear();
    m_constSystems.run(m_constClock.restart(), m_entities);
    m_window.display();
}

///////////////////////////////////////////////////////////////////////////
[[ nodiscard ]] auto ::xrn::FinalScreen::isOver() const
    -> bool
{
    return m_isOver;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::FinalScreen::handleEvent(
    sf::Event& event
) -> bool
{
    switch (event.type) {
    case ::sf::Event::Closed: m_isOver = true; return false;
    case ::sf::Event::MouseButtonPressed:
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (
                auto* hitbox{ m_components.get<::xrn::component::Hitbox>(m_quitButtonId) };
                hitbox->contains(m_window.getMousePosition())
            ) {
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
