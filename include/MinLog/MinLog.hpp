/**
 * @brief This is the header file for the Minimalist Logger for C++. 
 * MinLog is a collection of printf-like functions for logging.
 * Every log function appends a newline at the end of the string passed as an argument.
 * @file MinLog.hpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com> https://github.com/MuAlphaOmegaEpsilon/MinLog
 * @date 03-06-2018
 */

// Never include this header twice or more in a row
#ifndef MINLOG_HPP 
#define MINLOG_HPP
#pragma once

#include <cstdio>
#include <cstdarg>
#include <cstdlib>

//#define NO_LOG // Enabling this will disable all the logging without introducing runtime cost if -01 or greater is selected.

/**
 * @brief Logs to the standard output like a normal printf.
 * @param fmt The format of the string.
 * @param ... The variadic function arguments.
 */
inline void LOG (const char* fmt, ...) noexcept
{
    #ifndef NO_LOG
	va_list args; // The variable containing the list of variadic arguments
    va_start (args, fmt); // A macro used to define the start of the usage of the variadic arguments
    vfprintf (stdout, fmt, args); // Printing the formatted string to the standard output
    fprintf (stdout, "\n"); // Newline
    va_end (args); // A macro used to define the end of the usage of the variadic arguments
    #endif
}

/**
 * @brief Logs to the standard output only if the NDEBUG flag is not defined by a macro. Useful for logging in debug, but not during release.
 * @param fmt The format of the string.
 * @param ... The variadic function arguments.
 */
inline void LOG_DEBUG (const char* fmt, ...) noexcept
{
    #ifndef NO_LOG
    #ifndef NDEBUG
    va_list args; // The variable containing the list of variadic arguments
    va_start (args, fmt); // A macro used to define the start of the usage of the variadic arguments
    vfprintf (stdout, fmt, args); // Printing the formatted string to the standard output
    fprintf (stdout, "\n"); // Newline
    va_end (args); // A macro used to define the end of the usage of the variadic arguments
    #endif
    #endif
}

/**
 * @brief Logs to the standard error.
 * @param fmt The format of the string.
 * @param ... The variadic function arguments.
 */
inline void LOG_ERROR (const char* fmt, ...) noexcept
{
    #ifndef NO_LOG
    va_list args; // The variable containing the list of variadic arguments
    va_start (args, fmt); // A macro used to define the start of the usage of the variadic arguments
    vfprintf (stderr, fmt, args); // Printing the formatted string to the standard output
    fprintf (stderr, "\n"); // Newline
    va_end (args); // A macro used to define the end of the usage of the variadic arguments
    #endif
}

/**
 * @brief Logs to the standard error, than makes the program exit with the EXIT_FAILURE code. 
 * Remember that if you want to call a "cleanup funcion" before exiting, you can do this by using the "atexit" function.
 * @param fmt The format of the string.
 * @param ... The variadic function arguments.
 */
inline void LOG_EXIT (const char* fmt, ...) noexcept
{
    #ifndef NO_LOG
    va_list args; // The variable containing the list of variadic arguments
    va_start (args, fmt); // A macro used to define the start of the usage of the variadic arguments
    vfprintf (stderr, fmt, args); // Printing the formatted string to the standard output
    fprintf (stderr, "\n"); // Newline
    va_end (args); // A macro used to define the end of the usage of the variadic arguments
    exit (EXIT_FAILURE);
    #endif
}

#endif