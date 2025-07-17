import matplotlib.pyplot as plt
import sodshock
import numpy as np

# Verify numerical algorithm
# We compare with the analytical solution
# so results won't be identical but a plot
# should qualitatively verify we are correct
gamma = 1.4
dustFrac = 0.0
npts = 100
t = 0.2
left_state = (1,1,0)
right_state = (0.1, 0.125, 0)

# Compute solution
positions, regions, values = sodshock.solve(left_state=left_state, \
        right_state=right_state, geometry=(0, 1, 0.5), t=t, 
        gamma=gamma, npts=npts, dustFrac=dustFrac)


# Save density to file
np.savetxt('analytical.dat', np.column_stack((values['x'], values['rho'])))

data = np.loadtxt("density.dat")
analytics = np.loadtxt("analytical.dat")
x = data[:, 0]
rho = data[:, 1]
x_an = analytics[:, 0]
rho_an = analytics[:, 1]

plt.plot(x, rho, label="Density")
plt.plot(x_an, rho_an, label="Density")
plt.xlabel("x")
plt.ylabel("ρ")
plt.title("Density Profile")
plt.grid(True)
plt.legend()
plt.show()