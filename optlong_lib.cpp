/* Library to handle command-line args
 * for Project 4.
 * 
 * EECS 281
 *
 * Michael Haynes
 * mjhaynes@umich.edu
 *
 * optlong_lib.cpp
 */

#include <getopt.h>
#include <iostream>
#include <string>

#include "optlong_lib.h"
#include "helpers.h"

using namespace std;

// Parses command-line inputs and modifies the necessary values
void get_options(int argc, char *argv[], OptWrap &options) {

    int option = 0; // DO NOT CHANGE
    int option_index = 0; // DO NOT CHANGE

    opterr = false; // DO NOT CHANGE!!!

	bool rounds = false;

    struct option long_opts[] = { {"help", no_argument, nullptr, 'h'},
                                  {"verbose", no_argument, nullptr, 'v'},
								  {"strat1", required_argument, nullptr, '1'},
							      {"strat2", required_argument, nullptr, '2'},
								  {"rounds", required_argument, nullptr, 'r'},
                                  {nullptr, 0, nullptr, '\0'} };

    while ((option = getopt_long(argc, argv, "vr:1:2:h",
								 long_opts, &option_index)) != -1) {
        switch (option) {
		case '1':
			options.strat1 = optarg;
			break;
		case '2':
			options.strat2 = optarg;
			break;
		case 'r':
			options.num_rounds = stoi(optarg);
			rounds = true;
			break;
		case 'v':
			options.verbose = true;
			break;
        case 'h':
			print_help();
            exit(0);
			break;
		default:
			cout << "Invalid flag: " << option << endl;
			exit(0);
			break;
		}
    }

	if (!rounds) {
		cout << "Number of rounds not specified, set to 10 by default." << endl;
	}

    return;
}