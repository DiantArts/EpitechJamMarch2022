#pragma once

namespace xrn::component {

///////////////////////////////////////////////////////////////////////////
// Drawable
///////////////////////////////////////////////////////////////////////////
COMPONENT_IN_NAMESPACE(xrn::component, Drawable) {

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
    explicit Drawable(
        const ::std::string& filename,
        ::xrn::Window& window
    );



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Rule of 5
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    ~Drawable();

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    Drawable(
        const ::xrn::component::Drawable& other
    ) noexcept = delete;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator=(
        const ::xrn::component::Drawable& other
    ) noexcept
        -> ::xrn::component::Drawable& = delete;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    Drawable(
        ::xrn::component::Drawable&& other
    ) noexcept;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator=(
        ::xrn::component::Drawable&& other
    ) noexcept
        -> ::xrn::component::Drawable&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Swaps the containers
    ///
    /// Required for the assignement operator.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void swap(
        ::xrn::component::Drawable&& that
    ) noexcept;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Getters/Setters
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Updates the sprite size, rotation, scale and animation relative
    ///  and position
    ///
    ///////////////////////////////////////////////////////////////////////////
    void updatePosition(
        const ::xrn::component::Movable& movable
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Draws the sprite
    ///
    ///////////////////////////////////////////////////////////////////////////
    void draw() const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the texture rect
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setTextureRect(
        const sf::Rect<int>& rect
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief sets image scale
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto getScale() const
        -> float;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief sets image scale
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setScale(float scale);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief sets image scale
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setScale(float scaleX, float scaleY);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief sets image scale
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto getSprite()
        -> ::sf::Sprite&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief sets image rotation angle
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[nodiscard]] auto getRotation() const
        -> float;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief sets image rotation angle
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setRotation(float angle);



private:

    ::sf::Sprite m_sprite{};
    ::sf::Texture m_texture{};
    ::xrn::Window* m_window{ nullptr };

};

} // namespace xr::ecs::component
