#include "state.hh"
#include "config.hh"

double state::velocity() {
    return mom / rho;
}

double state::pressure() {
    double u = velocity();
    // equation of state
    return (gamma - 1.0) * (E - 0.5 * rho * u * u);
}

// we can also hold the fluxes in a state
state state::flux() {
    double u = velocity();
    double p = pressure();
    return state(
        mom,         // mass flux
        mom * u + p, // momentum flux
        u * (E + p)  // energy flux
    );
}