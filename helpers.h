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

#include "Strat.h"

void ignore(char delimit) {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), delimit);

	return;
}

//            1
//         C     D
//      -------------
//    C | 2,2 | 3,0 |
//  2   -------------
//    D | 0,3 | 1,1 |
//      -------------
void print_help() {
	std::cout << "TODO" << std::endl;

	return;
}

void simulate_turns(const Strat &strat1, const Strat &strat2,
					const int rounds, const bool verbose) {
	int score1 = 0;
	int score2 = 0;

	int state1 = 0;
	int state2 = 0;

	for (int i = 0; i < rounds; i++) {
		Action action1 = strat1.get_action(state1);
		Action action2 = strat2.get_action(state2);

		if (action1 == COMPLY && action2 == COMPLY) {
			if (verbose) {
				cout << strat1.get_name() << " complies and "
					 << strat2.get_name() << " complies.\n"
					 << "\t" << strat1.get_name() << " score = " << score1 << " + 2\n"
					 << "\t" << strat2.get_name() << " score = " << score2 << " + 2" << endl;
			}
			score1 += 2;
			score2 += 2;
		}
		else if (action1 == COMPLY && action2 == DISSENT) {
			if (verbose) {
				cout << strat1.get_name() << " complies and "
					 << strat2.get_name() << " dissents.\n"
					 << "\t" << strat1.get_name() << " score = " << score1 << " + 0\n"
					 << "\t" << strat2.get_name() << " score = " << score2 << " + 3" << endl;
			}
			score1 += 0;
			score2 += 3;
		}
		else if (action1 == DISSENT && action2 == COMPLY) {
			if (verbose) {
				cout << strat1.get_name() << " dissents and "
					 << strat2.get_name() << " complies.\n"
					 << "\t" << strat1.get_name() << " score = " << score1 << " + 3\n"
					 << "\t" << strat2.get_name() << " score = " << score2 << " + 0" << endl;
			}
			score1 += 3;
			score2 += 0;
		}
		else /*(action1 == DISSENT && action2 == DISSENT)*/ {
			if (verbose) {
				cout << strat1.get_name() << " dissents and "
					 << strat2.get_name() << " dissents.\n"
					 << "\t" << strat1.get_name() << " score = " << score1 << " + 1\n"
					 << "\t" << strat2.get_name() << " score = " << score2 << " + 1" << endl;
			}
			score1 += 1;
			score2 += 1;
		}

		state1 = strat1.get_next_state(state1, action2);
		state2 = strat2.get_next_state(state2, action1);
	}
}

#endif