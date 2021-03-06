#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Run
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void ::xrn::ecs::system::Container::run(
    ::xrn::Time t,
    ::xrn::ecs::entity::Container& entities
)
{
    for (auto& system : m_systems) {
        system->operator()(t, entities);
    }
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Others
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    auto function,
    typename... Types
> void ::xrn::ecs::system::Container::emplace()
{
    m_systems.push_back(::std::make_unique<::xrn::ecs::System<function, Types...>>());
}
