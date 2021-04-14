#include <cmp.hpp>

////////////////////////////////////////////////
////////////////////////////////////////////////

TimeCmp_t::TimeCmp_t() {}

TimeCmp_t::~TimeCmp_t() {}

////////////////////////////////////////////////
////////////////////////////////////////////////

SpriteTriangle_t::SpriteTriangle_t(Moon::Alias::EntityId eid, float size)
    : Moon::Core::Component_t<SpriteTriangle_t>(eid), size{size}
{
    //TODO
}
SpriteTriangle_t::~SpriteTriangle_t() {}

////////////////////////////////////////////////
////////////////////////////////////////////////

IACmp_t::IACmp_t(Moon::Alias::EntityId eid)
    : Moon::Core::Component_t<IACmp_t>(eid)
{
    //TODO
}

IACmp_t::~IACmp_t() {}

////////////////////////////////////////////////
////////////////////////////////////////////////

RotateCmp_t::RotateCmp_t(Moon::Alias::EntityId eid)
    : Moon::Core::Component_t<RotateCmp_t>(eid)
{
    //TODO
}

RotateCmp_t::~RotateCmp_t() {}

////////////////////////////////////////////////
////////////////////////////////////////////////

Position2Df_t::Position2Df_t() {}
Position2Df_t::Position2Df_t(Moon::Alias::EntityId eid, float x, float y) : Moon::Core::Component_t<Position2Df_t>(eid), x{x}, y{y}
{
}
Position2Df_t::~Position2Df_t() {}

////////////////////////////////////////////////
////////////////////////////////////////////////

PhysicsCmp_t::PhysicsCmp_t() {}
PhysicsCmp_t::PhysicsCmp_t(Moon::Alias::EntityId eid, bool colider) : Moon::Core::Component_t<PhysicsCmp_t>(eid), colider{colider}
{
}
PhysicsCmp_t::~PhysicsCmp_t() {}