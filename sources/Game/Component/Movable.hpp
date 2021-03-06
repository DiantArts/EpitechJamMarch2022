#pragma once

namespace xrn::component {

///////////////////////////////////////////////////////////////////////////
// Movable
///////////////////////////////////////////////////////////////////////////
COMPONENT_IN_NAMESPACE(xrn::component, Movable) {

public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // *structors
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    explicit Movable();



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Position
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Moves right.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void moveRight(
        float offset
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Moves left.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void moveLeft(
        float offset
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Moves up.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void moveUp(
        float offset
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Moves down.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void moveDown(
        float offset
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Moves.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void move(
        const ::sf::Vector2<float>& scale
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Moves.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void move(
        float offsetX,
        float offsetY
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Moves on x axis.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void moveX(
        float offset
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Moves on y axis.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void moveY(
        float offset
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets position.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setPosition(
        const ::sf::Vector2<float> position
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the position.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setPosition(
        float positionX,
        float positionY
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the position on X axis.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setPositionX(
        float position
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the position on Y axis.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setPositionY(
        float position
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Updates the position.
    ///
    /// Updates the position according to the global and local speed.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void updatePosition(
        ::xrn::Time deltaTime
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the position.
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto getPosition() const
        -> const ::sf::Vector2<float>&;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Speed
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the local speed.
    ///
    /// The local speed represents the aditional speed. With a value of 0, it
    /// moves to the speed of the global speed.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setSpeed(
        const ::sf::Vector2<float>& speed
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the local speed.
    ///
    /// The local speed represents the aditional speed. With a value of 0, it
    /// moves to the speed of the global speed.
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto getSpeed() const
        -> const ::sf::Vector2<float>&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the direction.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setDirection(
        const ::sf::Vector2<float>& direction
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the direction.
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto getDirection()
        -> ::sf::Vector2<float>&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the direction.
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto getDirection() const
        -> const ::sf::Vector2<float>&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief jumps
    ///
    ///////////////////////////////////////////////////////////////////////////
    void jump();

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto isGrounded() const
        -> bool;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setGrounded(
        bool value
    );

private:

    static constexpr const auto maxSpeed{ 3000.0f };
    static constexpr const auto jumpStrength{ 2000.0f };

    ::sf::Vector2<float> m_position{ 0.0f, 0.0f };
    // ::sf::Vector2<float> m_direction{ -1.0f, 0.0f };
    ::sf::Vector2<float> m_direction{ 0.0f, 1.0f };
    ::sf::Vector2<float> m_speed{ 0.0f, 0.0f };
    bool m_isGrounded{ false };

};



} // namespace xrn::component
