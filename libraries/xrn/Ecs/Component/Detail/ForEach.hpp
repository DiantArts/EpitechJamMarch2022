#pragma once

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <xrn/Util/Id.hpp>
#include <xrn/Ecs/System/Detail/Meta/Function.hpp>

///////////////////////////////////////////////////////////////////////////
// Forward declarations
///////////////////////////////////////////////////////////////////////////
namespace xrn::ecs { class Signature; }



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Components
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

namespace xrn::ecs::component::detail {

///////////////////////////////////////////////////////////////////////////
/// \internal
/// \brief Iterates over each components
/// \ingroup ecs-component
///
/// \include ForEach.hpp <xrn/Ecs/Component/Detail/ForEach.hpp>
///
/// Iterates over each component types
///
///////////////////////////////////////////////////////////////////////////
class ForEach {

public:

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Runs a function for the component type matching the ID given as
    ///        parameter
    ///
    ///////////////////////////////////////////////////////////////////////////
    template <
        auto func,
        ::xrn::Id::Type componentIndex = 0
    > static constexpr void find(
        ::xrn::Id::Type id,
        auto&&... args
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Runs a function for each component type
    ///
    ///////////////////////////////////////////////////////////////////////////
    template <
        auto func,
        ::xrn::Id::Type componentIndex = 0
    > static constexpr void run(
        auto&&... args
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Runs a function for each component type contained by the
    ///        signature
    ///
    ///////////////////////////////////////////////////////////////////////////
    template <
        auto func,
        ::xrn::Id::Type componentIndex = 0
    > static constexpr void runIfSignature(
        const ::xrn::ecs::Signature& signature,
        auto&&... args
    );

    //////////////////////////////////////////////////////////////////////////
    /// \brief Runs a function for each component type
    ///
    ///////////////////////////////////////////////////////////////////////////
    template <
        auto func,
        ::xrn::Id::Type componentIndex = 0
    > static constexpr void runWithId(
        auto&&... args
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Runs a function for each component type contained by the
    ///        signature
    ///
    ///////////////////////////////////////////////////////////////////////////
    template <
        auto func,
        ::xrn::Id::Type componentIndex = 0
    > static constexpr void runWithId(
        const ::xrn::ecs::Signature& signature,
        auto&&... args
    );

};

} // namespace xrn::ecs::component::detail



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Abilities
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

namespace xrn::ecs::ability::detail {

///////////////////////////////////////////////////////////////////////////
/// \internal
/// \brief Iterates over each ability
/// \ingroup ecs-component
///
/// \include ForEach.hpp <xrn/Ecs/Component/Detail/ForEach.hpp>
///
/// Iterates over each ability types
///
///////////////////////////////////////////////////////////////////////////
class ForEach {

public:

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Runs a function for the ability type matching the ID given as
    ///        parameter
    ///
    ///////////////////////////////////////////////////////////////////////////
    template <
        auto func,
        ::xrn::Id::Type abilityIndex = 0
    > static constexpr void find(
        ::xrn::Id::Type id,
        auto&&... args
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Runs a function for each ability type
    ///
    ///////////////////////////////////////////////////////////////////////////
    template <
        auto func,
        ::xrn::Id::Type abilityIndex = 0
    > static constexpr void run(
        auto&&... args
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Runs a function for each ability type contained by the
    ///        signature
    ///
    ///////////////////////////////////////////////////////////////////////////
    template <
        auto func,
        ::xrn::Id::Type abilityIndex = 0
    > static constexpr void runIfSignature(
        const ::xrn::ecs::Signature& signature,
        auto&&... args
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Runs a function for each ability type contained by the
    ///        signature
    ///
    ///////////////////////////////////////////////////////////////////////////
    template <
        auto func,
        ::xrn::Id::Type abilityIndex = 0
    > static constexpr void runWithId(
        auto&&... args
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Runs a function for each ability type contained by the
    ///        signature
    ///
    ///////////////////////////////////////////////////////////////////////////
    template <
        auto func,
        ::xrn::Id::Type abilityIndex = 0
    > static constexpr void runWithId(
        const ::xrn::ecs::Signature& signature,
        auto&&... args
    );

};

} // namespace xrn::ecs::ability::detail



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Components and Abilities
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

namespace xrn::ecs::detail {

///////////////////////////////////////////////////////////////////////////
/// \internal
/// \brief Iterates over each ability
/// \ingroup ecs-component
///
/// \include ForEach.hpp <xrn/Ecs/Component/Detail/ForEach.hpp>
///
/// Iterates over each ability types
///
///////////////////////////////////////////////////////////////////////////
class ForEach {

public:

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Runs a function for the component type matching the ID given as
    ///        parameter
    ///
    ///////////////////////////////////////////////////////////////////////////
    template <
        auto func,
        ::xrn::Id::Type componentIndex = 0
    > static constexpr void find(
        ::xrn::Id::Type id,
        auto&&... args
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Runs a function for each ability type
    ///
    ///////////////////////////////////////////////////////////////////////////
    template <
        auto func,
        ::xrn::Id::Type componentIndex = 0
    > static constexpr void run(
        auto&&... args
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Runs a function for each ability type contained by the
    ///        signature
    ///
    ///////////////////////////////////////////////////////////////////////////
    template <
        auto func,
        ::xrn::Id::Type componentIndex = 0
    > static constexpr void runIfSignature(
        const ::xrn::ecs::Signature& signature,
        auto&&... args
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Runs a function for each ability type contained by the
    ///        signature
    ///
    ///////////////////////////////////////////////////////////////////////////
    template <
        auto func,
        ::xrn::Id::Type componentIndex = 0
    > static constexpr void runWithId(
        auto&&... args
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Runs a function for each ability type contained by the
    ///        signature
    ///
    ///////////////////////////////////////////////////////////////////////////
    template <
        auto func,
        ::xrn::Id::Type componentIndex = 0
    > static constexpr void runWithId(
        const ::xrn::ecs::Signature& signature,
        auto&&... args
    );

};

} // namespace xrn::ecs::detail



///////////////////////////////////////////////////////////////////////////
// Header-implimentation
///////////////////////////////////////////////////////////////////////////
#include <xrn/Ecs/Component/Detail/ForEach.impl.hpp>
