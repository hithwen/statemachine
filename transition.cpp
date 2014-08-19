/**
* Transition container class
* Each transition contains an origin state, a destiny state and the function that decides if the state is changed or not.
* Transition function receives no arguments and returns a boolean
* 
* @author hithwen@gmail.com
*/

#include "hithwen/statemachine/transition.h"

Transition::Transition(int origin, int dest, tr_fun_t transition_function) {
	this->origin = origin;
	this->dest = dest;
	this->transition_function = transition_function;
}
