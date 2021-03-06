#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::xrn::ecs::entity::Reference::Reference() noexcept
    : m_components{ nullptr }, m_entity{ nullptr }
{}

///////////////////////////////////////////////////////////////////////////
::xrn::ecs::entity::Reference::Reference(
    ::xrn::ecs::component::Container& components,
    ::xrn::ecs::entity::Entity& entity
) noexcept
    : m_components{ &components }, m_entity{ &entity }
{}

///////////////////////////////////////////////////////////////////////////
::xrn::ecs::entity::Reference::Reference(
    ::xrn::ecs::entity::Entity& entity,
    ::xrn::ecs::component::Container& components
) noexcept
    : m_components{ &components }, m_entity{ &entity }
{}



/////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Add
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    ::xrn::ecs::detail::constraint::isEcsRegistered... Types
> void ::xrn::ecs::entity::Reference::add()
{
    m_entity->add<Types...>(*m_components);
}

///////////////////////////////////////////////////////////////////////////
template <
    ::xrn::ecs::detail::constraint::isComponent ComponentType
> void ::xrn::ecs::entity::Reference::addComponent(
    auto&&... args
)
{
    m_entity->addComponent<ComponentType>(*m_components, ::std::forward<decltype(args)>(args)...);
}

///////////////////////////////////////////////////////////////////////////
template <
    ::xrn::ecs::detail::constraint::isComponent... ComponentTypes
> void ::xrn::ecs::entity::Reference::addComponents()
{
    m_entity->addComponents<ComponentTypes...>(*m_components);
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::ecs::entity::Reference::addComponents(
    ::xrn::ecs::detail::constraint::isComponent auto&&... components
)
{
    m_entity->addComponents(*m_components, ::std::forward<decltype(components)>(components)...);
}

///////////////////////////////////////////////////////////////////////////
template <
    ::xrn::ecs::detail::constraint::isAbility AbilityType
> void ::xrn::ecs::entity::Reference::addAbility()
{
    m_entity->addAbility<AbilityType>();
}

///////////////////////////////////////////////////////////////////////////
template <
    ::xrn::ecs::detail::constraint::isAbility... AbilityTypes
> void ::xrn::ecs::entity::Reference::addAbilities()
{
    m_entity->addAbilities<AbilityTypes...>();
}




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Has
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    ::xrn::ecs::detail::constraint::isEcsRegistered... Types
> auto ::xrn::ecs::entity::Reference::has() const
    -> bool
{
    return m_entity->has<Types...>();
}

///////////////////////////////////////////////////////////////////////////
template <
    ::xrn::ecs::detail::constraint::isComponent ComponentType
> auto ::xrn::ecs::entity::Reference::hasComponent() const
    -> bool
{
    return m_entity->hasComponent<ComponentType>();
}

///////////////////////////////////////////////////////////////////////////
template <
    ::xrn::ecs::detail::constraint::isComponent... ComponentTypes
> auto ::xrn::ecs::entity::Reference::hasComponents() const
    -> bool
{
    return m_entity->hasComponents<ComponentTypes...>();
}

///////////////////////////////////////////////////////////////////////////
template <
    ::xrn::ecs::detail::constraint::isAbility AbilityType
> auto ::xrn::ecs::entity::Reference::hasAbility() const
    -> bool
{
    return m_entity->hasAbility<AbilityType>();
}

///////////////////////////////////////////////////////////////////////////
template <
    ::xrn::ecs::detail::constraint::isAbility... AbilityTypes
> auto ::xrn::ecs::entity::Reference::hasAbilities() const
    -> bool
{
    return m_entity->hasAbilities<AbilityTypes...>();
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Remove
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    ::xrn::ecs::detail::constraint::isEcsRegistered... Types
> void ::xrn::ecs::entity::Reference::remove()
{
    m_entity->remove<Types...>(*m_components);
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::ecs::entity::Reference::removeAbilitiesAndComponents()
{
    m_entity->removeAbilitiesAndComponents(*m_components);
}

///////////////////////////////////////////////////////////////////////////
template <
    ::xrn::ecs::detail::constraint::isComponent ComponentType
> void ::xrn::ecs::entity::Reference::removeComponent()
{
    m_entity->removeComponent<ComponentType>(*m_components);
}

///////////////////////////////////////////////////////////////////////////
template <
    ::xrn::ecs::detail::constraint::isComponent... ComponentTypes
> void ::xrn::ecs::entity::Reference::removeComponents()
{
    m_entity->removeComponents<ComponentTypes...>(*m_components);
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::ecs::entity::Reference::removeComponents()
{
    m_entity->removeComponents(*m_components);
}

///////////////////////////////////////////////////////////////////////////
template <
    ::xrn::ecs::detail::constraint::isAbility AbilityType
> void ::xrn::ecs::entity::Reference::removeAbility()
{
    m_entity->removeAbility<AbilityType>(*m_components);
}

///////////////////////////////////////////////////////////////////////////
template <
    ::xrn::ecs::detail::constraint::isAbility... AbilityTypes
> void ::xrn::ecs::entity::Reference::removeAbilities()
{
    m_entity->removeAbilities<AbilityTypes...>(*m_components);
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::ecs::entity::Reference::removeAbilities()
{
    m_entity->removeAbilities();
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Getters
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
[[ nodiscard ]] auto ::xrn::ecs::entity::Reference::isValid() const
    -> bool
{
    return m_entity != nullptr;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::ecs::entity::Reference::getSignature() const
    -> const ::xrn::ecs::Signature&
{
    return m_entity->getSignature();
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::ecs::entity::Reference::getId() const
    -> ::xrn::Id
{
    return m_entity->getId();
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::ecs::entity::Reference::get()
    -> ::xrn::ecs::entity::Entity&
{
    return *m_entity;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::ecs::entity::Reference::get() const
    -> const ::xrn::ecs::entity::Entity&
{
    return *m_entity;
}

///////////////////////////////////////////////////////////////////////////
::xrn::ecs::entity::Reference::operator const ::xrn::ecs::entity::Entity&() const
{
    return *m_entity;
}

///////////////////////////////////////////////////////////////////////////
::xrn::ecs::entity::Reference::operator ::xrn::ecs::entity::ConstReference() const
{
    return ::xrn::ecs::entity::ConstReference{ *m_entity };
}
