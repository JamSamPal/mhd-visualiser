# 1D Alfvén Wave MHD Solver

## Overview

This project implements a simple 1D Magnetohydrodynamics (MHD) solver to simulate Alfvén waves in an ideal, magnetized plasma. The solver numerically integrates the ideal MHD equations using a finite difference Lax-Friedrichs scheme with periodic boundary conditions.

---

## Physical Model and Equations

The solver models the 1D ideal MHD equations along the \( x \)-direction with transverse velocity and magnetic field components \( (u_y, u_z) \) and \( (B_y, B_z) \). The system evolves the following conserved variables:

\[
U = \begin{bmatrix}
\rho \\
\rho u_x \\
\rho u_y \\
\rho u_z \\
E \\
B_y \\
B_z
\end{bmatrix}
\]

where

- \( \rho \) = mass density
- \( u_x, u_y, u_z \) = velocity components
- \( E \) = total energy density (thermal + kinetic + magnetic)
- \( B_x \) = constant background magnetic field along \( x \)
- \( B_y, B_z \) = transverse magnetic fields (evolving)

The flux vector \( F(U) \) is given by:

\[
F(U) = \begin{bmatrix}
\rho u_x \\
\rho u_x^2 + p + \frac{B^2}{2} - B_x^2 \\
\rho u_x u_y - B_x B_y \\
\rho u_x u_z - B_x B_z \\
(E + p + \frac{B^2}{2}) u_x - B_x (\mathbf{B} \cdot \mathbf{u}) \\
u_y B_x - u_x B_y \\
u_z B_x - u_x B_z
\end{bmatrix}
\]

where \( p \) is the thermal pressure and

\[
p = (\gamma - 1) \left(E - \frac{1}{2} \rho (u_x^2 + u_y^2 + u_z^2) - \frac{1}{2} (B_x^2 + B_y^2 + B_z^2)\right)
\]

The ideal MHD equations are solved assuming:

- 1D spatial variation along \( x \)
- Constant \( B_x \) background field (non-evolving)
- Periodic boundary conditions

---

## Initial Conditions: Alfvén Wave

The initial setup models a transverse Alfvén wave with:

- Uniform density \( \rho_0 \) and pressure \( p_0 \)
- Uniform magnetic field \( B_x \) along \( x \)
- Small sinusoidal perturbations in transverse velocity and magnetic field:

\[
u_y(x,0) = \delta \sin(2 \pi x / L)
\]
\[
B_y(x,0) = \delta \sin(2 \pi x / L)
\]

where \( \delta \ll 1 \) is the wave amplitude, and \( L \) is the domain length.

This configuration excites a linearly polarized Alfvén wave traveling at the Alfvén speed:

\[
v_A = \frac{B_x}{\sqrt{\rho_0}}
\]

---

## Numerical Method

- Time integration uses a Lax-Friedrichs finite difference scheme with timestep \( \Delta t \) and grid spacing \( \Delta x \).
- Periodic boundary conditions ensure wave continuity.
- The conserved variables are updated by computing numerical fluxes from neighboring grid points.
- The solver outputs snapshots of all fields at specified time intervals for post-processing.

---
