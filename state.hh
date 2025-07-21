#ifndef F62F8679_D4BB_4E12_B505_79B5FED4F9B0
#define F62F8679_D4BB_4E12_B505_79B5FED4F9B0

/* Stores the state of each cell:
    density
    momentum
    total energy
    velocity
    pressure
    magnetic field
*/

class state {
public:
    double rho;
    double momx;
    double momy;
    double momz;
    double p;
    double ux;
    double uy;
    double uz;
    double E;
    // allowing for transverse fields
    double By, Bz;
    state() : rho(0.0), momx(0.0), momy(0.0), momz(0.0), E(0.0), By(0.0), Bz(0.0) {
        ux = velocity(momx);
        uy = velocity(momy);
        uz = velocity(momz);
        p = pressure();
    }
    state(double r, double mx, double my, double mz, double e, double by, double bz) : rho(r), momx(mx), momy(my), momz(mz), E(e), By(by), Bz(bz) {
        ux = velocity(mx);
        uy = velocity(my);
        uz = velocity(mz);
        p = pressure();
    }
    state flux();
    double velocity(const double &mom);
    double pressure();
};

#endif /* F62F8679_D4BB_4E12_B505_79B5FED4F9B0 */
