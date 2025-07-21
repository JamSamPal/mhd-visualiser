#include "solver.hh"
#include <fstream>

void Solver::getGrid() {

    std::ofstream out("density.dat");

    for (int i = 0; i < N; ++i) {
        double x = i * dx;
        out << x << " " << grid[i].rho << "\n";
    }

    out.close();
}

void Solver::step() {
    // update grid across a timestep
    std::vector<state> newGrid = grid;
    for (int i = 1; i < N - 1; i++) {
        state UL = grid[i - 1];
        state UR = grid[i + 1];
        state FL = UL.flux();
        state FR = UR.flux();

        newGrid[i].rho = 0.5 * (UL.rho + UR.rho) - 0.5 * (dt / dx) * (FR.rho - FL.rho);
        newGrid[i].mom = 0.5 * (UL.mom + UR.mom) - 0.5 * (dt / dx) * (FR.mom - FL.mom);
        newGrid[i].E = 0.5 * (UL.E + UR.E) - 0.5 * (dt / dx) * (FR.E - FL.E);
    }

    grid = newGrid;
}