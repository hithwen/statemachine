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

#include <EEPROM.h>
#include "hithwen/statemachine/eepromstatemachine.h"

//Returns current state
int EEPROMStateMachine::current_state(void) {
	this->currentstate = EEPROM.read(this->eeprom_position);
	return this->currentstate;
}

void EEPROMStateMachine::set_current_state(int current) {
	EEPROM.write(this->eeprom_position, current);
	this->currentstate = current;
}
