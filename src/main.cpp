#include <cstddef>
#include <cstdlib>
#include "p6/p6.h"
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"

class Boids
{
    glm::vec2 position;
    float maxSpeed;
    float speed;
    float angle;

    Boids(glm::vec2 p, float mS, float a): position(p), maxSpeed(mS), speed(mS), angle(a) {};
};

std::vector<glm::vec2> createBoids(const p6::Context& ctx, const size_t nb)
{
    std::vector<glm::vec2> points;
    for(size_t i=0; i<nb; ++i)
    {
        points.push_back(p6::random::point(ctx));
    }
    return points;
}

void boidsDisplacement(/*const p6::Context& ctx,*/ std::vector<glm::vec2>& boids)
{
    for(size_t i=0; i<boids.size(); ++i)
    {
        float speed=0.001;
        boids[i]+=speed;
    }
}

void drawBoids(p6::Context& ctx, const std::vector<glm::vec2>& boids)
{
    for(auto boid : boids)
    {
        ctx.circle(p6::Center{boid},p6::Radius{0.02f});
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

    std::vector<glm::vec2> boids=createBoids(ctx,100);

    // Declare your infinite update loop.
    ctx.update = [&]() {

        ctx.background(p6::NamedColor::Cyan);

        boidsDisplacement(/*ctx,*/ boids);

        drawBoids(ctx, boids);
    };

    // Should be done last. It starts the infinite loop.
    ctx.start();
}