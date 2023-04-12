#pragma once

#include "glm/fwd.hpp"
#include "p6/p6.h"

class Boid
{
    private :
        glm::vec2 position;
        float maxSpeed;
        float speed;
        glm::vec2 direction;

    private : 
        void applyForce(const glm::vec2 direction, const float strength);

        float distance(const Boid boid) const;

        void slowing(const float amount);

    public :

        Boid(const glm::vec2 p, const float mS, const glm::vec2 d);

        void acceleration(const float a);

        void displacement();

        void neighborsAlignement(const Boid boid, const float distance, const float strength);

        void neighborsCohesion(const Boid boid, const float distance, const float strength);

        void neighborsSeparation(const Boid boid, const float distance, const float strength);

        void bordersAvoidance(const p6::Context& ctx, const float distance, const float strength);

        void draw(p6::Context& ctx, const float size) const;
};