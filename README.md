# 1D Alfvén Wave MHD Solver

## Overview

This project implements a simple 1D Magnetohydrodynamics (MHD) solver to simulate Alfvén waves in an ideal, magnetized plasma. The solver numerically integrates the ideal MHD equations using a finite difference Lax-Friedrichs scheme with periodic boundary conditions.

---

## Physical Model and Equations

The solver models the 1D ideal MHD equations along the \( x \)-direction with transverse velocity and magnetic field components \( (u_y, u_z) \) and \( (B_y, B_z) \). The system evolves the mass density (rho), the velocity components (u_x, u_y, u_z), the energy density (E) and the magnetic field (B_x, B_y, B_z).

The ideal MHD equations are solved assuming:

- 1D spatial variation along \( x \)
- Constant \( B_x \) background field (non-evolving)
- Periodic boundary conditions

---

## Initial Conditions: Alfvén Wave

The initial setup models a transverse Alfvén wave with:

- Uniform density rho_0 and pressure p_0
- Uniform magnetic field B_x
- Small sinusoidal perturbations in transverse velocity and magnetic field:

This configuration excites a linearly polarized Alfvén wave which causes oscillations in the transverse B_y magnetic field which we visualise

---

## Numerical Method

- Time integration uses a Lax-Friedrichs finite difference scheme
- Periodic boundary conditions ensure wave continuity.
- The conserved variables are updated by computing numerical fluxes from neighboring grid points.
- The solver outputs snapshots of all fields at specified time intervals for post-processing.

---
