#include <cstddef>
#include <cstdlib>
#include "p6/p6.h"
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"


/////////////////////////////////
    // PARAMETERS

const int NB_BOIDS=100;
const float BOIDS_LENGHT=0.02;

const float ACCELERATION=0.01;
const float MAX_SPEED_MIN=0.0005;
const float MAX_SPEED_MAX=0.001;

const float RALENTIR_LUGAR=0.2;

const float NEIGHBOR_INFLUENCE=0.5;


/////////////////////////////////

class Boid
{
    public :
    glm::vec2 position;
    float maxSpeed;
    glm::vec2 speed;
    glm::vec2 direction;

    Boid(glm::vec2 p, float mS, glm::vec2 d): position(p), maxSpeed(mS), speed(), direction(d) {};
};

float RandomFloat(float a, float b) 
{
    float random = ((float)rand()) / (float)RAND_MAX;
    float diff   = b - a;
    float r      = random * diff;
    return a + r;
}

std::vector<Boid> createBoids(const p6::Context& ctx, const size_t nb)
{
    std::vector<Boid> boids;
    for(size_t i=0; i<nb; ++i)
    {
        glm::vec2 position=p6::random::point(ctx);
        float maxSpeed = RandomFloat(MAX_SPEED_MIN, MAX_SPEED_MAX);
        glm::vec2 direction = p6::random::direction();

        Boid boid=Boid(position, maxSpeed, direction);
        boids.push_back(boid);
    }
    return boids;
}

void neighborsManager(std::vector<Boid>& boids)
{
    for(size_t i=0; i<boids.size(); ++i)
    {
        size_t neighborIndex=i;
        float neighborDistance=1000000; 

        for(size_t j=0; j<boids.size(); ++j)
        {
            if(j!=i)
            {
                float distance=sqrt(pow(boids[i].position.x-boids[j].position.x, 2)+pow(boids[i].position.y-boids[j].position.y, 2));

                if(distance<neighborDistance)
                {
                    neighborIndex=j;
                    neighborDistance=distance;
                }
            }
        }
        boids[i].direction+=(boids[neighborIndex].direction-boids[i].direction)*NEIGHBOR_INFLUENCE;
    }
}

void turnManager(const p6::Context& ctx ,std::vector<Boid>& boids)
{
    for(Boid & boid : boids)
    {

        if((boid.position.x>ctx.aspect_ratio()*(1-RALENTIR_LUGAR)))
        {
            boid.speed.x=boid.maxSpeed*pow(((1-(boid.position.x-(1-RALENTIR_LUGAR)*ctx.aspect_ratio()))), 6);
        }
        else if((boid.position.x<-ctx.aspect_ratio()*(1-RALENTIR_LUGAR)))
        {
            boid.speed.x=boid.maxSpeed*pow(((1-(-boid.position.x-(1-RALENTIR_LUGAR)*ctx.aspect_ratio()))), 6);
        }

        if((boid.position.y>(1-RALENTIR_LUGAR)))
        {
            boid.speed.y=boid.maxSpeed*pow(((1-(boid.position.y-(1-RALENTIR_LUGAR)))), 6);
        }
        else if((boid.position.y<-(1-RALENTIR_LUGAR)))
        {
            boid.speed.y=boid.maxSpeed*pow(((1-(-boid.position.y-(1-RALENTIR_LUGAR)))), 6);
        }
    }
}

void borderManager(const p6::Context& ctx ,std::vector<Boid>& boids)
{
    for(Boid & boid : boids)
    {
        if(boid.position.x+boid.direction.x*boid.speed.x>ctx.aspect_ratio() 
        || boid.position.x+boid.direction.x*boid.speed.x<-ctx.aspect_ratio())
        {
            boid.direction.x=-boid.direction.x;
        }
        if(boid.position.y+boid.direction.y*boid.speed.y>1 
        || boid.position.y+boid.direction.y*boid.speed.y<-1)
        {
            boid.direction.y=-boid.direction.y;
        }
    }
}

void boidsDisplacement(std::vector<Boid>& boids)
{
    for(Boid & boid : boids)
    {
        if(boid.speed.x<boid.maxSpeed)
        {
            boid.speed.x+=ACCELERATION*boid.maxSpeed;
        }
        if(boid.speed.y<boid.maxSpeed)
        {
            boid.speed.y+=ACCELERATION*boid.maxSpeed;
        }

        boid.position.x+=boid.direction.x*boid.speed.x;
        boid.position.y+=boid.direction.y*boid.speed.y;
    }
}

void drawBoids(p6::Context& ctx, const std::vector<Boid>& boids)
{
    for(Boid boid : boids)
    {
        ctx.circle(p6::Center{boid.position},p6::Radius{BOIDS_LENGHT});
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

    std::vector<Boid> boids=createBoids(ctx,NB_BOIDS);

    // Declare your infinite update loop.
    ctx.update = [&]() {

        ctx.background(p6::NamedColor::Cyan);

        neighborsManager(boids);

        turnManager(ctx, boids);
        borderManager(ctx, boids);

        boidsDisplacement(boids);

        drawBoids(ctx, boids);
    };

    // Should be done last. It starts the infinite loop.
    ctx.start();
}