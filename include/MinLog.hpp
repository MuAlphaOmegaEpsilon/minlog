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

/**
 * @brief 
 * @param fmt The formatted string
 * @param ... The variadic function arguments
 */
void LOG (const char* fmt, ...)
{
	va_list args;
    va_start (args, fmt);
    vprintf (fmt, args);
    va_end (args);
}

void LOG_ABORT ();
void LOG_DEBUG ();
void LOG_ERROR ();


#endif