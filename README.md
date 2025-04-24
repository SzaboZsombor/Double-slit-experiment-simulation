# Quantum Double-Slit Monte Carlo Simulation

![Quantum Physics](https://img.shields.io/badge/Physics-Quantum-blue) 
![C++](https://img.shields.io/badge/Language-C++-orange) 
![Monte Carlo](https://img.shields.io/badge/Method-Monte_Carlo-purple)
### This project was made as part of the Programming 2 course during my second semester.

## Introduction

It's computational implementation of the famous quantum double-slit experiment using Monte Carlo methods, demonstrating wave-particle duality through numerical simulation. The system models the probability distribution of particle impacts on a detection screen after passing through two slits.

## Physical Model

The simulation calculates the quantum mechanical probability distribution using:

$$
P(x) = \frac{1}{d^2 + (x + \frac{l}{2})^2} + \frac{1}{d^2 + (x - \frac{l}{2})^2} + \frac{2P\cos(\omega)}{\sqrt{[d^2 + (x + \frac{l}{2})^2][d^2 + (x - \frac{l}{2})^2]}}
$$

Where the phase difference ω is given by:

$$
\omega = k\left(\sqrt{d^2 + \left(x - \frac{l}{2}\right)^2} - \sqrt{d^2 + \left(x + \frac{l}{2}\right)^2}\right)
$$

Parameters:
- $d$: Screen distance from slits
- $l$: Slit separation
- $x$: Position on detection screen
- $P = 1 - P_{\text{measure}}$: Quantum decoherence factor
- $k = \frac{\sqrt{2mE}}{\hbar}$: Wave number


### Requirements
- C++ compiler
- SDL2 and SDL2_ttf libraries
