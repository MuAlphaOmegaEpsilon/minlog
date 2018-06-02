<img src="https://github.com/MuAlphaOmegaEpsilon/MinLog/blob/master/images/MinLog.png" alt="MinLog" width="450">

# Minimalist Logger for C++
This is a README file for MinLog, a minimalist C++ logger header.
The README is organized as a FAQ.

## What is the license used by MinLog?
The GNU General Public License v3.0.
Open the LICENSE file for more informations about it.

## What's the point of having another logging library for C++?
I wanted a very small set of logging tools, without the usual bloat that a logging library adds, since I'm not going to use most of those features and I have no intention to wrap my head around verbosity levels, logger initializations, and so on. 
*I JUST WANT TO LOG*



MinLog uses a single header file to give you access to printf-like logging functions, with the below properties:
* No initialization required
* No structs nor classes involved