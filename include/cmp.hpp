#pragma once

#include <Moon/include/tools/time_step.hpp>
#include <Moon/include/core/cmp/cmp.hpp>
#include <Moon/include/core/cmp/cmp_storage.hpp>

struct TimeCmp_t : Moon::Core::ComponentSingleton_t<TimeCmp_t>
{
    uint64_t fps{60}, sim_fps{60};

    TimeCmp_t(Moon::Alias::EntityId eid) = delete;

    TimeCmp_t();

    ~TimeCmp_t();
};

struct SpriteTriangle_t : Moon::Core::Component_t<SpriteTriangle_t>
{
    float size;
    SpriteTriangle_t(Moon::Alias::EntityId eid, float size);
    ~SpriteTriangle_t();
};

struct IACmp_t : Moon::Core::Component_t<IACmp_t>
{
    IACmp_t(Moon::Alias::EntityId eid);

    ~IACmp_t();
};

struct RotateCmp_t : Moon::Core::Component_t<RotateCmp_t>
{
    float angle{0.1f};
    RotateCmp_t(Moon::Alias::EntityId eid);

    ~RotateCmp_t();
};

struct Position2Df_t : Moon::Core::Component_t<Position2Df_t>
{
    float x{0.0f}, y{0.0f};
    Position2Df_t();
    Position2Df_t(Moon::Alias::EntityId eid, float x, float y);
    ~Position2Df_t();
};

struct PhysicsCmp_t : Moon::Core::Component_t<PhysicsCmp_t>
{
    bool colider = false;
    PhysicsCmp_t();
    PhysicsCmp_t(Moon::Alias::EntityId eid, bool colider);
    ~PhysicsCmp_t();
};