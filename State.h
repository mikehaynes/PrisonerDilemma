/* Contains a class that contains a class to handle a single
 * state of a stratagem
 *
 * Michael Haynes
 * mjhaynes
 *
 * State.h
 */

#ifndef STATE_H
#define STATE_H

enum Action { COOPERATE, DEFECT };

class State {
public:
	State() {
		action = DEFECT;
		if_comply = 0;
		if_dissent = 0;
	}

	State(const Action act, const int comply, const int dissent) {
		action = act;
		if_comply = comply;
		if_dissent = dissent;
	}

	Action action;
	int if_comply;
	int if_dissent;
};

#endif
