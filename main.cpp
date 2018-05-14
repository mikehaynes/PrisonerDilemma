/* This program simulates the head-to-head
 * battle of two, predetermined Prisoner's Dilemma
 * strategies over a number of rounds that the
 * user sets.
 *
 * Michael Haynes
 * mjhaynes@umich.edu
 *
 * main.cpp
 */

#include <iostream>

#include "optlong_lib.h"

using namespace std;

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);

	OptWrap options;

	get_options(argc, argv, options);

	return 0;
}