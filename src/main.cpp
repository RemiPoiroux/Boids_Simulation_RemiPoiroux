#include <cstddef>
#include <cstdlib>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"

#include "BoidsManager.hpp"

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

    /////////////////////////////////
    // PARAMETERS

    const int NB_BOIDS=200;
    float BOIDS_SIZE=0.04;
    float TAILS_SIZE=20;

    float BORDERS_DISTANCE=0.2;
    float BORDERS_STRENGTH=0.3; 

    float NEIGHBORS_PARAMETERS[]={  0.4f, 0.005f, // Alignment distance and strength
                                    0.3f, 0.002f, // Cohesion          //
                                    0.1f, 0.5f    // Separation        //
                                };

    /////////////////////////////////

    // Actual app
    auto ctx = p6::Context{{.title = "Rem's boids"}};
    ctx.maximize_window();
    ctx.use_stroke=false;

    std::vector<Boid> boids=createBoids(ctx,NB_BOIDS);

    // Declare your infinite update loop.
    ctx.update = [&]() {

        ImGui::Begin("Control");
        ImGui::SliderFloat("Boids size", &BOIDS_SIZE, 0.01f, 1.f);
        ImGui::SliderFloat("Tails size", &TAILS_SIZE, 1.f, 10000.f);
        ImGui::SliderFloat("Alignment distance", &NEIGHBORS_PARAMETERS[0], 0.f, 2.f);
        ImGui::SliderFloat("Alignment strength", &NEIGHBORS_PARAMETERS[1], 0.f, 1.f);
        ImGui::SliderFloat("Cohesion distance", &NEIGHBORS_PARAMETERS[2], 0.f, 2.f);
        ImGui::SliderFloat("Cohesion strength", &NEIGHBORS_PARAMETERS[3], 0.f, 1.f);
        ImGui::SliderFloat("Separation distance", &NEIGHBORS_PARAMETERS[4], 0.f, 2.f);
        ImGui::SliderFloat("Separation strength", &NEIGHBORS_PARAMETERS[5], 0.f, 1.f);
        ImGui::SliderFloat("Borders distance", &BORDERS_DISTANCE, 0.f, 1.f);
        ImGui::SliderFloat("Borders strength", &BORDERS_STRENGTH, 0.f, 1.f);
        ImGui::End();

        ctx.fill={0,0,0,1/TAILS_SIZE};
        ctx.rectangle(p6::FullScreen{});

        neighborsManager(boids, NEIGHBORS_PARAMETERS);

        borderManager(ctx, boids, BORDERS_DISTANCE, BORDERS_STRENGTH);

        boidsDisplacement(boids);

        drawBoids(ctx, boids, BOIDS_SIZE);
    };

    // Should be done last. It starts the infinite loop.
    ctx.start();
}