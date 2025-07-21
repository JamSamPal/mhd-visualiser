#include "solver.hh"
#include <fstream>

void Solver::saveGrid(const std::string &filename) {

    std::ofstream out(filename);

    for (int i = 0; i < N; ++i) {
        double x = i * dx;
        out << x << " " << grid[i].rho << " " << grid[i].momx << " " << grid[i].momy << " " << grid[i].momz << " " << grid[i].E << " " << grid[i].By << " " << grid[i].Bz << "\n";
    }

    out.close();
}

void Solver::step() {
    // update grid across a timestep
    std::vector<state> newGrid = grid;
    for (int i = 0; i < N; i++) {
        int iL = (i - 1 + N) % N; // left neighbor with wrap-around
        int iR = (i + 1) % N;     // right neighbor with wrap-around
        state UL = grid[iL];
        state UR = grid[iR];
        state FL = UL.flux();
        state FR = UR.flux();

        newGrid[i].rho = 0.5 * (UL.rho + UR.rho) - 0.5 * (dt / dx) * (FR.rho - FL.rho);
        newGrid[i].momx = 0.5 * (UL.momx + UR.momx) - 0.5 * (dt / dx) * (FR.momx - FL.momx);
        newGrid[i].momy = 0.5 * (UL.momy + UR.momy) - 0.5 * (dt / dx) * (FR.momy - FL.momy);
        newGrid[i].momz = 0.5 * (UL.momz + UR.momz) - 0.5 * (dt / dx) * (FR.momz - FL.momz);
        newGrid[i].E = 0.5 * (UL.E + UR.E) - 0.5 * (dt / dx) * (FR.E - FL.E);
        newGrid[i].By = 0.5 * (UL.By + UR.By) - 0.5 * (dt / dx) * (FR.By - FL.By);
        newGrid[i].Bz = 0.5 * (UL.Bz + UR.Bz) - 0.5 * (dt / dx) * (FR.Bz - FL.Bz);
    }

    grid = newGrid;
}