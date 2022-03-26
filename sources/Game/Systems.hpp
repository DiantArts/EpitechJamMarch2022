#pragma once

namespace xrn::system {

///////////////////////////////////////////////////////////////////////////
/// \brief Draws
///
///////////////////////////////////////////////////////////////////////////
inline void draw(
    const ::xrn::component::Drawable& drawable
)
{
    drawable.draw();
}

///////////////////////////////////////////////////////////////////////////
/// \brief Draws
///
///////////////////////////////////////////////////////////////////////////
inline void drawText(
    const ::xrn::component::Text& text
)
{
    text.draw();
}

inline void overlapText(
    ::xrn::component::Text& text,
    const ::xrn::component::Hitbox& hitbox
)
{
    text.setOverlapColor(hitbox);
}

///////////////////////////////////////////////////////////////////////////
/// \brief Draws
///
///////////////////////////////////////////////////////////////////////////
inline void drawHitbox(
    const ::xrn::component::Hitbox& hitbox
)
{
#ifdef DEBUG_HITBOX
    hitbox.draw();
#endif
}

///////////////////////////////////////////////////////////////////////////
/// \brief Moves
///
///////////////////////////////////////////////////////////////////////////
inline void updatePosition(
    ::xrn::Time deltaTime,
    ::xrn::component::Movable& movable
)
{
    movable.updatePosition(deltaTime);
}

///////////////////////////////////////////////////////////////////////////
/// \brief Moves
///
///////////////////////////////////////////////////////////////////////////
inline void moveDrawable(
    ::xrn::component::Movable& movable,
    ::xrn::component::Drawable& drawable
)
{
    drawable.updatePosition(movable);
}

///////////////////////////////////////////////////////////////////////////
/// \brief Moves
///
///////////////////////////////////////////////////////////////////////////
inline void moveHitbox(
    ::xrn::component::Movable& movable,
    ::xrn::component::Hitbox& hitbox
)
{
    hitbox.updatePosition(movable);
}

///////////////////////////////////////////////////////////////////////////
/// \brief Gravity
///
///////////////////////////////////////////////////////////////////////////
inline void applyGravity(
    ::xrn::Time deltaTime,
    ::xrn::component::Gravity& gravity,
    ::xrn::component::Movable& movable
)
{
    if (!movable.isGrounded()) {
        auto speed{ movable.getSpeed() };
        if (speed.y >= 0) {
            speed.y += (gravity.getStrength() + 10000) / 100;
            movable.setSpeed(speed);
        } else {
            speed.y += (gravity.getStrength() + 10000) / 100;
            movable.setSpeed(speed);
        }
    }
}

} // namespace xrn::system
