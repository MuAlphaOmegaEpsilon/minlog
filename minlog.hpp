/**
 * @brief A Minimalist Logger for C++17. 
 * MinLog is a collection of printf-like functions for logging.
 * Every log function appends a newline at the end of the string passed as an argument.
 * @file MinLog.hpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com> https://github.com/MuAlphaOmegaEpsilon/minlog
 * @date 17-02-2019
 */

#ifndef MINLOG_HPP 
#define MINLOG_HPP

#include <stdio.h>

template<typename... Args> 
constexpr void LOG (const char * fmt, Args... args) noexcept
{
	constexpr int percentSignsIndices [sizeof...(args)];
	for (auto i : sizeof...(args))
		percentSignsIndices [i] = -1;

	#pragma message("Number of parameters:")
	#pragma message(sizeof...(args))

	printf ("PRINTF VERSION WITH %d PARAMETERS\n", sizeof...(args));
}

#endif