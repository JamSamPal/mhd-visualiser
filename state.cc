#include "state.hh"
#include "config.hh"

double state::velocity(const double &mom) {
    return mom / rho;
}

double state::pressure() {
    // equation of state
    return (Gamma - 1.0) * (E - 0.5 * rho * (ux * ux + uy * uy + uz * uz) - 0.5 * (Bx * Bx + By * By + Bz * Bz));
}

// we can also hold the fluxes in a state
state state::flux() {
    double ptot = p + 0.5 * (Bx * Bx + By * By + Bz * Bz);
    double BdotV = Bx * ux + By * uy + Bz * uz;
    return state(
        momx,                         // mass flux
        momx * ux + ptot - Bx * Bx,   // x-momentum flux
        momx * uy - Bx * By,          // y-momentum flux
        momx * uz - Bx * Bz,          // z-momentum flux
        (E + ptot) * ux - Bx * BdotV, // energy flux
        uy * Bx - ux * By,            // By evolution
        uz * Bx - ux * Bz             // Bz evolution
    );
}