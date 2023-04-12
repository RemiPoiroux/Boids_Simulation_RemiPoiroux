#pragma once

#include "Boid.hpp"

Boid randomBoid(const p6::Context& ctx);

std::vector<Boid> createBoids(const p6::Context& ctx, const size_t nb);

void neighborsManager(std::vector<Boid>& boids, const float parameters[6]);

void borderManager(const p6::Context& ctx ,std::vector<Boid>& boids, const float distance, const float strength);

void boidsDisplacement(std::vector<Boid>& boids);

void drawBoids(p6::Context& ctx, const std::vector<Boid>& boids, const float size);