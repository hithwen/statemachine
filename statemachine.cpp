/**
* Class representing a state machine
*
* Each transition consists of an origin state, a destination state and a transition function
* when calling transict, the state machine will look for a state which meets the following
*   - origin is current_state
*   - transition_function returns True
* then state machine will transition to dest
*
* @author hithwen@gmail.com
*/

#include "hithwen/statemachine/statemachine.h"
#include "hithwen/statemachine/transition.h"

StateMachine::StateMachine(int numStates, int numTransitions){
	transitions = new Transition[numTransitions];
	state_functions = new st_fun_t[numStates]();
	stored_transitions = 0;
	currentstate = 0;
}

void StateMachine::add_transition(int origin, int dest, tr_fun_t transition_function) {
	transitions[stored_transitions].origin = origin;
	transitions[stored_transitions].dest = dest;
	transitions[stored_transitions].transition_function = transition_function;
	stored_transitions++;
}

void StateMachine::add_state_function(int state, st_fun_t state_function) {
	state_functions[state] = state_function;
}

//Transit from current state
int StateMachine::loop() {
    int current_state = this->current_state();
    for(int i=0; i < stored_transitions; i++) {
		Transition transition = this->transitions[i];
		if(transition.origin == current_state && transition.transition_function()) {
			this->set_current_state(transition.dest);
            current_state = transition.dest;
			return transition.dest;
		}
	}
    if (state_functions[current_state] != 0) {
		state_functions[current_state]();
	}
	return current_state;
}

//Returns current state
int StateMachine::current_state(void) {
	return this->currentstate;
}

void StateMachine::set_current_state(int current) {
	this->currentstate = current;
}

void StateMachine::reset(void) {
	this->set_current_state(0);
}
