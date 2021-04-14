#pragma once

#include <Moon/template/core/gtx/gtx.tpp>

#include <cmp.hpp>
#include <entidad.hpp>
//#include <include/keyboard.hpp>

struct Gtx_t : Moon::Core::GameContext_t<Gtx_t>
{
    //Moon::GLFW::KeyBoardCmp_t keyBoardCmp;
    TimeCmp_t timeCmp;
    Gtx_t();
    ~Gtx_t();
};