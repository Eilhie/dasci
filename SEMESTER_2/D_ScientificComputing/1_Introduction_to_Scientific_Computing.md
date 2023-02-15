# Scientific Computation
branch of computer science that involves the use of computer algorithms, software tools, and programming languages to solve complex mathematical, scientific, and engineering problems.

# Numerical Method
are the specific algorithms and techniques used to solve mathematical problems numerically. These methods may be developed using the principles of numerical analysis, but they are often customized to solve specific classes of problems. Examples of numerical methods include the finite element method, the finite difference method, the spectral method, and the Monte Carlo method. Numerical methods are typically implemented as computer programs that use iterative or recursive algorithms to compute approximate solutions to a problem

# Numerical Analysis
Numerical analysis is the study of algorithms and mathematical techniques for approximating the solutions to mathematical problems that cannot be solved exactly. It encompasses a wide range of topics, including numerical integration, numerical differentiation, linear algebra, optimization, and partial differential equations. The goal of numerical analysis is to understand the behavior of numerical algorithms, to develop new algorithms and techniques, and to provide theoretical guarantees on the accuracy and convergence of these algorithms.

# Numerical Analysis and Numerical Methods difference

Methods = approximate, More intuitive, easily coded, easy to get, finds a solusion, may diverge

Analytical = exact, less intuitive, not so easy, not so easy, not the solution, always finds the solution

# Programming Language
Fotran, MATLAB, Scilab, GNU-Octave, Mathematica, Python

# Why use Numerical Methods ?
to solve problems that cannot be solved exactly. 
we utilize numerical approximation of solutions to understood problems two main objectives

- quantify errors : approximation without error estimation is useless
- increase efficiency : solutions which take years or need more resources that you have are useless

what can we solve numerically?
- systems of linear equations
- regression and interpolation
- taylor series
- root of equations
- numerical differentiantion
- numerical integration
- ordinary differential equations
- etc.



# How to represent the numbers and hom they are useful for computers?
- Representation of numbers

    digital computers, use Binary number system to represent all types of information inside the computers. Alphanumeric characters are represented using binary bits (i.e., 0 and 1). 

    Digital representations are easier to design, storage is easy, accuracy and precision are greater.
    There are various types of number representation techniques for digital number representation, for example: Binary number system, decimal number system, and hexadecimal number system etc. 

- Rounding and Chopping

    Rounding: Replace the number by the nearest machine number.

    Chopping: Throw all extra digits

- Accuracy and Precision

    Accuracy is related to the closeness to the true value.    

    Precision is related to the closeness to other estimated values.

- Error Definitions

    Truncation errors, result when approximations/discretization are used to represent exact mathematical procedures. e.g. finite Taylor series

    taylor series expansions to approximate/predict the function's value


    Round-off errors, result when numbers having limited significant figures are used to represent exact numbers.

    Roundoff errors arise for the reason that PCs cannot represent some quantities exactly.

    Round-off errors occur because computers retain only a fixed number of significant figures.


    Modeling Error, Errors in deriving the mathematical equation or using a model that does not describe adequately the physical system under study. 

    e.g. Selecting a wrong algorithm

- Approximation error

    The approximation error in a data value is the discrepancy between an exact value and some approximation to it. 

    1. True/actual error is the different between the true/actual value and approximate value
    2. Absolute error is the difference between measured or inferred value and the actual value of a quantity.
    3. Relative error is ratio between the true error and true value.

