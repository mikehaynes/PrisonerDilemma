/* Library to handle command-line args
 * for Project 4.  Also contains a
 * project-specific struct to hold all of the
 * arguments.
 *
 * EECS 281
 *
 * Michael Haynes
 * mjhaynes@umich.edu
 *
 * optlong_lib.cpp
 */

#ifndef OPTLONG_LIB_H
#define OPTLONG_LIB_H

#include <string>

const std::string RANDOM = "random";
class OptWrap {
public:
	OptWrap() {
		strat1 = RANDOM;
		strat2 = RANDOM;
		verbose = false;
		num_rounds = 10;
	}

	std::string strat1;
	std::string strat2;
	int num_rounds;
	bool verbose;
};

void get_options(int argc, char *argv[], OptWrap &options);

#endif