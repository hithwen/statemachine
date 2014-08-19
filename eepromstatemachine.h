/**
* Class representing a state machine stored in EPROM
*
* Each transition consists of an origin state, a destination state and a transition function
* when calling transict, the state machine will look for a state which meets the following
*   - origin is current_state
*   - transition_function returns True
* then state machine will transition to dest
*
* State is stored in eprom in eeprom_position which defaults to 0, change eeprom position when declaring a
* EEPROMState machine to avoid colliding with other code that uses EEPROM.
* EEPROMStateMachine machine(3, 3);
* machine.eeprom_position = 100;
* machine.reset();
*
* Flash your sketch with machine.reset() in the setup to clear that memory position in first run.
* Then reflash it removing that line or the machine will reset each time you restart your arduino;
*
* @author hithwen@gmail.com
*/
#include "hithwen/statemachine/statemachine.h"

#ifndef HITH_EPROMSTATEMACHINE
#define HITH_EPROMSTATEMACHINE

class EEPROMStateMachine: public StateMachine {
	public:
		EEPROMStateMachine(int numStates, int numTransitions):StateMachine(numStates, numTransitions){}
		int eeprom_position; // Change it if you're using the eprom for other reasons
		virtual int current_state(void);
    protected:
		virtual void set_current_state(int current);
};

#endif
