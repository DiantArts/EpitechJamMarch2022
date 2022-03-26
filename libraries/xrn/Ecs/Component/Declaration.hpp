#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Declares components
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// COMPONENT macro only works in the "::xrn::ecs::component" namespace. To
// declare a macro in another namespace, use COMPONENT_IN_NAMESPACE with
// the first argument being the current namespace.
// To use an other file (or multiple files) to declare components, please go
// inside the "/xrn/Ecs/Component/Detail/Declaration.hpp" file, and look at the
// "User-defined Components" sections. It is where the component declaration
// files are included and used.
// Components are forwarded declared here, but can be defined else where.
///////////////////////////////////////////////////////////////////////////
#include <Game/Component/Drawable.hpp>
#include <Game/Component/Movable.hpp>
#include <Game/Component/Gravity.hpp>
#include <Game/Component/Hitbox.hpp>
#include <Game/Component/Text.hpp>

namespace xrn::ability {

ABILITY_IN_NAMESPACE(xrn::ability, Enemy);

}
