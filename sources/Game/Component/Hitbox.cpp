///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>
#include <xrn/Ecs.hpp>
#include <Game/Window.hpp>
#include <Game/Scene.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// *structors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
#ifdef DEBUG_HITBOX
::xrn::component::Hitbox::Hitbox(
    int left,
    int top,
    int width,
    int height,
    ::xrn::Window& window
)
    : m_hitbox{ 0, 0, width, height }
    , m_relativePosition{ static_cast<float>(left), static_cast<float>(top) }
    , m_window{ &window }
{
    m_hitboxDebug.setOutlineColor(::sf::Color::Yellow);
    m_hitboxDebug.setFillColor(::sf::Color::Transparent);
    m_hitboxDebug.setOutlineThickness(1);
}
#else
::xrn::component::Hitbox::Hitbox(
    int left,
    int top,
    int width,
    int height
)
    : m_hitbox{ 0, 0, width, height }
    , m_relativePosition{ static_cast<float>(left), static_cast<float>(top) }
{}
#endif



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Getters/setters
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void ::xrn::component::Hitbox::updatePosition(
    const ::xrn::component::Movable& movable
)
{
    m_hitbox.left = movable.getPosition().x;
    m_hitbox.top = movable.getPosition().y;
#ifdef DEBUG_HITBOX
    m_hitboxDebug.setSize({ static_cast<float>(m_hitbox.width), static_cast<float>(m_hitbox.height) });
    m_hitboxDebug.setPosition({m_hitbox.left + m_relativePosition.x, m_hitbox.top + m_relativePosition.y});
#endif
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::component::Hitbox::getPosition() const
    -> ::sf::Vector2f
{
    return { static_cast<float>(m_hitbox.left), static_cast<float>(m_hitbox.top) };
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::component::Hitbox::getSize() const
    -> ::sf::Vector2f
{
    return { static_cast<float>(m_hitbox.width), static_cast<float>(m_hitbox.height) };
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::component::Hitbox::draw() const
{
#ifdef DEBUG_HITBOX
    m_window->draw(m_hitboxDebug);
#endif
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::component::Hitbox::contains(
    const ::xrn::component::Hitbox& other
) const
    -> bool
{
    return m_hitbox.intersects(other.m_hitbox);
}

auto ::xrn::component::Hitbox::contains(
    const ::sf::Vector2i& other
) const
    -> bool
{
    return m_hitbox.contains(other);
}