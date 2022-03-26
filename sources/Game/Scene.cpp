///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>
#include <xrn/Ecs.hpp>
#include <Game/Scene.hpp>
#include <Game/Window.hpp>
#include <Game/Systems.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// *structors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::xrn::Scene::Scene(
    ::xrn::Window& window
)
    : m_window{ window }
{
    m_entities.emplace(::xrn::component::Drawable{ "testWallpaper.png", m_window });

    // ground
    {
        ::xrn::component::Drawable drawable{ "ground.png", m_window };
        drawable.setScale(10, 1);

        ::xrn::component::Movable movable;
        movable.setPosition(0, m_window.getSize().y / 1.15);
        drawable.updatePosition(movable);

#ifdef DEBUG_HITBOX
        ::xrn::component::Hitbox hitbox{ 0, 0, 1920, 200, window };
#else
        ::xrn::component::Hitbox hitbox{ 0, 0, 1920, 200 };
#endif
        hitbox.updatePosition(movable);

        m_entities.emplace(
            ::std::move(drawable),
            ::std::move(hitbox)
        );
    }


    // player created in last
    {
        ::xrn::component::Drawable drawable{ "cube.png", m_window };
        drawable.setScale(0.12);

        ::xrn::component::Movable movable;
        movable.setDirection({0.0f, 1.0f});
        movable.setPosition(m_window.getSize().x / 7, m_window.getSize().y / 1.4);

        m_playerId = m_entities.emplace(
            ::std::move(drawable),
            ::std::move(movable),
            ::xrn::component::Gravity{},
#ifdef DEBUG_HITBOX
            ::xrn::component::Hitbox{ 8, 8, 100, 100, m_window }
#else
            ::xrn::component::Hitbox{ 8, 8, 100, 100 }
#endif
        ).getId();
    }

    // score
    {
        ::xrn::component::Text text{ "Score: 0", ::sf::Color::Blue, m_window };

        ::xrn::component::Movable movable;
        movable.setDirection({0.0f, 1.0f});
        movable.setPosition(m_window.getSize().x / 50, m_window.getSize().y / 50);

        text.updatePosition(movable);

        m_scoreId = m_entities.emplace(::std::move(text)).getId();
    }

    // systems
    m_systems.emplace<::xrn::system::applyGravity>();

    // update systems
    m_updateSystems.emplace<::xrn::system::updatePosition>();
    m_updateSystems.emplace<::xrn::system::moveDrawable>();
    m_updateSystems.emplace<::xrn::system::moveHitbox>();

    // const systems
    m_constSystems.emplace<::xrn::system::draw>();
    m_constSystems.emplace<::xrn::system::drawText>();
#ifdef DEBUG_HITBOX
    m_constSystems.emplace<::xrn::system::drawHitbox>();
#endif
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Actions
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
auto ::xrn::Scene::update()
    -> bool
{
    this->spawnObstacles();
    m_systems.run(m_clock.restart(), m_entities);
    m_updateSystems.run(m_clockUpdate.restart(), m_entities);

    // hitbox
    for (auto& entity1 : m_entities) {
        auto entityId1 = entity1.getId();
        bool foundAGround{ false };
        auto* hitbox1{ m_components.get<::xrn::component::Hitbox>(entityId1) };
        auto* movable1{ m_components.get<::xrn::component::Movable>(entityId1) };
        if (!hitbox1 || !movable1) {
            continue;
        }
        for (auto& entity2 : m_entities) {
            auto entityId2 = entity2.getId();
            if (entityId1 == entityId2) {
                continue;
            } else if (auto* hitbox2{ m_components.get<::xrn::component::Hitbox>(entityId2) }; hitbox2) {
                if (hitbox1->contains(*hitbox2)) {
                    if (
                        entityId1 == m_playerId &&
                        m_entities.get(entityId2).hasAbility<xrn::ability::Enemy>()
                    ) {
                        return false;
                    }
                    movable1->setDirection({ movable1->getDirection().x, 0.0f });
                    movable1->setSpeed({ movable1->getSpeed().x, 0.0f });
                    movable1->setPosition({
                        movable1->getPosition().x, hitbox2->getPosition().y - hitbox1->getSize().y + 1
                    });
                    foundAGround = true;
                    break;
                }
            }
        }
        movable1->setGrounded(foundAGround);
        if (foundAGround) {
            m_updateSystems.run(m_clockUpdate.restart(), m_entities);
        } else {
            movable1->setDirection({ movable1->getDirection().x, 1.0f });
        }
    }

    // delete enemies
    for (auto& entity : m_entities) {
        if (auto* movable{ m_components.get<::xrn::component::Movable>(entity.getId()) }; movable) {
            if (movable->getPosition().x <= -100) {
                break;
            }
        }
    }

    // score
    if (m_scoreClock.getElapsed() >= 50) {
        m_scoreClock.reset();
        m_components.get<::xrn::component::Text>(m_scoreId)->set("score: "s + ::std::to_string(++m_score));
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::Scene::spawnObstacles()
{
    if (m_obstacleClock.getElapsed() >= m_obstacleRate) {
        m_obstacleClock.reset();
        switch (std::rand() % 2) {
        case 0: { // player created in last
            ::xrn::component::Drawable drawable{ "cube.png", m_window };
            drawable.setScale(0.05, 0.2);

            ::xrn::component::Movable movable;
            movable.setDirection({1.0f, 1.0f});
            movable.setSpeed({ -static_cast<float>(m_enemySpeed), movable.getSpeed().x });
            movable.setPosition(m_window.getSize().x * 1, m_window.getSize().y / 1.4);

            auto id{ m_entities.emplace(
                ::std::move(drawable),
                ::std::move(movable),
                ::xrn::component::Gravity{},
#ifdef DEBUG_HITBOX
                ::xrn::component::Hitbox{ 5, 5, 50, 170, m_window }
#else
                ::xrn::component::Hitbox{ 8, 8, 50, 100 }
#endif
            ).getId() };
            m_entities.get(id).addAbility<xrn::ability::Enemy>();
            break;
        } case 1: {
            ::xrn::component::Drawable drawable{ "cube.png", m_window };
            drawable.setScale(0.05, 0.2);

            ::xrn::component::Movable movable;
            movable.setDirection({1.0f, 1.0f});
            movable.setSpeed({ -static_cast<float>(m_enemySpeed), movable.getSpeed().x });
            movable.setPosition(m_window.getSize().x * 1, m_window.getSize().y / 1.8);

            auto id{ m_entities.emplace(
                ::std::move(drawable),
                ::std::move(movable),
#ifdef DEBUG_HITBOX
                ::xrn::component::Hitbox{ 5, 5, 50, 170, m_window }
#else
                ::xrn::component::Hitbox{ 8, 8, 50, 100 }
#endif
            ).getId() };
            m_entities.get(id).addAbility<xrn::ability::Enemy>();
            break;
        } default: {
            break;
        }
        }
        m_enemySpeed += 50;
    }
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::Scene::draw() const
{
    m_window.clear();
    m_constSystems.run(m_constClock.restart(), m_entities);
    m_window.display();
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::Scene::isOver() const
    -> bool
{
    return m_isOver;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::Scene::handleEvent(
    sf::Event& event
) -> bool
{
    switch (event.type) {
    case ::sf::Event::Closed: m_isOver = true; return false;
    case ::sf::Event::KeyPressed:
        switch (event.key.code) {
        case sf::Keyboard::Key::Space:
            m_components.get<::xrn::component::Movable>(m_playerId)->jump();
            return true;
        case sf::Keyboard::Key::Escape: return false;
        default: return true;
        }
    default: return true;
    }
}

///////////////////////////////////////////////////////////////////////////
[[ nodiscard ]] auto ::xrn::Scene::getScore() const
    -> ::std::size_t
{
    return m_score;
}
