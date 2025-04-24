# Quantum Double-Slit Monte Carlo Simulation

![Quantum Physics](https://img.shields.io/badge/Physics-Quantum-blue) 
![C++](https://img.shields.io/badge/Language-C++-orange) 
![SDL](https://img.shields.io/badge/Graphics-SDL2-green)
![Monte Carlo](https://img.shields.io/badge/Method-Monte_Carlo-purple)

A stunning visualization of quantum mechanics' most famous paradox - demonstrating wave-particle duality through Monte Carlo simulation.

## Key Features

- **Real-time quantum interference visualization**
- **Customizable experimental parameters**
- **Quantum measurement effects simulation**
- **Beautiful SDL2 graphics engine**
- **Scientific accuracy with Monte Carlo methods**

```c++
// Quantum magic happening here
double probability = (1/(d*d + pow(x+l/2,2))) 
                   + (1/(d*d + pow(x-l/2,2)))
                   + P*2*cos(omega)/sqrt((d*d+pow(x+l/2,2))*(d*d+pow(x-l/2,2)));
