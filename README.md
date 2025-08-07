# 1D Alfvén Wave MHD Solver

## Overview

This project implements a 1D solver to simulate Alfvén waves in an ideal, magnetized plasma. The solver numerically integrates the ideal MHD equations using a finite difference Lax-Friedrichs scheme with periodic boundary conditions.

---

## Physical Model and Equations

The solver models the 1D ideal MHD equations along the \( x \)-direction with transverse velocity and magnetic field components \( (u_y, u_z) \) and \( (B_y, B_z) \). The system evolves the mass density (rho), the velocity components (u_x, u_y, u_z), the energy density (E) and the magnetic field (B_x, B_y, B_z).

---

## Initial Conditions: Alfvén Wave

The initial conditions are such that we begin with a uniform density rho_0 and pressure p_0 and a uniform magnetic field B_x. We then add a small sinusoidal perturbations to the transverse velocity and magnetic field:

This configuration excites a linearly polarized Alfvén wave which causes oscillations in the transverse B_y magnetic field which we visualise

---

## Numerical Method

- Time integration uses a Lax-Friedrichs finite difference scheme
- Periodic boundary conditions
- The conserved variables are updated by computing numerical fluxes from neighboring grid points.
- The solver outputs snapshots of all fields at specified time intervals for post-processing.

---

---

## Running

clear output directory

g++ -o mhd_solver main.cc solver.cc state.cc

./mhd_solver

And then

python test.py

---
