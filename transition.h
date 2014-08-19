/**
* Transition container class
* Each transition contains an origin state, a destiny state and the function that decides if the state is changed or not.
* Transition function receives no arguments and returns a boolean
* 
* @author hithwen@gmail.com
*/

#ifndef HITH_TRANSITION
#define HITH_TRANSITION

typedef bool (*tr_fun_t)( void );

class Transition {
	public:
		Transition(){};
		Transition(int origin, int dest, tr_fun_t transition_function);
		int origin, dest;
		tr_fun_t transition_function;
};

#endif
