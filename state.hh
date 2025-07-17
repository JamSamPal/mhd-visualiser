#ifndef F62F8679_D4BB_4E12_B505_79B5FED4F9B0
#define F62F8679_D4BB_4E12_B505_79B5FED4F9B0

/* Stores the state of each cell:
    density
    momentum
    total energy
    velocity
    pressure
*/

class state {
public:
    double rho;
    double mom;
    double E;
    state() : rho(0.0), mom(0.0), E(0.0) {}
    state(double r, double m, double e) : rho(r), mom(m), E(e) {}
    state flux();
    double velocity();
    double pressure();
};

#endif /* F62F8679_D4BB_4E12_B505_79B5FED4F9B0 */
