/*
cmake .. -G "Unix Makefiles" -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS_RELEASE=-O3 -DCMAKE_CXX_FLAGS_DEBUG=-g -DCMAKE_C_FLAGS_RELEASE=-O3 -DLOGS=OFF
cmake .. -G "Unix Makefiles" -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS_RELEASE=-O3 -DCMAKE_CXX_FLAGS_DEBUG=-g -DCMAKE_C_FLAGS_RELEASE=-O3 -DLOGS=ON
*/
#include <iostream>
#include <keyboard.hpp>

#include <moon.hpp>
#include <typeinfo>
#include <include/cmp.hpp>
#include <entidad.hpp>
#include <Moon/template/core/ent/ent_base.tpp>
#include <include/gtx.hpp>
#include <include/sys.hpp>

#ifndef RELEASE
#include <include/termcolor.hpp>
#endif

template <typename... Args>
void contructor(std::string_view name, void *location, Args &&...args)
{
#ifndef RELEASE
    std::cout << "Contructor of " << termcolor::green
              << name << termcolor::reset
              << " in " << termcolor::red << location << termcolor::reset;
    ((std::cout << std::forward<Args>(args)), ...);
    std::cout << std::endl;
#endif
}

int main(void)
{
#if true
    GLFWwindow *window;
    auto physicsSys = PhysicsSys_t();
    auto renderSys = RenderSys_t();
    auto inputSys = InputSystem_t();
    ///InputSystem_t::time.start();
    auto gtx = Gtx_t();

    auto t = gtx.addEntity<Triangle_t>();
    gtx.addComponentById<Triangle_t, SpriteTriangle_t>(t.eid, 0.2f);
    gtx.addComponentById<Triangle_t, Position2Df_t>(t.eid, 0.0f, 0.0f);
    gtx.addComponentById<Triangle_t, PhysicsCmp_t>(t.eid, true);
    auto t_1 = gtx.addEntity<Triangle_t>();
    gtx.addComponentById<Triangle_t, SpriteTriangle_t>(t_1.eid, 0.15f);
    gtx.addComponentById<Triangle_t, Position2Df_t>(t_1.eid, 0.9f, -0.9f);
    gtx.addComponentById<Triangle_t, IACmp_t>(t_1.eid);
    auto t_2 = gtx.addEntity<Triangle_t>();
    gtx.addComponentById<Triangle_t, SpriteTriangle_t>(t_2.eid, 0.1f);
    gtx.addComponentById<Triangle_t, Position2Df_t>(t_2.eid, -0.5f, -0.5f);
    gtx.addComponentById<Triangle_t, RotateCmp_t>(t_2.eid);
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetKeyCallback(window, inputSys.key_callback);
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    Moon::Tools::TimeStep_t time;
    uint64_t nanos;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window) && inputSys.alive())
    {
        nanos = 1000000000 / gtx.timeCmp.fps;
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        if (time.ellapsed() > nanos)
        {
            physicsSys.update(&gtx);
            time.start();
        }

        renderSys.update(&gtx);

        inputSys.update();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
#endif
    //auto c = SpriteTriangle_t(5, 1.0f);
    return 0;
}