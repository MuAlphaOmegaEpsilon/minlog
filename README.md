<img src="https://github.com/MuAlphaOmegaEpsilon/MinLog/blob/master/images/MinLog.png" alt="MinLog" width="450">

# Minimalist Logger for C++
This is a README file for MinLog, a minimalist C++ logger header.\
The README is organized as a FAQ.

## What's the point of having another logging library for C++?
I wanted a very small set of logging tools, without the usual bloat that a logging library usually adds, since I'm not going to use most of those features and I have no intention to wrap my head around verbosity levels, logger initializations, and so on.\
**I JUST WANT TO LOG**

## What are the pros of this library?
* Header-only library
* No initialization required
* No structs nor classes involved
* Printf-like
* Under 100 LOC (Lines Of Code) in C++ --> Under 150 LOC in Assembly with the -01 flag
* Logging can be entirely disabled without additional runtime-cost by defining a macro
* Always adds a newline after your string for you
* [Doxygen](http://www.doxygen.org) ready
* [CMake](https://cmake.org/) ready

## What are the functions offered by this library?
* **LOG (" ", ...)**: Logs to the standard output like a normal printf.
* **LOG_DEBUG (" ", ...)**: Logs to the standard output only if the NDEBUG flag is not defined by a macro. Useful for logging in debug, but not during release.
* **LOG_ERROR (" ", ...)**: Logs to the standard error.
* **LOG_EXIT (" ", ...)**: Logs to the standard error, than makes the program exit with the EXIT_FAILURE code. Remember that if you want to call a "cleanup funcion" before exiting, you can do this by using the "atexit" function.

## How can I integrate this library using CMake?
After cloning this repo like this:
```
git clone https://github.com/MuAlphaOmegaEpsilon/MinLog
```
Just add these two lines inside your CMakeLists.txt file:
```
ADD_SUBDIRECTORY (***path_to_MinLog_folder***)
TARGET_LINK_LIBRARIES (***project_name*** PUBLIC MinLog)
```
And then include this library wherever you want in your project with:
```
#include <MinLog/MinLog.hpp>
```

## Are there any examples?
Yes, you can find a [simple usage case](../tests/main.cpp) inside the [tests/](../blob/master/tests) folder.
### How can I launch it?
There you go. 
Remember that this test executable is programmed to log an error when the local time has odd seconds.
```bash
mkdir build
cd build
cmake .. -DBUILD_TESTING=ON
make
./MinLogTest
```

## What is the license used by MinLog?
The GNU General Public License v3.0.\
Open the LICENSE file for more informations about it.