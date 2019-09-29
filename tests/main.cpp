/**
 * @brief An example main file using the log functions of the MinLog library
 * @file main.cpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com> https://github.com/MuAlphaOmegaEpsilon/MinLog
 * @date 10-06-2018
 */

#include <minlog.hpp>

int main (int argc, char** argv)
{     
	const char * Hello = "Hello";  
	const char * Hello_World_fmt = "Hello %s";
	const char * world = "world!";

	LOG (Hello);
	LOG (Hello_World_fmt, world);
    return 0;
}
