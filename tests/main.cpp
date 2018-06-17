/**
 * @brief An example main file using the log functions of the MinLog library
 * @file main.cpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com> https://github.com/MuAlphaOmegaEpsilon/MinLog
 * @date 10-06-2018
 */

#include <MinLog/MinLog.hpp> // The MinLog library
#include <ctime>

/**
 * @brief Just a cleanup function: not actually using it as such.
 */
void cleanup ()
{
	LOG ("This is the last thing that will be logged.");
}

int main (int argc, char** argv)
{       
	// This will be printed only in debug mode
	LOG_DEBUG ("Starting the program.\n");

	atexit (cleanup); // Registering the cleanup () function to be called on exit

	time_t rawtime; // A time type struct
	time (&rawtime); // Initializing the time struct to the local system type

	// This will be printed in the standard output stream
	LOG ("The current time is %s", ctime (&rawtime));

	if (rawtime % 2)
	{
		// This will be printed in the standard error stream
		LOG_ERROR ("An unrecoverable error occured:");

		// This will be printed in the standard error stream
		// This will also call the exit () function
		LOG_EXIT ("\tThe local time has odd seconds!\n");
	}
		

	// This will be printed only in debug mode
	// The program flow is such that this is logged only if no "errors" occurs during the program runtime
	LOG_DEBUG ("Exiting the program without errors.\n"); 

    return 0;
}
