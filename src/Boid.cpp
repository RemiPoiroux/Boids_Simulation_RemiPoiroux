#include "glm/fwd.hpp"
#include "p6/p6.h"

#include "Boid.hpp"

void normaliseVector(glm::vec2 &v)
{
    float norm = sqrt(v.x*v.x+v.y*v.y);
    v.x=v.x/norm;
    v.y=v.y/norm;
}

void Boid::applyForce(const glm::vec2 direction, const float strength)
{
    this->direction+=direction*strength;
    normaliseVector(this->direction);
}

float Boid::distance(const Boid boid) const
{
    return sqrt(pow(this->position.x-boid.position.x, 2)+pow(this->position.y-boid.position.y, 2));
}

void Boid::slowing(const float amount)
{
    this->speed-=this->speed*amount;
}

Boid::Boid(const glm::vec2 p, const float mS, const glm::vec2 d): position(p), maxSpeed(mS), speed(), direction(d) {}

void Boid::acceleration(float a)
{
    if(this->speed<this->maxSpeed)
    {
        this->speed+=a*this->maxSpeed;
    }
}
void Boid::displacement()
{
    this->position+=this->direction*this->speed;
}

void Boid::neighborsAlignement(const Boid boid, const float distance, const float strength)
{
    if(this->distance(boid)<distance)
    {
        this->applyForce(boid.direction-this->direction,strength);
    }
}
void Boid::neighborsCohesion(const Boid boid, const float distance, const float strength)
{
    if(this->distance(boid)<distance)
    {
        this->applyForce(boid.position-this->position,strength);
    }
}
void Boid::neighborsSeparation(const Boid boid, const float distance, const float strength)
{
    if(this->distance(boid)<distance)
    {
        this->applyForce(boid.direction-this->direction,-strength);
        this->applyForce(boid.position-this->position,-strength/10);
    }
}

void Boid::bordersAvoidance(const p6::Context& ctx, const float distance, float strength)
{
    if((this->position.x>ctx.aspect_ratio()*(1-distance)) 
    && this->direction.x>0)
    {
        if(this->position.x>ctx.aspect_ratio())
        {
            glm::vec2 direction(-1,-this->direction.y);
            this->applyForce(direction, 2);
        }
        else
        {
            glm::vec2 direction(-1,this->direction.y);
            strength=(distance+this->position.x/ctx.aspect_ratio()-1)*strength;
            this->applyForce(direction,strength);
            this->slowing(strength);
        }
    }
    else if((this->position.x<-ctx.aspect_ratio()*(1-distance))
    && this->direction.x<0)
    {
        if(this->position.x<-ctx.aspect_ratio())
        {
            glm::vec2 direction(1,-this->direction.y);
            this->applyForce(direction, 2);
        }
        else
        {
            glm::vec2 direction(1,this->direction.y);
            strength=(distance-this->position.x/ctx.aspect_ratio()-1)*strength;
            this->applyForce(direction,strength);
            this->slowing(strength/2);
        }
    }

    if((this->position.y>(1-distance)) 
    && this->direction.y>0)
    {
        if(this->position.y>1)
        {
            glm::vec2 direction(-this->direction.x, -1);
            this->applyForce(direction, 2);
        }
        else
        {
            glm::vec2 direction(this->direction.x,-1);
            strength=(distance+this->position.y-1)*strength;
            this->applyForce(direction,strength);
            this->slowing(strength);
        }
    }
    else if((this->position.y<-(1-distance))
    && this->direction.y<0)
    {
        if(this->position.y<-1)
        {
            glm::vec2 direction(-this->direction.x, 1);
            this->applyForce(direction, 2);
        }
        else
        {
            glm::vec2 direction(this->direction.x,1);
            strength=(distance-this->position.y-1)*strength;
            this->applyForce(direction,strength);
            this->slowing(strength);
        }
    }
}

void Boid::draw(p6::Context& ctx, const float size) const
{
    ctx.fill={-this->direction.y-this->direction.x,this->direction.y,this->direction.x,1};
    ctx.circle(p6::Center{this->position},p6::Radius{size/2});
}