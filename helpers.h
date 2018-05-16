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
#include <vector>
#include <cstdlib>
#include <string>

#include "Strat.h"

const std::string& get_random_strategy() {
	std::vector<std::string> strats = { "tit-for-two-tats.pds",
										"tit-for-tat.pds",
										"always-dissent.pds",
										"always-comply.pds",
										"grudger.pds" };

	int strat = rand() % strats.size();

	return strats[strat];
}

void ignore(char delimit) {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), delimit);

	return;
}

void print_help() {
	int null = 0;

	std::cout << "This is a simulator for the game \"Prisoner's Dilemma\" in\n"
			  << "which two prisoners that are accomplices are approached\n"
			  << "seperately by detectives and offered a deal.  If the prisoner\n"
			  << "defects and rats out his/her partner, and the partner continues\n"
			  << "to cooperate, then the prisoner will be released and the\n"
			  << "partner will spend three years in prison for their crime.  If\n"
			  << "both prisoners defect, they will both be found guilty and receive\n"
			  << "a reduced sentence of two years each.  If both prisoners continue\n"
			  << "to cooperate, then they will be found guilty of a lesser crime and\n"
			  << "each will spend a year in prison.  Neither prisoner is able to\n"
			  << "know which option the other prisoner will choose.  The \"scoring\"\n"
			  << "can bevisualized as follows:\n"
			  << "\n"
			  << "          1      \n"
			  << "       C     D   \n"
			  << "    -------------\n"
			  << "  C | 1\\1 | 0\\3 |\n"
			  << "2   -------------\n"
			  << "  D | 3\\0 | 2\\2 |\n"
			  << "    -------------\n"
			  << "\n"
			  << "Press ENTER to continue..." << std::endl;

	std::cin >> null;
	std::cin.clear();
	ignore('\n');
	std::cin.clear();

	std::cout << "\nThe game is played by developing a strategy of multiple states.\n"
			  << "Each state first tells what the prisoner's action will be, then\n"
			  << "which state to jump to if the other prisoner complies, then which\n"
			  << "state to jump to if the other prisoner dissents.  The strategies\n"
			  << "must be in text files that follow the following format:\n"
			  << "\n"
			  << "NAME OF STRATEGY\n"
			  << "Number of states\n"
			  << "State 0\n"
			  << "State 1\n"
			  << "State 3\n"
			  << "...\n"
			  << "\n"
			  << "The following as a sample for the popular \"Tit-For-Two-Tats\" strategy:\n"
			  << "\n"
			  << "Tit-For-Two-Tats\n"
			  << "3\n"
			  << "C  0  1\n"
			  << "C  0  2\n"
			  << "D  0  2\n"
			  << "\n"
			  << "Press ENTER to continue..." << std::endl;

	std::cin >> null;
	std::cin.clear();
	ignore('\n');
	std::cin.clear();

	std::cout << "\nUse the following flags to run the program:\n"
			  << "\n"
			  << "-1 | --strat1 <filename>   The file that contains the first\n"
			  << "                           prisoner's strategy.  If not used,\n"
			  << "                           one will be picked randomly.\n"
			  << "-2 | --strat2 <filename>   The file that contains the second\n"
			  << "                           prisoner's strategy.  If not used,\n"
			  << "                           one will be picked randomly.\n"
			  << "-r | --rounds <number>     The number of rounds to be played.\n"
			  << "-v | --verbose             If set, each round's results are displayed\n"
			  << "\n"
			  << "Several simple strategies already exist with the extension .pds\n"
			  << "and these can be used by the player or will be chosen from randomly\n"
			  << "when no strategy is specified.\n"
			  << "\n"
			  << "Have fun!" << std::endl;

	return;
}

void print_scores(const std::string &name1, const std::string &name2,
	const int score1, const int score2) {
	std::cout << "The strategy \"" << name1 << "\" spends "
		<< score1 << " years in prison.\n"
		<< "The strategy \"" << name2 << "\" spends "
		<< score2 << " years in prison.\n";
	if (score1 < score2) {
		std::cout << "The strategy \"" << name1 << "\" wins!" << std::endl;
	}
	else if (score2 < score1) {
		std::cout << "The strategy \"" << name2 << "\" wins!" << std::endl;
	}
	else {
		std::cout << "It's a tie!" << std::endl;
	}

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

		if (action1 == COOPERATE && action2 == COOPERATE) {
			if (verbose) {
				std::cout << strat1.get_name() << " cooperates and "
						  << strat2.get_name() << " cooperates.\n"
						  << "\t" << strat1.get_name() << " score = "
						  << score1 << " + 1\n"
						  << "\t" << strat2.get_name() << " score = "
						  << score2 << " + 1" << std::endl;
			}
			score1 += 1;
			score2 += 1;
		}
		else if (action1 == COOPERATE && action2 == DEFECT) {
			if (verbose) {
				std::cout << strat1.get_name() << " cooperates and "
						  << strat2.get_name() << " defects.\n"
						  << "\t" << strat1.get_name() << " score = "
						  << score1 << " + 3\n"
						  << "\t" << strat2.get_name() << " score = "
						  << score2 << " + 0" << std::endl;
			}
			score1 += 3;
			score2 += 0;
		}
		else if (action1 == DEFECT && action2 == COOPERATE) {
			if (verbose) {
				std::cout << strat1.get_name() << " defects and "
						  << strat2.get_name() << " cooperates.\n"
						  << "\t" << strat1.get_name() << " score = "
						  << score1 << " + 0\n"
						  << "\t" << strat2.get_name() << " score = "
						  << score2 << " + 3" << std::endl;
			}
			score1 += 0;
			score2 += 3;
		}
		else /*(action1 == DEFECT && action2 == DEFECT)*/ {
			if (verbose) {
				std::cout << strat1.get_name() << " defects and "
						  << strat2.get_name() << " defects.\n"
						  << "\t" << strat1.get_name() << " score = "
						  << score1 << " + 2\n"
						  << "\t" << strat2.get_name() << " score = "
						  << score2 << " + 2" << std::endl;
			}
			score1 += 2;
			score2 += 2;
		}

		state1 = strat1.get_next_state(state1, action2);
		state2 = strat2.get_next_state(state2, action1);
	}

	print_scores(strat1.get_name(), strat2.get_name(), score1, score2);
}

#endif