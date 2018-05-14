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

#include "optlong_lib.h"
#include "helpers.h"

using namespace std;

// Parses command-line inputs and modifies the necessary values
void get_options(int argc, char *argv[], OptWrap &options) {

    int option = 0; // DO NOT CHANGE
    int option_index = 0; // DO NOT CHANGE

    opterr = false; // DO NOT CHANGE!!!

    struct option long_opts[] = { {"help", no_argument, nullptr, 'h'},
                                  {"verbose", no_argument, nullptr, 'v'},
								  {"strat1", required_argument, nullptr, '1'},
							      {"strat2", required_argument, nullptr, '2'},
                                  {nullptr, 0, nullptr, '\0'} };

    while ((option = getopt_long(argc, argv, "v1:2:h",
								 long_opts, &option_index)) != -1) {
        switch (option) {
		case '1':
			options.strat1 = optarg;
			break;
		case '2':
			options.strat2 = optarg;
			break;
		case 'v':
			options.verbose = true;
			break;
        case 'h':
			print_help();
            exit(0);
			break;
		default:
			std::cout << "Invalid flag: " << option << endl;
			exit(0);
			break;
		}
    }

    return;
}