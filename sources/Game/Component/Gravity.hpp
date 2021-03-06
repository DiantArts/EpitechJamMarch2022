#pragma once

namespace xrn::component {

///////////////////////////////////////////////////////////////////////////
// Gravity
///////////////////////////////////////////////////////////////////////////
COMPONENT_IN_NAMESPACE(xrn::component, Gravity) {

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
    explicit Gravity();



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
    [[ nodiscard ]] static auto getStrength()
        -> ::std::int8_t;



private:

    static inline ::std::int8_t strength{ 50 }; // speed percentage per second

};

} // namespace xr::ecs::component
