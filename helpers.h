/* This file is used to hold all general helper functions
 * for the entire project.
 *
 * Michael Haynes
 * mjhaynes@umich.edu
 *
 * helpers.h
 */

#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <limits>

void ignore(char delimit) {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), delimit);

	return;
}

void print_help() {
	std::cout << "TODO" << std::endl;

	return;
}

#endif