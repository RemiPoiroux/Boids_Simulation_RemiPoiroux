#include <cstddef>
#include <cstdlib>
#include "glm/fwd.hpp"
#include "glm/gtx/norm.hpp"
#include "p6/p6.h"
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"


/////////////////////////////////
    // PARAMETERS

const int NB_BOIDS=200;
const float BOIDS_LENGHT=0.02;
const float TAIL_SIZE=20;

const float ACCELERATION=0.01;
const float MAX_SPEED_MIN=0.003;
const float MAX_SPEED_MAX=0.004;

const float RALENTIR_LUGAR=0.2;
const float BORDER_STRENGTH=0.5;

const float NEIGHBOR_ALIGNMENT_DISTANCE=0.4;
const float NEIGHBOR_ALIGNMENT_STRENGTH=0.005;

const float NEIGHBOR_COHESION_DISTANCE=0.3;
const float NEIGHBOR_COHESION_STRENGTH=0.002;

const float NEIGHBOR_SEPARATION_DISTANCE=0.1;
const float NEIGHBOR_SEPARATION_STRENGTH=0.05;


/////////////////////////////////

float RandomFloat(const float a, const float b) 
{
    float random = ((float)rand()) / (float)RAND_MAX;
    float diff   = b - a;
    float r      = random * diff;
    return a + r;
}

void normaliseVector(glm::vec2 &v)
{
    float norm = sqrt(v.x*v.x+v.y*v.y);
    v.x=v.x/norm;
    v.y=v.y/norm;
}

class Boid
{
    private :
        glm::vec2 position;
        float maxSpeed;
        float speed;
        glm::vec2 direction;

    private : 
        void applyForce(const glm::vec2 direction, const float strength)
        {
            this->direction+=direction*strength;
            normaliseVector(this->direction);
        }

        float distance(const Boid boid) const
        {
            return sqrt(pow(this->position.x-boid.position.x, 2)+pow(this->position.y-boid.position.y, 2));
        }

        void slowing(const float amount)
        {
            this->speed-=this->speed*amount;
        }

    public :

        Boid(const glm::vec2 p, const float mS, const glm::vec2 d): position(p), maxSpeed(mS), speed(), direction(d) {};

        void acceleration()
        {
            if(this->speed<this->maxSpeed)
            {
                this->speed+=ACCELERATION*this->maxSpeed;
            }
        }
        void displacement()
        {
            this->position+=this->direction*this->speed;
        }

        void neighborsAlignement(const Boid boid)
        {
            if(this->distance(boid)<NEIGHBOR_ALIGNMENT_DISTANCE)
            {
                this->applyForce(boid.direction-this->direction,NEIGHBOR_ALIGNMENT_STRENGTH);
            }
        }
        void neighborsCohesion(const Boid boid)
        {
            if(this->distance(boid)<NEIGHBOR_COHESION_DISTANCE)
            {
                this->applyForce(boid.position-this->position,NEIGHBOR_COHESION_STRENGTH);
            }
        }
        void neighborsSeparation(const Boid boid)
        {
            if(this->distance(boid)<NEIGHBOR_SEPARATION_DISTANCE)
            {
                this->direction-=((boid.direction-this->direction))*NEIGHBOR_SEPARATION_STRENGTH;
            }
        }

        void bordersAvoidance(const p6::Context& ctx)
        {
            if((this->position.x>ctx.aspect_ratio()*(1-RALENTIR_LUGAR)) 
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
                    float strength=(RALENTIR_LUGAR+this->position.x/ctx.aspect_ratio()-1)*BORDER_STRENGTH;
                    this->applyForce(direction,strength);
                    this->slowing(strength);
                }
            }
            else if((this->position.x<-ctx.aspect_ratio()*(1-RALENTIR_LUGAR))
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
                    float strength=(RALENTIR_LUGAR-this->position.x/ctx.aspect_ratio()-1)*BORDER_STRENGTH;
                    this->applyForce(direction,strength);
                    this->slowing(strength);
                }
            }

            if((this->position.y>(1-RALENTIR_LUGAR)) 
            && this->direction.y>0)
            {
                if(this->position.y>1)
                {
                    glm::vec2 direction(-this->direction.y, -1);
                    this->applyForce(direction, 2);
                }
                else
                {
                    glm::vec2 direction(this->direction.x,-1);
                    float strength=(RALENTIR_LUGAR+this->position.y-1)*BORDER_STRENGTH;
                    this->applyForce(direction,strength);
                    this->slowing(strength);
                }
            }
            else if((this->position.y<-(1-RALENTIR_LUGAR))
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
                    float strength=(RALENTIR_LUGAR-this->position.y-1)*BORDER_STRENGTH;
                    this->applyForce(direction,strength);
                    this->slowing(strength);
                }
            }
        }

        void draw(p6::Context& ctx)
        {
            ctx.fill={-this->direction.y-this->direction.x,this->direction.y,this->direction.x,1};
            ctx.circle(p6::Center{this->position},p6::Radius{BOIDS_LENGHT});
        }
};

Boid randomBoid(const p6::Context& ctx)
{
    glm::vec2 position=p6::random::point(ctx);
    float maxSpeed = RandomFloat(MAX_SPEED_MIN, MAX_SPEED_MAX);
    glm::vec2 direction = p6::random::direction();

    return Boid(position, maxSpeed, direction);
}

std::vector<Boid> createBoids(const p6::Context& ctx, const size_t nb)
{
    std::vector<Boid> boids;
    for(size_t i=0; i<nb; ++i)
    {
        boids.push_back(randomBoid(ctx));
    }
    return boids;
}

void neighborsManager(std::vector<Boid>& boids)
{
    for(size_t i=0; i<boids.size(); ++i)
    {
        for(size_t j=0; j<boids.size(); ++j)
        {
            if(j!=i)
            {
                boids[i].neighborsAlignement(boids[j]);
                boids[i].neighborsCohesion(boids[j]);
                boids[i].neighborsSeparation(boids[j]);
            }
        }    
    }
}

void borderManager(const p6::Context& ctx ,std::vector<Boid>& boids)
{
    for(Boid & boid : boids)
    {
        boid.bordersAvoidance(ctx);
    }
}

void boidsDisplacement(std::vector<Boid>& boids)
{
    for(Boid & boid : boids)
    {   
        boid.acceleration();
        boid.displacement();
    }
}

void drawBoids(p6::Context& ctx, const std::vector<Boid>& boids)
{
    for(Boid boid : boids)
    {
        boid.draw(ctx);
    }
}

int main(int argc, char* argv[])
{
    { // Run the tests
        if (doctest::Context{}.run() != 0)
            return EXIT_FAILURE;
        // The CI does not have a GPU so it cannot run the rest of the code.
        const bool no_gpu_available = argc >= 2 && strcmp(argv[1], "-nogpu") == 0; // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
        if (no_gpu_available)
            return EXIT_SUCCESS;
    }

    // Actual app
    auto ctx = p6::Context{{.title = "Rem's boids"}};
    ctx.maximize_window();
    ctx.stroke_weight=0;

    std::vector<Boid> boids=createBoids(ctx,NB_BOIDS);

    // Declare your infinite update loop.
    ctx.update = [&]() {

        ctx.fill={0,0,0,1/TAIL_SIZE};
        ctx.rectangle(p6::FullScreen{});

        neighborsManager(boids);

        borderManager(ctx, boids);

        boidsDisplacement(boids);

        drawBoids(ctx, boids);
    };

    // Should be done last. It starts the infinite loop.
    ctx.start();
}