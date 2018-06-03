/**
 * @brief This is the header file for the Minimalist Logger for C++. 
 * @file MinLog.hpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com>
 * @date 03-06-2018
 */

// Never include this header twice or more in a row
#ifndef MINLOG_HPP 
#define MINLOG_HPP
#pragma once

#include <cstdio>
#include <cstdarg>
#include <cstdlib>

/**
 * @brief Prints to the standard output.
 * @param fmt The string to format.
 * @param ... The variadic function arguments.
 */
void LOG (const char* fmt, ...)
{
	va_list args; // The variable containing the list of variadic arguments
    va_start (args, fmt); // A macro used to define the start of the usage of the variadic arguments
    vprintf (fmt, args); // Printing the formatted string to the standard output
    va_end (args); // A macro used to define the end of the usage of the variadic arguments
}

/**
 * @brief Prints to the standard error, calls the cleanup function (if specified) and then aborts.
 * @param cleanupFunction The function to call before aborting: use this to cleanup things. Passing a nullptr will result in no function call.
 * @param fmt The string to format.
 * @param ... The variadic function arguments.
 */
void LOG_ABORT (void (* cleanupFunction) (void), const char* fmt, ...)
{
    va_list args; // The variable containing the list of variadic arguments
    va_start (args, fmt); // A macro used to define the start of the usage of the variadic arguments
    vprintf (fmt, args); // Printing the formatted string to the standard output
    va_end (args); // A macro used to define the end of the usage of the variadic arguments

    if (cleanupFunction)
        cleanupFunction ();
    abort ();
}

void LOG_DEBUG (const char* fmt, ...)
{
    #ifndef NDEBUG
    va_list args; // The variable containing the list of variadic arguments
    va_start (args, fmt); // A macro used to define the start of the usage of the variadic arguments
    vprintf (fmt, args); // Printing the formatted string to the standard output
    va_end (args); // A macro used to define the end of the usage of the variadic arguments
    #endif
}

void LOG_ERROR (const char* fmt, ...)
{

}


#endif