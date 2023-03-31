// #include <cstddef>
// #include <cstdlib>
// #include "p6/p6.h"
// #define DOCTEST_CONFIG_IMPLEMENT
// #include "doctest/doctest.h"


// /////////////////////////////////
//     // PARAMETERS

// const int NB_BOIDS=200;
// const float BOIDS_LENGHT=0.02;
// const float TAIL_SIZE=20;

// const float ACCELERATION=0.01;
// const float MAX_SPEED_MIN=0.003;
// const float MAX_SPEED_MAX=0.004;
// const float MIN_SPEED=0.0008;

// const float RALENTIR_LUGAR=0.2;

// const float NEIGHBOR_INFLUENCE=0.1;


// /////////////////////////////////

// class Boid
// {
//     public :
//     glm::vec2 position;
//     float maxSpeed;
//     glm::vec2 speed;
//     glm::vec2 direction;

//     Boid(glm::vec2 p, float mS, glm::vec2 d): position(p), maxSpeed(mS), speed(), direction(d) {};
// };

// float RandomFloat(const float a, const float b) 
// {
//     float random = ((float)rand()) / (float)RAND_MAX;
//     float diff   = b - a;
//     float r      = random * diff;
//     return a + r;
// }

// void normaliseVector(glm::vec2 &v)
// {
//     float norm = std::sqrt(v.x*v.x + v.y*v.y);
//     v.x=v.x/norm;
//     v.y=v.y/norm;
// }

// std::vector<Boid> createBoids(const p6::Context& ctx, const size_t nb)
// {
//     std::vector<Boid> boids;
//     for(size_t i=0; i<nb; ++i)
//     {
//         glm::vec2 position=p6::random::point(ctx);
//         float maxSpeed = RandomFloat(MAX_SPEED_MIN, MAX_SPEED_MAX);
//         glm::vec2 direction = p6::random::direction();

//         Boid boid=Boid(position, maxSpeed, direction);
//         boids.push_back(boid);
//     }
//     return boids;
// }

// void neighborsManager(std::vector<Boid>& boids)
// {
//     for(size_t i=0; i<boids.size(); ++i)
//     {
//         size_t neighborIndex=i;
//         float neighborDistance=1000000; 

//         for(size_t j=0; j<boids.size(); ++j)
//         {
//             if(j!=i)
//             {
//                 float distance=sqrt(pow(boids[i].position.x-boids[j].position.x, 2)+pow(boids[i].position.y-boids[j].position.y, 2));

//                 if(distance<neighborDistance)
//                 {
//                     neighborIndex=j;
//                     neighborDistance=distance;
//                 }
//             }
//         }
//         boids[i].direction+=((boids[neighborIndex].direction-boids[i].direction))/neighborDistance*NEIGHBOR_INFLUENCE;
//         normaliseVector(boids[i].direction);
//     }
// }

// void turnManager(const p6::Context& ctx ,std::vector<Boid>& boids)
// {
//     for(Boid & boid : boids)
//     {

//         if((boid.position.x>ctx.aspect_ratio()*(1-RALENTIR_LUGAR)))
//         {
//             boid.speed.x=boid.maxSpeed*pow(((1-(boid.position.x-(1-RALENTIR_LUGAR)*ctx.aspect_ratio()))), 6)+MIN_SPEED;
//         }
//         else if((boid.position.x<-ctx.aspect_ratio()*(1-RALENTIR_LUGAR)))
//         {
//             boid.speed.x=boid.maxSpeed*pow(((1-(-boid.position.x-(1-RALENTIR_LUGAR)*ctx.aspect_ratio()))), 6)+MIN_SPEED;
//         }

//         if((boid.position.y>(1-RALENTIR_LUGAR)))
//         {
//             boid.speed.y=boid.maxSpeed*pow(((1-(boid.position.y-(1-RALENTIR_LUGAR)))), 6)+MIN_SPEED;
//         }
//         else if((boid.position.y<-(1-RALENTIR_LUGAR)))
//         {
//             boid.speed.y=boid.maxSpeed*pow(((1-(-boid.position.y-(1-RALENTIR_LUGAR)))), 6)+MIN_SPEED;
//         }
//     }
// }

// void borderManager(const p6::Context& ctx ,std::vector<Boid>& boids)
// {
//     for(Boid & boid : boids)
//     {
//         if(boid.position.x+boid.direction.x*boid.speed.x>ctx.aspect_ratio() 
//         || boid.position.x+boid.direction.x*boid.speed.x<-ctx.aspect_ratio())
//         {
//             boid.direction.x=-boid.direction.x;
//         }
//         if(boid.position.y+boid.direction.y*boid.speed.y>1 
//         || boid.position.y+boid.direction.y*boid.speed.y<-1)
//         {
//             boid.direction.y=-boid.direction.y;
//         }
//     }
// }

// void boidsDisplacement(std::vector<Boid>& boids)
// {
//     for(Boid & boid : boids)
//     {
//         if(boid.speed.x<boid.maxSpeed)
//         {
//             boid.speed.x+=ACCELERATION*boid.maxSpeed;
//         }
//         if(boid.speed.y<boid.maxSpeed)
//         {
//             boid.speed.y+=ACCELERATION*boid.maxSpeed;
//         }

//         boid.position.x+=boid.direction.x*boid.speed.x;
//         boid.position.y+=boid.direction.y*boid.speed.y;
//     }
// }

// void drawBoids(p6::Context& ctx, const std::vector<Boid>& boids)
// {
//     for(Boid boid : boids)
//     {
//         ctx.fill={-boid.direction.y-boid.direction.x,boid.direction.y,boid.direction.x,1};
//         ctx.circle(p6::Center{boid.position},p6::Radius{BOIDS_LENGHT});
//     }
// }

// int main(int argc, char* argv[])
// {
//     { // Run the tests
//         if (doctest::Context{}.run() != 0)
//             return EXIT_FAILURE;
//         // The CI does not have a GPU so it cannot run the rest of the code.
//         const bool no_gpu_available = argc >= 2 && strcmp(argv[1], "-nogpu") == 0; // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
//         if (no_gpu_available)
//             return EXIT_SUCCESS;
//     }

//     // Actual app
//     auto ctx = p6::Context{{.title = "Rem's boids"}};
//     ctx.maximize_window();
//     ctx.stroke_weight=0;

//     std::vector<Boid> boids=createBoids(ctx,NB_BOIDS);

//     // Declare your infinite update loop.
//     ctx.update = [&]() {

//         ctx.fill={0,0,0,1/TAIL_SIZE};
//         ctx.rectangle(p6::FullScreen{});

//         neighborsManager(boids);

//         turnManager(ctx, boids);
//         borderManager(ctx, boids);

//         boidsDisplacement(boids);

//         drawBoids(ctx, boids);
//     };

//     // Should be done last. It starts the infinite loop.
//     ctx.start();
// }