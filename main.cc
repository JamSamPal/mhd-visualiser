#include "config.hh"
#include "solver.hh"
#include <iostream>
#include <math.h>

int main() {
    // Increasing the data points and decreasing the timestep will more
    // closely approximate the exact solution
    const int N = 200;        // Number of grid points
    const double L = 1.0;     // Domain length
    const double dx = L / N;  // Spatial step
    const double dt = 0.0005; // Time step
    const double t_final = 5; // End time

    Solver solver(N, dt, dx);

    double rho0 = 1.0;
    double p0 = 1.0;
    double Bx = 1.0;
    double delta = 0.1;

    for (int i = 0; i < N; ++i) {
        double x = i * dx;

        double uy = delta * sin(2 * M_PI * x);
        double By = delta * sin(2 * M_PI * x);
        double uz = 0.0;
        double Bz = 0.0;
        double ux = 0.0;

        double momx = rho0 * ux;
        double momy = rho0 * uy;
        double momz = rho0 * uz;

        double kinetic = 0.5 * rho0 * (ux * ux + uy * uy + uz * uz);
        double magnetic = 0.5 * (Bx * Bx + By * By + Bz * Bz);
        double energy = p0 / (Gamma - 1) + kinetic + magnetic;

        solver.grid[i] = state(rho0, momx, momy, momz, energy, By, Bz);
    }

    const int output_interval = 100;
    int step_count = 0;

    for (double t = 0.0; t < t_final; t += dt) {
        solver.step();
        step_count++;

        if (step_count % output_interval == 0) {
            std::string filename = "output/data_" + std::to_string(step_count) + ".dat";
            solver.saveGrid(filename);
        }
    }

    return 0;
}