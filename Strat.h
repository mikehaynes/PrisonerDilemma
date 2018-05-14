/* Contains a class that contains a class to handle a stratagem
 *
 * Michael Haynes
 * mjhaynes
 *
 * Strat.h
 */

#ifndef STRAT_H
#define STRAT_H

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "State.h"

class Strat {
public:
	Strat() {
		strat_name = "NULL";
	}

	bool initialize(const std::string &filename) {
		std::ifstream file;
		file.open(filename);

		std::getline(file, strat_name);

		if (file.fail()) {
			std::cout << "Error in opening file: " << filename << "\n"
				      << "The file may not exist or is improperly formatted.\n"
					  << "Aborting..." << std::endl;

			const char* fname = filename.c_str();
			std::remove(fname);
			file.clear();
			
			return false;
		}

		int size;
		file >> size;

		if (file.fail()) {
			std::cout << "The file " << filename << " is improperly formatted.\n"
				      << "Aborting..." << std::endl;

			file.clear();
			
			return false;
		}

		if (size <= 0) {
			std::cout << "The file " << filename << " is improperly formatted.\n"
				<< "Aborting..." << std::endl;

			file.clear();

			return false;
		}

		strat.reserve(size);

		char action;
		int comply;
		int dissent;
		
		while (file >> action >> comply >> dissent) {
			Action act;

			switch (action) {
			case 'c':
			case 'C':
				act = COMPLY;
				break;
			case 'd':
			case 'D':
				act = DISSENT;
				break;
			default:
				std::cout << "The file " << filename << " is improperly formatted.\n"
						  << "Aborting..." << std::endl;

				file.clear();

				return false;
				break;
			}

			if (comply < 0 || comply >= size || dissent < 0 || dissent >= size) {
				std::cout << "The file " << filename << " is improperly formatted.\n"
						  << "Aborting..." << std::endl;

				file.clear();

				return false;
			}

			strat.push_back(State(act, comply, dissent));
		}

		return true;
	}

private:
	std::string strat_name;
	std::vector<State> strat;
};

#endif
