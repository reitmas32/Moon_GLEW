#pragma once
#include <GLFW/glfw3.h>
#include <entidad.hpp>
#include <cmp.hpp>
#include <Moon/template/core/sys/sys.tpp>
#include <Moon/template/core/cmp/cmp_storage.tpp>
#include <gtx.hpp>
#include <keyboard.hpp>
inline Moon::GLFW::KeyBoardCmp_t keyBoardCmp = Moon::GLFW::KeyBoardCmp_t();

struct InputSystem_t : Moon::Core::SystemVoid_t<InputSystem_t>
{
    bool alive_flag = true;

    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        keyBoardCmp.keyboard[key] = action;
    }

    void update() override;
    bool alive() override;
};

struct PhysicsSys_t : Moon::Core::System_t<Gtx_t>
{
    inline static Moon::Tools::TimeStep_t time = Moon::Tools::TimeStep_t();
    void update(Gtx_t *gtx) override;

    bool alive() override;
};

struct RenderSys_t : Moon::Core::System_t<Gtx_t>
{
    void update(Gtx_t *gtx) override;

    bool alive() override;
};