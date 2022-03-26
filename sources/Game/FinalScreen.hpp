#pragma once

namespace xrn {

class FinalScreen {

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
    explicit FinalScreen(
        ::xrn::Window& window,
        ::std::size_t score
    );



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Actions
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Updates the scene
    ///
    /// Calls actors updates
    //
    ///////////////////////////////////////////////////////////////////////////
    auto update()
        -> bool;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Draws the scene
    ///
    /// Calls actors draws
    ///
    ///////////////////////////////////////////////////////////////////////////
    void draw() const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Is over
    ///
    /// If window is closed or should close
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto isOver() const
        -> bool;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Handles each events given by window
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto handleEvent(
        sf::Event& event
    ) -> bool;



private:

    ::xrn::ecs::component::Container m_components{};
    ::xrn::ecs::entity::Container m_entities{ m_components };
    mutable ::xrn::Clock m_clock{};
    ::xrn::ecs::system::Container m_systems{};
    mutable ::xrn::Clock m_constClock{};
    ::xrn::ecs::system::ConstContainer m_constSystems{};

    ::xrn::Window& m_window;
    bool m_isOver{ false };

    ::xrn::Id m_quitButtonId{ 0 };

};



} // namespace xrn
