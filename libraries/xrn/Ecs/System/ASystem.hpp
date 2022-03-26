#pragma once

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <xrn/Util/Time.hpp>
#include <xrn/Ecs/Entity.hpp>
#include <xrn/Ecs/Component.hpp>



namespace xrn::ecs::system {

///////////////////////////////////////////////////////////////////////////
/// \internal
/// \brief Representation of how a system is stocked in containers
/// \ingroup ecs-system
///
/// \include ASystem.hpp <xrn/Ecs/System/ASystem.hpp>
///
/// ::xrn::ecs::system::ASystem represents how a system is stocked inside a
/// ::xrn::ecs::system::Container.
/// This class is aliased with ::xrn::ecs::system::ASystem.
///
/// \see ::xrn::ecs::system::System, ::xrn::ecs::system::Container
///
///////////////////////////////////////////////////////////////////////////
class ASystem {

public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructor
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    inline ASystem() noexcept;



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
    inline virtual ~ASystem() noexcept = 0;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Copy constructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    ASystem(
        const ::xrn::ecs::system::ASystem& other
    ) noexcept = delete;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Copy assign operator
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator=(
        const ::xrn::ecs::system::ASystem& other
    ) noexcept
        -> ::xrn::ecs::system::ASystem& = delete;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Move constructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    ASystem(
        ::xrn::ecs::system::ASystem&& that
    ) noexcept = delete;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Move assign operator
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator=(
        ::xrn::ecs::system::ASystem&& that
    ) noexcept
        -> ::xrn::ecs::system::ASystem& = delete;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Run
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Runs the system as const
    ///
    /// \param deltaTime Represents the time passed by the user. It is usually
    ///                  used to know the elapsed since the last runs of
    ///                  systems
    /// \param entities  Container of entities that the system will act upon
    ///
    /// \see ::xrn::util::BasicTime, ::xrn::ecs::entity::Container
    ///
    ///////////////////////////////////////////////////////////////////////////
    virtual void operator()(
        ::xrn::Time t,
        ::xrn::ecs::entity::Container& entities
    ) = 0;

};

} // namespace xrn::ecs::system



///////////////////////////////////////////////////////////////////////////
// Alias name
///////////////////////////////////////////////////////////////////////////
namespace xrn::ecs { using ASystem = ::xrn::ecs::system::ASystem; }



///////////////////////////////////////////////////////////////////////////
// Header-implimentation
///////////////////////////////////////////////////////////////////////////
#include <xrn/Ecs/System/ASystem.impl.hpp>
