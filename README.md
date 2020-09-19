# PoissonEq
2D Poisson Equation solver using Openframeworks.

![Solved example]( https://github.com/bemoregt/PoissonEq/blob/master/scrshot.png "example")

![Differential Equation](https://github.com/bemoregt/PoissonEq/blob/master/174a0597a684dbb96.png)
- Poisson & Laplace Equation 

### Algorithm
- Left image is boundary condition space and right image is steady state space.
- Poisson Equation's solution is steady state of 2d space in this case.
- Differential equation is converted to difference equation for computer calculation.
- Poisson difference equation is extracted from u(x,u) function's Taylor series(simple finite element method).

### Dependency
- OpenFrameworks 0.11.0
- ofxCv
- ofxOpenCv
- XCode 11.1.x
- OSX Mojave

### Next Plan
- Iterational Solution Animation using update() method.
- Pseudo Coloring for grayscale. 
- Fast solver using FFT(DST).
- Elapsed Time Display for solve.
