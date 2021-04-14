#pragma once

#include <Moon/template/core/ent/ent.tpp>
#include <Moon/template/core/ent/ent_base.tpp>
//#include <Moon/template/core/ent/ent_storage.tpp>

struct Triangle_t : Moon::Core::Entity_t<Triangle_t>
{
    Triangle_t(){}
    Triangle_t(Moon::Alias::EntityId eid) : Moon::Core::Entity_t<Triangle_t>(eid) {}
    ~Triangle_t(){}
    void unaFuncion();
};