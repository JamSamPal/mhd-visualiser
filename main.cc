#include "config.hh"
#include "solver.hh"
#include <iostream>

int main() {
    // Increasing the data points and decreasing the timestep will more
    // closely approximate the exact solution
    const int N = 10000;        // Number of grid points
    const double L = 1.0;       // Domain length
    const double dx = L / N;    // Spatial step
    const double dt = 0.00001;  // Time step
    const double t_final = 0.2; // End time

    Solver solver(N, dt, dx);

    // Sod tube initial state
    double rho_left = 1.0;
    double u_left = 0.0;
    double p_left = 1.0;

    double rho_right = 0.125;
    double u_right = 0.0;
    double p_right = 0.1;

    double E_left = p_left / (gamma - 1.0) + 0.5 * rho_left * u_left * u_left;
    double E_right = p_right / (gamma - 1.0) + 0.5 * rho_right * u_right * u_right;

    for (int i = 0; i < N; ++i) {
        if (i < N / 2) {
            solver.grid[i] = state(rho_left, rho_left * u_left, E_left);
        } else {
            solver.grid[i] = state(rho_right, rho_right * u_right, E_right);
        }
    }

    for (double t = 0.0; t < t_final; t += dt) {
        solver.step();
    }

    solver.getGrid();

    return 0;
}