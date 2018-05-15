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
#include <string>

#include "optlong_lib.h"
#include "Strat.h"
#include "helpers.h"

using namespace std;

bool init_strat(Strat &strat, const string &filename);

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);

	OptWrap options;
	get_options(argc, argv, options);
	if (options.num_rounds <= 0) {
		cout << "Number of rounds must be greater than 8.  Aborting..." << endl;
		return 3;
	}

	Strat strat1;
	Strat strat2;

	if (init_strat(strat1, options.strat1)) {
		cout << "Success!" << endl;
	}
	else {
		return 1;
	}

	if (init_strat(strat2, options.strat2)) {
		cout << "Success" << endl;
	}
	else {
		return 2;
	}

	return 0;
}

bool init_strat(Strat &strat, const string &filename) {
	cout << "Initializing from " << filename << "..." << endl;
	return strat.initialize(filename);
}