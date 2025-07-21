#ifndef E0B6E553_AFE0_4110_AD38_81812E2EA298
#define E0B6E553_AFE0_4110_AD38_81812E2EA298

#include "state.hh"
#include <vector>

class Solver {
public:
    Solver(int gridSize, double dt, double dx)
        : N(gridSize), dt(dt), dx(dx), grid(gridSize, state()) {};
    std::vector<state>
        grid;
    void getGrid();
    void step();

private:
    int N;
    double dt;
    double dx;
};

#endif /* E0B6E553_AFE0_4110_AD38_81812E2EA298 */
