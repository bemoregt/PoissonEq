# PoissonEq
2D Poisson Equation solver using Openframeworks.

![Solved example]( https://github.com/bemoregt/PoissonEq/blob/master/scrshot.png "example")

### Algorithm
- Left image is boundary condition space and right image is steady state space.
- Poisson Equation's solution is steady state of 2d space in this case.
- Differential equation is converted to difference equation for computer calculation.

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
