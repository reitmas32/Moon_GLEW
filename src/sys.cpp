#include <sys.hpp>

void InputSystem_t::update()
{
    if (keyBoardCmp.keyboard[Moon::GLFW::MOON_KEY_ESCAPE])
        this->alive_flag = false;
    if(keyBoardCmp.keyboard[Moon::GLFW::MOON_KEY_W] == 2){
        this->alive_flag = false;
    }
}
bool InputSystem_t::alive() { return this->alive_flag; }

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void PhysicsSys_t::update(Gtx_t *gtx)
{
    for (Position2Df_t &cmp : gtx->getComponents<Position2Df_t>())
    {
        if (gtx->getEntityById<Triangle_t>(cmp.eid)->getComponent<PhysicsCmp_t>())
        {

            if (keyBoardCmp.keyboard[Moon::GLFW::MOON_KEY_UP] != 0)
                cmp.y += 1.0f / gtx->timeCmp.sim_fps;
            if (keyBoardCmp.keyboard[Moon::GLFW::MOON_KEY_DOWN] != 0)
                cmp.y -= 1.0f / gtx->timeCmp.sim_fps;
            if (keyBoardCmp.keyboard[Moon::GLFW::MOON_KEY_RIGHT] != 0)
                cmp.x += 1.0f / gtx->timeCmp.sim_fps;
            if (keyBoardCmp.keyboard[Moon::GLFW::MOON_KEY_LEFT] != 0)
                cmp.x -= 1.0f / gtx->timeCmp.sim_fps;
        }
        if (gtx->getEntityById<Triangle_t>(cmp.eid)->getComponent<IACmp_t>())
        {
            cmp.x -= 1.0f / gtx->timeCmp.sim_fps * 0.1;
        }
        auto *rot{gtx->getEntityById<Triangle_t>(cmp.eid)->getComponent<RotateCmp_t>()};
        if (rot)
        {
            rot->angle += 10.0f;
            if (rot->angle > 360.0f)
                rot->angle = 0.0f;
        }
    }

    if (keyBoardCmp.keyboard[Moon::GLFW::MOON_KEY_A] != 0)
        gtx->timeCmp.fps++;
    if (keyBoardCmp.keyboard[Moon::GLFW::MOON_KEY_S] != 0)
        gtx->timeCmp.fps--;
    if (keyBoardCmp.keyboard[Moon::GLFW::MOON_KEY_O] != 0)
        gtx->timeCmp.sim_fps++;
    if (keyBoardCmp.keyboard[Moon::GLFW::MOON_KEY_P] != 0)
        gtx->timeCmp.sim_fps--;

    if ( PhysicsSys_t::time.ellapsed() > 6000000000)
    {

        auto &t_1 = gtx->addEntity<Triangle_t>();
        gtx->addComponentById<Triangle_t, SpriteTriangle_t>(t_1.eid, 0.25f);
        gtx->addComponentById<Triangle_t, Position2Df_t>(t_1.eid, 1.2f, -0.9f);
        gtx->addComponentById<Triangle_t, IACmp_t>(t_1.eid);
        PhysicsSys_t::time.start();
    }
    if (keyBoardCmp.keyboard[Moon::GLFW::MOON_KEY_M] == 1)
    {

        Moon::Tools::Logs::error("This a Error");
    }
}

bool PhysicsSys_t::alive() { return true; }

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void RenderSys_t::update(Gtx_t *gtx)
{
    for (Position2Df_t &cmp : gtx->getComponents<Position2Df_t>())
    {
        const auto *sprite{gtx->getEntityById<Triangle_t>(cmp.eid)->getComponent<SpriteTriangle_t>()};
        if (sprite)
        {
            glLoadIdentity();
            glPushMatrix();
            auto *rot{gtx->getEntityById<Triangle_t>(cmp.eid)->getComponent<RotateCmp_t>()};
            if (rot)
            {
                glTranslatef(cmp.x, cmp.y, 0.0f);
                glRotatef(rot->angle, 0.0f, 0.0f, 1.0f);
                glTranslatef(-cmp.x, -cmp.y, 0.0f);
            }
            glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(0.0f + cmp.x, sprite->size + cmp.y, 0.1f);
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(sprite->size + cmp.x, -sprite->size + cmp.y, 0.1f);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex3f(-sprite->size + cmp.x, -sprite->size + cmp.y, 0.1f);
            glEnd();
            glPopMatrix();
        }
    }
}

bool RenderSys_t::alive() { return true; }