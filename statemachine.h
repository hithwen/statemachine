/**
* Class representing a state machine, this can be used in non arduino programs.
*
* Each transition consists of an origin state, a destination state and a transition function
* when calling transict, the state machine will look for a state which meets the following
*   - origin is current_state
*   - transition_function returns True
* then state machine will transition to dest
*
* @author hithwen@gmail.com
*/

#include "hithwen/statemachine/transition.h"

#ifndef HITH_STATEMACHINE
#define HITH_STATEMACHINE

typedef void (*st_fun_t)( void );

class StateMachine {
	public:
		StateMachine(int numStates, int numTransitions);
		void add_transition(int origin, int dest, tr_fun_t transition_function);
		void add_state_function(int state, st_fun_t state_function);
		int loop();
		void reset(void);
		virtual int current_state(void);
	protected:
		int currentstate;
		virtual void set_current_state(int current);
	private:
		Transition *transitions;
		int stored_transitions;
		st_fun_t *state_functions;
};

#endif
